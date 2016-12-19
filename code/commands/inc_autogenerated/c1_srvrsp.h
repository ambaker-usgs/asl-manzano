// ** C1Srvrsp Class ** //
// Autogenerated in QDP Commands ** //
// Manzano Software //

#ifndef _MZN_CMD_C1_SRVRSP_H
#define _MZN_CMD_C1_SRVRSP_H

#include "command.h"

namespace mzn {
class C1Srvrsp : public Command {

friend std::ostream & operator<<(std::ostream & cmd_os, C1Srvrsp const & cmd);

public:

    explicit C1Srvrsp();
    ~C1Srvrsp() = default;

    C1Srvrsp(C1Srvrsp && rhs) = default;
    C1Srvrsp & operator=(C1Srvrsp && rhs) = default;
    C1Srvrsp(C1Srvrsp const & rhs) = default;
    C1Srvrsp & operator=(C1Srvrsp const & rhs) = default;
    std::string const cmd_name = "c1_srvrsp";

    CmdFieldHex<uint64_t> serial_number;
    CmdFieldHex<uint64_t> challenge_value;
    CmdFieldIp server_ip_address;
    CmdField<uint16_t> server_udp_port;
    CmdFieldHex<uint16_t> registration_number;
    CmdFieldHex<uint64_t> server_random_value;
    CmdFieldArrayUByte<16> md5_result;

    uint16_t msg_to_data(std::vector<uint8_t> const & msg,
                         uint16_t mf_begin) override;

    uint16_t data_to_msg(std::vector<uint8_t> & msg,
                         uint16_t mf_begin) const override;

private:

    std::ostream & os_print(std::ostream & cmd_os) const override;
};


inline std::ostream & operator<<(std::ostream & cmd_os, C1Srvrsp const & cmd) {
    return cmd.os_print(cmd_os);
}

} // end namespace
#endif // _MZN_CMD_C1_SRVRSP_H
