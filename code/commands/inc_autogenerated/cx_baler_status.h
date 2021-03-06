// ** CxBalerStatus Class ** //
// Autogenerated in main_create_cmds.cpp from cmds_format.json ** //
// Manzano Software //

#ifndef _MZN_CMD_CX_BALER_STATUS_H
#define _MZN_CMD_CX_BALER_STATUS_H

#include "command.h"

namespace mzn {

// -------------------------------------------------------------------------- //
class CxBalerStatus : public Command {

friend std::ostream & operator<<(std::ostream & cmd_os, CxBalerStatus const & cmd);

public:

    explicit CxBalerStatus();
    ~CxBalerStatus() = default;

    CxBalerStatus(CxBalerStatus && rhs) = default;
    CxBalerStatus & operator=(CxBalerStatus && rhs) = default;
    CxBalerStatus(CxBalerStatus const & rhs) = default;
    CxBalerStatus & operator=(CxBalerStatus const & rhs) = default;
    std::string const cmd_name = "cx_baler_status";

    CmdFieldTime<uint32_t, Time::k_shift_seconds_1970_2000> serial_1_last_time;
    CmdField<uint32_t> serial_1_total_number_of_cycles;
    BmBalerstatus serial_1_baler_status_and_timeouts;
    CmdFieldDuration<uint16_t, std::ratio<60> > serial_1_baler_on_off_minutes;
    CmdFieldTime<uint32_t, Time::k_shift_seconds_1970_2000> serial_2_last_time;
    CmdField<uint32_t> serial_2_total_number_of_cycles;
    BmBalerstatus serial_2_baler_status_and_timeouts;
    CmdFieldDuration<uint16_t, std::ratio<60> > serial_2_baler_on_off_minutes;
    CmdFieldTime<uint32_t, Time::k_shift_seconds_1970_2000> special_last_time;
    CmdField<uint32_t> special_total_number_of_cycles;
    BmBalerstatusSpecial special_baler_status_and_timeouts;
    CmdFieldDuration<uint16_t, std::ratio<60> > special_baler_on_off_minutes;
    CmdFieldTime<uint32_t, Time::k_shift_seconds_1970_2000> ethernet_last_time;
    CmdField<uint32_t> ethernet_total_number_of_cycles;
    BmBalerstatus ethernet_baler_status_and_timeouts;
    CmdFieldDuration<uint16_t, std::ratio<60> > ethernet_baler_on_off_minutes;

    uint16_t msg_to_data(std::vector<uint8_t> const & msg,
                         uint16_t mf_begin) override;

    uint16_t data_to_msg(std::vector<uint8_t> & msg,
                         uint16_t mf_begin) const override;

private:

    std::ostream & os_print(std::ostream & cmd_os) const override;
};


inline std::ostream & operator<<(std::ostream & cmd_os, CxBalerStatus const & cmd) {
    return cmd.os_print(cmd_os);
}

} // end namespace
#endif // _MZN_CMD_CX_BALER_STATUS_H
