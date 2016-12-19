// ** CyAuxiliaryBoardStatus Class ** //
// Autogenerated in QDP Commands ** //
// Manzano Software //

#ifndef _MZN_CMD_CY_AUXILIARY_BOARD_STATUS_H
#define _MZN_CMD_CY_AUXILIARY_BOARD_STATUS_H

#include "command.h"

namespace mzn {
class CyAuxiliaryBoardStatus : public Command {

friend std::ostream & operator<<(std::ostream & cmd_os, CyAuxiliaryBoardStatus const & cmd);

public:

    explicit CyAuxiliaryBoardStatus();
    ~CyAuxiliaryBoardStatus() = default;

    CyAuxiliaryBoardStatus(CyAuxiliaryBoardStatus && rhs) = default;
    CyAuxiliaryBoardStatus & operator=(CyAuxiliaryBoardStatus && rhs) = default;
    CyAuxiliaryBoardStatus(CyAuxiliaryBoardStatus const & rhs) = default;
    CyAuxiliaryBoardStatus & operator=(CyAuxiliaryBoardStatus const & rhs) = default;
    std::string const cmd_name = "cy_auxiliary_board_status";

    CmdField<int32_t> conversion;

    uint16_t msg_to_data(std::vector<uint8_t> const & msg,
                         uint16_t mf_begin) override;

    uint16_t data_to_msg(std::vector<uint8_t> & msg,
                         uint16_t mf_begin) const override;

private:

    std::ostream & os_print(std::ostream & cmd_os) const override;
};


inline std::ostream & operator<<(std::ostream & cmd_os, CyAuxiliaryBoardStatus const & cmd) {
    return cmd.os_print(cmd_os);
}

} // end namespace
#endif // _MZN_CMD_CY_AUXILIARY_BOARD_STATUS_H