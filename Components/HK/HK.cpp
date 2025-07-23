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
    m_configFileHandle = Os::File(); // Create a new file handle
    m_configFileStatus = m_configFileHandle.open(configFile.toChar(), Os::File::OPEN_READ); // Open the file in read mode
    if (m_configFileStatus == Os::FileInterface::Status::OP_OK) {
      this->log_ACTIVITY_HI_configLoaded(configFile); // Log successful load
      m_configFileHandle.close(); // Close the file handle
      this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
      return;
    } else
    {
      this->log_WARNING_HI_configLoadFailed(configFile); // Log failure to load
      this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::EXECUTION_ERROR);
      return;
    }
  }

  void HK ::
    ENABLE_TELEMETRY_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::On enable
    )
  {
    if(enable != m_telemetryEnabled) {
      this->log_ACTIVITY_HI_telemetryState(enable); // Log telemetry state change
      m_telemetryEnabled = enable; // Update telemetry state
    }
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

  void HK ::
    ENABLE_TASKS_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::On enable
    )
  {
    if(enable != m_tasksEnabled) {
      this->log_ACTIVITY_HI_tasksState(enable); // Log tasks state change
      m_tasksEnabled = enable; // Update tasks state
    }
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
