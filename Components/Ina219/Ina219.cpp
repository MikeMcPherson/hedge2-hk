// ======================================================================
// \title  Ina219.cpp
// \author kq9p
// \brief  cpp file for Ina219 component implementation class
// ======================================================================

#include "Components/Ina219/Ina219.hpp"

namespace Ina219 {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  Ina219 ::
    Ina219(const char* const compName) :
      Ina219ComponentBase(compName)
  {

  }

  Ina219 ::
    ~Ina219()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for typed input ports
  // ----------------------------------------------------------------------

  Drv::I2cStatus Ina219 ::
    inaInput_handler(
        FwIndexType portNum,
        U32 addr,
        Fw::Buffer& serBuffer
    )
  {
    // TODO
    return Drv::I2cStatus::I2C_OK;
  }

  void Ina219 ::
    run_handler(
        FwIndexType portNum,
        U32 context
    )
  {
    // TODO
  }

}
