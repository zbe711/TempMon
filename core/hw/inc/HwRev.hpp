#ifndef HWREV_HPP
#define HWREV_HPP

#include <cstdint>

enum LedColor { GREEN, YELLOW, RED };

class HwRev {
public:
    virtual ~HwRev();
    
    LedColor checkThresholds(uint16_t adc_raw) const;

protected:
    static constexpr int DEFAULT_WARNING = 85;
    static constexpr int DEFAULT_CRITICAL_HIGH = 105;
    static constexpr int DEFAULT_CRITICAL_LOW = 5;
    
    int32_t warning_threshold_;
    int32_t critical_high_threshold_;
    int32_t critical_low_threshold_;
};

#endif
