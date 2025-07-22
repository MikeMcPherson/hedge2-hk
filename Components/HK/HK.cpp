// ======================================================================
// \title  HK.cpp
// \author kq9p
// \brief  cpp file for HK component implementation class
// ======================================================================

#include "Components/HK/HK.hpp"

namespace HK {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  HK ::
    HK(const char* const compName) :
      HKComponentBase(compName)
  {

  }

  HK ::
    ~HK()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for typed input ports
  // ----------------------------------------------------------------------

  void HK ::
    run_handler(
        FwIndexType portNum,
        U32 context
    )
  {
    // TODO
  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void HK ::
    LOAD_CONFIG_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        const Fw::CmdStringArg& configFile
    )
  {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
