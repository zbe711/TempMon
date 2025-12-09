#include "HwRevA.hpp"

#define HW_REV_A_MIN_TEMP -40
#define HW_REV_A_MAX_TEMP 140
#define HW_REV_A_RESOLUTION_FACTOR 1

HwRevA::HwRevA(const SerialNumber& serial) : HwRev(serial) {}

HwRevision HwRevA::getRevision() const {
    return HwRevision::REV_A;
}

int32_t HwRevA::getMinTemp() const {
    return HW_REV_A_MIN_TEMP;
}

int32_t HwRevA::getMaxTemp() const {
    return HW_REV_A_MAX_TEMP;
}

int32_t HwRevA::getResolutionFactor() const {
    return HW_REV_A_RESOLUTION_FACTOR;
}

