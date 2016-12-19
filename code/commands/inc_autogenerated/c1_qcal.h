// ** C1Qcal Class ** //
// Autogenerated in QDP Commands ** //
// Manzano Software //

#ifndef _MZN_CMD_C1_QCAL_H
#define _MZN_CMD_C1_QCAL_H

#include "command.h"

namespace mzn {
class C1Qcal : public Command {

friend std::ostream & operator<<(std::ostream & cmd_os, C1Qcal const & cmd);

public:

    explicit C1Qcal();
    ~C1Qcal() = default;

    C1Qcal(C1Qcal && rhs) = default;
    C1Qcal & operator=(C1Qcal && rhs) = default;
    C1Qcal(C1Qcal const & rhs) = default;
    C1Qcal & operator=(C1Qcal const & rhs) = default;
    std::string const cmd_name = "c1_qcal";

    CmdField<uint32_t> starting_time;
    BmCalWaveform waveform;
    CmdFieldCalAmplitude amplitude;
    CmdFieldDuration<uint16_t> cal_duration;
    CmdFieldDuration<uint16_t> settling_time;
    BmCalibrationBitmap calibration_bitmap;
    CmdFieldDuration<uint16_t> trailer_time;
    BmCalSensorControlBitmap sensor_control_bitmap;
    BmCalMonitorChannel monitor_channel_bitmap;
    CmdField<uint16_t> frequency_divider;
    CmdFieldIgnore<uint16_t> spare_0;
    CmdFieldArrayChar<12> coupling_bytes;

    uint16_t msg_to_data(std::vector<uint8_t> const & msg,
                         uint16_t mf_begin) override;

    uint16_t data_to_msg(std::vector<uint8_t> & msg,
                         uint16_t mf_begin) const override;

private:

    std::ostream & os_print(std::ostream & cmd_os) const override;
};


inline std::ostream & operator<<(std::ostream & cmd_os, C1Qcal const & cmd) {
    return cmd.os_print(cmd_os);
}

} // end namespace
#endif // _MZN_CMD_C1_QCAL_H