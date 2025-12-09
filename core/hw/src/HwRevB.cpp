#include "HwRevB.hpp"

#define HW_REV_B_MIN_TEMP -50
#define HW_REV_B_MAX_TEMP 150
#define HW_REV_B_RESOLUTION_FACTOR 10

HwRevB::HwRevB(const SerialNumber& serial) : HwRev(serial) {}

HwRevision HwRevB::getRevision() const {
    return HwRevision::REV_B;
}

int32_t HwRevB::getMinTemp() const {
    return HW_REV_B_MIN_TEMP;
}

int32_t HwRevB::getMaxTemp() const {
    return HW_REV_B_MAX_TEMP;
}

int32_t HwRevB::getResolutionFactor() const {
    return HW_REV_B_RESOLUTION_FACTOR;
}

