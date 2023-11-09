#pragma once
#include "abstract_filter.h"
#include "grayscale_filter.h"
#include "matrix_filter.h"

const int CENTER_EDGE_DETECTION = 4;
const int SIDES_EDGE_DETECTION = -1;

class EdgeDetectionFilter : public GrayscaleFilter, public MatrixFilter {
public:
    explicit EdgeDetectionFilter(uint8_t threshold);
    ~EdgeDetectionFilter() override;
    void Process(Image& image) override;

private:
    uint8_t threshold_;
    int** CreateFilter();
    int** filter_;
};
