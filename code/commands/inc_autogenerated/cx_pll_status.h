// ** CxPllStatus Class ** //
// Autogenerated in QDP Commands ** //
// Manzano Software //

#ifndef _MZN_CMD_CX_PLL_STATUS_H
#define _MZN_CMD_CX_PLL_STATUS_H

#include "command.h"

namespace mzn {
class CxPllStatus : public Command {

friend std::ostream & operator<<(std::ostream & cmd_os, CxPllStatus const & cmd);

public:

    explicit CxPllStatus();
    ~CxPllStatus() = default;

    CxPllStatus(CxPllStatus && rhs) = default;
    CxPllStatus & operator=(CxPllStatus && rhs) = default;
    CxPllStatus(CxPllStatus const & rhs) = default;
    CxPllStatus & operator=(CxPllStatus const & rhs) = default;
    std::string const cmd_name = "cx_pll_status";

    CmdField<float> initial_vco;
    CmdField<float> time_error;
    CmdField<float> rms_vco;
    CmdField<float> best_vco;
    CmdFieldIgnore<uint32_t> spare_0;
    CmdField<uint32_t> ticks_since_last_update;
    CmdField<uint16_t> km;
    BmPllState pll_state;

    uint16_t msg_to_data(std::vector<uint8_t> const & msg,
                         uint16_t mf_begin) override;

    uint16_t data_to_msg(std::vector<uint8_t> & msg,
                         uint16_t mf_begin) const override;

private:

    std::ostream & os_print(std::ostream & cmd_os) const override;
};


inline std::ostream & operator<<(std::ostream & cmd_os, CxPllStatus const & cmd) {
    return cmd.os_print(cmd_os);
}

} // end namespace
#endif // _MZN_CMD_CX_PLL_STATUS_H