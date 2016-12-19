// ** CxAuxiliaryBoardStatus Class ** //
// Autogenerated in QDP Commands ** //
// Manzano Software //

#ifndef _MZN_CMD_CX_AUXILIARY_BOARD_STATUS_H
#define _MZN_CMD_CX_AUXILIARY_BOARD_STATUS_H

#include "command.h"


#include "cy_auxiliary_board_status.h"

#define k_cy_auxiliary_board_status 0

#include "multi_command.h"
namespace mzn {

class CxAuxiliaryBoardStatus : public MultiCommand {

friend std::ostream & operator<<(std::ostream & cmd_os, CxAuxiliaryBoardStatus const & cmd);

public:

    explicit CxAuxiliaryBoardStatus();
    ~CxAuxiliaryBoardStatus() = default;

    CxAuxiliaryBoardStatus(CxAuxiliaryBoardStatus && rhs) = default;
    CxAuxiliaryBoardStatus & operator=(CxAuxiliaryBoardStatus && rhs) = default;
    std::string const cmd_name = "cx_auxiliary_board_status";

    CmdField<uint16_t> size_of_this_block;
    CmdField<uint16_t> packet_version;
    CmdField<uint16_t> aux_type;
    CmdField<uint16_t> aux_version;

    uint16_t msg_to_data(std::vector<uint8_t> const & msg,
                         uint16_t mf_begin) override;

    uint16_t data_to_msg(std::vector<uint8_t> & msg,
                         uint16_t mf_begin) const override;
    // max keys implementation in a separate function/file
    // not part of auto generation
    int number_of_ic(std::size_t const msg_size) const override;
    void create_new_ic(uint8_t const  cmd_key) override;

private:

    std::ostream & os_print(std::ostream & cmd_os) const override;
};


inline std::ostream & operator<<(std::ostream & cmd_os, CxAuxiliaryBoardStatus const & cmd) {
    return cmd.os_print(cmd_os);
}

} // end namespace
#endif // _MZN_CMD_CX_AUXILIARY_BOARD_STATUS_H