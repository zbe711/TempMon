#ifndef MON_HPP
#define MON_HPP

#include <cstdint>

enum class LedColor : uint8_t { GREEN = 0, YELLOW = 1, RED = 2 };

class Monitor
{
public:
    Monitor();
    ~Monitor();
    
    void init();
    void setThresholds(int32_t warning, int32_t critical_high, int32_t critical_low);
    LedColor checkThresholds(uint16_t adc_raw) const;
    static void processSample();

private:
    static constexpr int DEFAULT_WARNING = 85;
    static constexpr int DEFAULT_CRITICAL_HIGH = 105;
    static constexpr int DEFAULT_CRITICAL_LOW = 5;
    
    bool initialized_;
    int32_t warning_threshold_;
    int32_t critical_high_threshold_;
    int32_t critical_low_threshold_;
};

#endif
