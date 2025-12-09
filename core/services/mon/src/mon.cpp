#include "mon.hpp"

Monitor::Monitor() : initialized_(false),
                     warning_threshold_(0),
                     critical_high_threshold_(0),
                     critical_low_threshold_(0)
{
}

Monitor::~Monitor()
{
}

void Monitor::init()
{
    initialized_ = true;
}

void Monitor::setThresholds(int32_t warning, int32_t critical_high, int32_t critical_low)
{
    warning_threshold_ = warning;
    critical_high_threshold_ = critical_high;
    critical_low_threshold_ = critical_low;
}

LedColor Monitor::checkThresholds(uint16_t adc_raw) const
{
    int32_t val = static_cast<int32_t>(adc_raw);
    
    if (val >= critical_high_threshold_ || val < critical_low_threshold_)
        return LedColor::RED;
    if (val >= warning_threshold_)
        return LedColor::YELLOW;
    return LedColor::GREEN;
}

void Monitor::processSample()
{
}
