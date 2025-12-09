#include "HwRevB.hpp"

HwRevB::HwRevB() {
    constexpr int TEMP_MIN = -50;
    constexpr int FACTOR = 10;
    int adc_offset = (-TEMP_MIN) * FACTOR;
    
    warning_threshold_       = DEFAULT_WARNING * FACTOR + adc_offset;
    critical_high_threshold_ = DEFAULT_CRITICAL_HIGH * FACTOR + adc_offset;
    critical_low_threshold_  = DEFAULT_CRITICAL_LOW * FACTOR + adc_offset;
}

