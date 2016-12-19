// ** C2Rqamass Class ** //
// Autogenerated in QDP Commands ** //
// Manzano Software //

#ifndef _MZN_CMD_C2_RQAMASS_H
#define _MZN_CMD_C2_RQAMASS_H

#include "command.h"

namespace mzn {
class C2Rqamass : public Command {

friend std::ostream & operator<<(std::ostream & cmd_os, C2Rqamass const & cmd);

public:

    explicit C2Rqamass();
    ~C2Rqamass() = default;

    C2Rqamass(C2Rqamass && rhs) = default;
    C2Rqamass & operator=(C2Rqamass && rhs) = default;
    C2Rqamass(C2Rqamass const & rhs) = default;
    C2Rqamass & operator=(C2Rqamass const & rhs) = default;
    std::string const cmd_name = "c2_rqamass";


    uint16_t msg_to_data(std::vector<uint8_t> const & msg,
                         uint16_t mf_begin) override;

    uint16_t data_to_msg(std::vector<uint8_t> & msg,
                         uint16_t mf_begin) const override;

private:

    std::ostream & os_print(std::ostream & cmd_os) const override;
};


inline std::ostream & operator<<(std::ostream & cmd_os, C2Rqamass const & cmd) {
    return cmd.os_print(cmd_os);
}

} // end namespace
#endif // _MZN_CMD_C2_RQAMASS_H
