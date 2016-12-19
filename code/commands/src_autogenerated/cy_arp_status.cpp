#include "cy_arp_status.h"

namespace mzn {
CyArpStatus::CyArpStatus():
    Command(0, 12),
    ip_address(),
    mac_address(),
    timeout() { }

uint16_t CyArpStatus::msg_to_data(std::vector<uint8_t> const & msg,
                                  uint16_t mf_begin) {

    if ( msg.size()  < cmd_data_size_ + mf_begin) {
        throw FatalException(
            "CyArpStatus",
            "msg_to_data",
            "msg size " + std::to_string( msg.size() )
            + ", mf_begin " + std::to_string(mf_begin)
            + ", cmd_data_size_ " + std::to_string(cmd_data_size_)
        );
    }

    mf_begin = ip_address.msg_to_data(msg, mf_begin);
    mf_begin = mac_address.msg_to_data(msg, mf_begin);
    mf_begin = timeout.msg_to_data(msg, mf_begin);

    return mf_begin;
}

uint16_t CyArpStatus::data_to_msg(std::vector<uint8_t> & msg,
                                  uint16_t mf_begin) const {

    if ( msg.size()  < cmd_data_size_ + mf_begin) {
        throw FatalException(
            "CyArpStatus",
            "msg_to_data",
            "msg size: " + std::to_string( msg.size() )
            + ", mf_begin " + std::to_string(mf_begin)
            + ", cmd_data_size_ " + std::to_string(cmd_data_size_)
        );
    }

    mf_begin = ip_address.data_to_msg(msg, mf_begin);
    mf_begin = mac_address.data_to_msg(msg, mf_begin);
    mf_begin = timeout.data_to_msg(msg, mf_begin);

    return mf_begin;
}

std::ostream & CyArpStatus::os_print(std::ostream & cmd_os) const {
    cmd_os << "\n --- CY_ARP_STATUS ---  \n";

    cmd_os << "\nip_address: "; cmd_os << ip_address;

    cmd_os << "\nmac_address: "; cmd_os << mac_address;

    cmd_os << "\ntimeout: "; cmd_os << timeout;
    cmd_os << std::endl;

    return cmd_os;
}

} // end namespace