// ** CxDynamicIp Class ** //
// Autogenerated in QDP Commands ** //
// Manzano Software //

#ifndef _MZN_CMD_CX_DYNAMIC_IP_H
#define _MZN_CMD_CX_DYNAMIC_IP_H

#include "command.h"

namespace mzn {
class CxDynamicIp : public Command {

friend std::ostream & operator<<(std::ostream & cmd_os, CxDynamicIp const & cmd);

public:

    explicit CxDynamicIp();
    ~CxDynamicIp() = default;

    CxDynamicIp(CxDynamicIp && rhs) = default;
    CxDynamicIp & operator=(CxDynamicIp && rhs) = default;
    CxDynamicIp(CxDynamicIp const & rhs) = default;
    CxDynamicIp & operator=(CxDynamicIp const & rhs) = default;
    std::string const cmd_name = "cx_dynamic_ip";

    CmdFieldIp serial_1_ip_address;
    CmdFieldIp serial_2_ip_address;
    CmdFieldIgnore<uint32_t> reserved;
    CmdFieldIp ethernet_ip_address;

    uint16_t msg_to_data(std::vector<uint8_t> const & msg,
                         uint16_t mf_begin) override;

    uint16_t data_to_msg(std::vector<uint8_t> & msg,
                         uint16_t mf_begin) const override;

private:

    std::ostream & os_print(std::ostream & cmd_os) const override;
};


inline std::ostream & operator<<(std::ostream & cmd_os, CxDynamicIp const & cmd) {
    return cmd.os_print(cmd_os);
}

} // end namespace
#endif // _MZN_CMD_CX_DYNAMIC_IP_H
