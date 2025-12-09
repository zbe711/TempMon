#include "HwRev.hpp"

HwRev::HwRev(const SerialNumber& serial) : serial_(serial) {}

HwRev::~HwRev() = default;

const SerialNumber& HwRev::getSerial() const {
    return serial_;
}
