#ifndef HWREVA_HPP
#define HWREVA_HPP

#include "HwRev.hpp"

class HwRevA : public HwRev {
public:
    HwRevA(const SerialNumber& serial);
    HwRevision getRevision() const override;
    int32_t getMinTemp() const override;
    int32_t getMaxTemp() const override;
    int32_t getResolutionFactor() const override;
};

#endif

