// ======================================================================
// \title  Hk.cpp
// \author kq9p
// \brief  cpp file for Hk component implementation class
// ======================================================================

#include "Components/Hk/Hk.hpp"

namespace Hk {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  Hk ::
    Hk(const char* const compName) :
      HkComponentBase(compName)
  {

  }

  Hk ::
    ~Hk()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void Hk ::
    TODO_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
