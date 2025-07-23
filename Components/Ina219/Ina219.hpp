// ======================================================================
// \title  Ina219.hpp
// \author kq9p
// \brief  hpp file for Ina219 component implementation class
// ======================================================================

#ifndef Ina219_Ina219_HPP
#define Ina219_Ina219_HPP

#include "Components/Ina219/Ina219ComponentAc.hpp"
#include "Drv/LinuxI2cDriver/LinuxI2cDriver.hpp"

namespace Ina219 {

  class Ina219 :
    public Ina219ComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct Ina219 object
      Ina219(
          const char* const compName //!< The component name
      );

      //! Destroy Ina219 object
      ~Ina219();
    
    private:

    

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for inaInput
      //!
      //! Port for reading data from the INA219 sensor
      Drv::I2cStatus inaInput_handler(
          FwIndexType portNum, //!< The port number
          U32 addr, //!< I2C slave device address
          Fw::Buffer& serBuffer //!< Buffer with data to read/write to/from
      ) override;

      //! Handler implementation for run
      //!
      //! Port receiving calls from the rate group
      void run_handler(
          FwIndexType portNum, //!< The port number
          U32 context //!< The call order
      ) override;

  };

}

#endif
