// ======================================================================
// \title  HK.hpp
// \author kq9p
// \brief  hpp file for HK component implementation class
// ======================================================================

#ifndef HK_HK_HPP
#define HK_HK_HPP

#include "Components/HK/HKComponentAc.hpp"
#include "Os/File.hpp"
#include "Os/Models/FileStatusEnumAc.hpp"

namespace HK {

  class HK :
    public HKComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct HK object
      HK(
          const char* const compName //!< The component name
      );

      //! Destroy HK object
      ~HK();

    private:

    Fw::On m_telemetryEnabled = Fw::On::ON; //!< Telemetry enabled state (default ON)
    Fw::On m_tasksEnabled = Fw::On::ON; //!< Tasks enabled state (default ON)
    Os::File m_configFileHandle; //!< Configuration file
    Os::FileInterface::Status m_configFileStatus; //!< Status of the file operation

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for run
      //!
      //! Example port: receiving calls from the rate group
      void run_handler(
          FwIndexType portNum, //!< The port number
          U32 context //!< The call order
      ) override;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command LOAD_CONFIG
      //!
      //! Commands
      void LOAD_CONFIG_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          const Fw::CmdStringArg& configFile //!< Name of the configuration file to load
      ) override;

      //! Handler implementation for command ENABLE_TELEMETRY
      void ENABLE_TELEMETRY_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          Fw::On enable //!< Enable or disable telemetry
      ) override;

      //! Handler implementation for command ENABLE_TASKS
      void ENABLE_TASKS_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          Fw::On enable //!< Enable or disable housekeeping tasks
      ) override;

  };

}

#endif
