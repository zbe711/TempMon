#include "HwRevA.hpp"

HwRevA::HwRevA() {
    constexpr int TEMP_MIN = -40;
    int adc_offset = -TEMP_MIN;
    
    warning_threshold_       = DEFAULT_WARNING + adc_offset;
    critical_high_threshold_ = DEFAULT_CRITICAL_HIGH + adc_offset;
    critical_low_threshold_  = DEFAULT_CRITICAL_LOW + adc_offset;
}

