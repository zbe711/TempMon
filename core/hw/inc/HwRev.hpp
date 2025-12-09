#ifndef HWREV_HPP
#define HWREV_HPP

#include <cstdint>

#define HW_SERIAL_NUMBER_SIZE 8U

enum class HwRevision : uint8_t {
    REV_A = 0,
    REV_B = 1
};

struct SerialNumber {
    char data[HW_SERIAL_NUMBER_SIZE];
};

class HwRev {
public:
    virtual ~HwRev();
    
    virtual HwRevision getRevision() const = 0;
    virtual int32_t getMinTemp() const = 0;
    virtual int32_t getMaxTemp() const = 0;
    virtual int32_t getResolutionFactor() const = 0;
    
    const SerialNumber& getSerial() const;

protected:
    HwRev(const SerialNumber& serial);
    
    SerialNumber serial_;
};

#endif
