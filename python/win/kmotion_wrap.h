/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.7
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_kmotion_WRAP_H_
#define SWIG_kmotion_WRAP_H_

#include <map>
#include <string>


class SwigDirector_KMotion : public KMotion, public Swig::Director {

public:
    SwigDirector_KMotion(PyObject *self, int boardid);
    virtual ~SwigDirector_KMotion();
    virtual void Console(char const *buf);
    virtual void ErrMsg(char const *buf);
    virtual void ChangedADC(intvec const &ADCVec);
    virtual void ChangedDAC(intvec const &DACVec);
    virtual void ChangedPWM(intvec const &PWMVec);
    virtual void ChangedPos(floatvec const &PositionVec);
    virtual void ChangedDest(floatvec const &DestVec);
    virtual void ChangedOutChan(intvec const &OutputChanVec);
    virtual void ChangedMode(int InputModes, int InputModes2, int OutputModes, int OutputModes2);
    virtual void ChangedEnable(int Enables);
    virtual void ChangedDone(int AxisDone);
    virtual void ChangedIO(boolvec const &OutDirVec, boolvec const &StateVec);
    virtual void ChangedThread(int ThreadActive);
    virtual void ChangedStop(int StopImmediateState);
    virtual void ChangedPCComm(intvec const &PC_comm);
    virtual void HandleConsole(char const *buf);
    virtual void HandleErrMsg(char const *buf);
    virtual int HandleMsgBox(char const *title, char const *msg, int options);

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class KMotion doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[16];
#endif

};


class SwigDirector_GCodeInterpreter : public GCodeInterpreter, public Swig::Director {

public:
    SwigDirector_GCodeInterpreter(PyObject *self, CCoordMotion *CM);
    virtual ~SwigDirector_GCodeInterpreter();
    virtual void ThreadStarted();
    virtual void ThreadFinished();
    virtual void HandleStatus(int line_no, char const *msg);
    virtual void HandleComplete(int status, int lineno, int sequence_number, char const *err);
    virtual int HandleUser(char const *msg);
    virtual int HandleMCode(int mCode);
    virtual void HandleBoolEvt(int evt_code, bool data);
    virtual void HandleIntEvt(int evt_code, int data, int prevdata);
    virtual void HandleFloatEvt(int evt_code, double data, double prevdata);
    virtual int PC_Estop();
    virtual int PC_Halt();
    virtual int PC_Execute();
    virtual int PC_SingleStep();
    virtual int PC_Restart();
    virtual int PC_SetToolLength();
    virtual int PC_GetToolLength();
    virtual int PC_SetFRO();
    virtual int PC_SetSSO();
    virtual int PC_SetFROInc();
    virtual int PC_SetSSOInc();
    virtual int PC_UpdateFixture();
    virtual int PC_UserButton();
    virtual int PC_MCode();
    virtual int PC_GetToolDiam();
    virtual int PC_SetToolDiam();
    virtual int PC_GetToolOffsetX();
    virtual int PC_SetToolOffsetX();
    virtual int PC_GetToolOffsetY();
    virtual int PC_SetToolOffsetY();
    virtual int PC_HaltNextLine();
    virtual int PC_EnableJogKeys();
    virtual int PC_DisableJogKeys();
    virtual int PC_StatusMsg();
    virtual int PC_SlotToIndex();
    virtual int PC_StatusClear();
    virtual int PC_Other();
    virtual int PC_MsgBox();
    virtual void PC_Cancel_MsgBox();
    virtual int PC_Running_MsgBox();
    virtual int PC_MDI();
    virtual void PC_Cancel_MDI();
    virtual int PC_Running_MDI();
    virtual int PC_InputBox();
    virtual void PC_Cancel_InputBox();
    virtual int PC_Running_InputBox();
    virtual int PC_NBMsgBox();
    virtual int PC_NBMDI();
    virtual int PC_NBInputBox();

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class GCodeInterpreter doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[46];
#endif

};


#endif
