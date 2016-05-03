/*
 * utils.cpp
 *
 *  Created on: 22 maj 2015
 *      Author: parhansson
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */
#include <unistd.h> // getpagesize
#include "utils.h"
#include "mongoose.h"

#include "dbg.h"

int mmapNamedFile(MappedFile& mmFile, const char * fileName){
  FILE *fp = (FILE *) fopen (fileName, "r+");
  int result = mmapFile(mmFile, fp);
  fclose(fp);
  return result;
}

int mmapFile(MappedFile& mmFile, FILE *fp){

  if (fp == NULL) {
    debug("Failed to open file");
    return -1;
  }

  struct stat st;

  int pagesize, offset, fd;

  fd = fileno(fp);
  fstat(fd, &st);
  mmFile.filesize = st.st_size;


  offset = 0;
  pagesize = getpagesize(); // should use sysconf(_SC_PAGE_SIZE) instead.
  mmFile.mapsize = (mmFile.filesize/pagesize)*pagesize+pagesize; // align memory allocation with pagesize
  //memory map tmp file and parse it.
  mmFile.addr = (char*)mmap((caddr_t)0, mmFile.mapsize, PROT_READ, MAP_PRIVATE, fd, offset);
  return 0;
}


void unmapFile(MappedFile& mmFile){
  munmap(mmFile.addr, mmFile.mapsize);
}


void absolutePath(const char * relativePath, char * actualpath){
  char absolute [256/*PATH_MAX*/];
  
  if(relativePath[0]=='/'){
    sprintf(absolute, "%s",relativePath);
  } else {
    const char * rootDir = mg_get_option(server, "document_root");
    sprintf(absolute, "%s/%s",rootDir,relativePath);
  }
  
  
  if(realpath(absolute, actualpath) == NULL){
    printf("Error resolving relative path %s from %s\n", relativePath, absolute);
    sprintf(actualpath, "%s",absolute);
  } 
}
