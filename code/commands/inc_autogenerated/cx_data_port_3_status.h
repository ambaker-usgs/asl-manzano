// ** CxDataPort3Status Class ** //
// Autogenerated in QDP Commands ** //
// Manzano Software //

#ifndef _MZN_CMD_CX_DATA_PORT_3_STATUS_H
#define _MZN_CMD_CX_DATA_PORT_3_STATUS_H

#include "command.h"

namespace mzn {
class CxDataPort3Status : public Command {

friend std::ostream & operator<<(std::ostream & cmd_os, CxDataPort3Status const & cmd);

public:

    explicit CxDataPort3Status();
    ~CxDataPort3Status() = default;

    CxDataPort3Status(CxDataPort3Status && rhs) = default;
    CxDataPort3Status & operator=(CxDataPort3Status && rhs) = default;
    CxDataPort3Status(CxDataPort3Status const & rhs) = default;
    CxDataPort3Status & operator=(CxDataPort3Status const & rhs) = default;
    std::string const cmd_name = "cx_data_port_3_status";

    CmdField<uint32_t> total_data_packets_sent;
    CmdField<uint32_t> total_packets_resent;
    CmdField<uint32_t> total_fill_packets_sent;
    CmdField<uint32_t> receive_sequence_errors;
    CmdField<uint32_t> bytes_of_packet_currently_used;
    CmdField<uint16_t> physical_interface_number;
    CmdField<uint16_t> data_port_number;
    CmdFieldDuration<uint16_t, std::deci> retransmission_timout;
    BmFgDataport dataport_flags;

    uint16_t msg_to_data(std::vector<uint8_t> const & msg,
                         uint16_t mf_begin) override;

    uint16_t data_to_msg(std::vector<uint8_t> & msg,
                         uint16_t mf_begin) const override;

private:

    std::ostream & os_print(std::ostream & cmd_os) const override;
};


inline std::ostream & operator<<(std::ostream & cmd_os, CxDataPort3Status const & cmd) {
    return cmd.os_print(cmd_os);
}

} // end namespace
#endif // _MZN_CMD_CX_DATA_PORT_3_STATUS_H
