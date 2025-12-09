#include "HwRev.hpp"

HwRev::~HwRev() = default;

LedColor HwRev::checkThresholds(uint16_t adc_raw) const {
    int32_t val = static_cast<int32_t>(adc_raw);
    
    if (val >= critical_high_threshold_ || val < critical_low_threshold_)
        return RED;
    if (val >= warning_threshold_)
        return YELLOW;
    return GREEN;
}
