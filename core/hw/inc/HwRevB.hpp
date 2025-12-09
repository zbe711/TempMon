#ifndef HWREVB_HPP
#define HWREVB_HPP

#include "HwRev.hpp"

class HwRevB : public HwRev {
public:
    HwRevB(const SerialNumber& serial);
    HwRevision getRevision() const override;
    int32_t getMinTemp() const override;
    int32_t getMaxTemp() const override;
    int32_t getResolutionFactor() const override;
};

#endif

