#pragma once
#include "abstract_filter.h"

class InterestingFilter : public AbstractFilter {
public:
    explicit InterestingFilter(int octaves);
    void Process(Image& image) override;

private:
    int octaves_;
};
