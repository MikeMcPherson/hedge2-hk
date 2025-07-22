// ======================================================================
// \title  Hk.hpp
// \author kq9p
// \brief  hpp file for Hk component implementation class
// ======================================================================

#ifndef Hk_Hk_HPP
#define Hk_Hk_HPP

#include "Components/Hk/HkComponentAc.hpp"

namespace Hk {

  class Hk :
    public HkComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct Hk object
      Hk(
          const char* const compName //!< The component name
      );

      //! Destroy Hk object
      ~Hk();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command TODO
      //!
      //! TODO
      void TODO_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq //!< The command sequence number
      ) override;

  };

}

#endif
