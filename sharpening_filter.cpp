#include "sharpening_filter.h"

SharpeningFilter::~SharpeningFilter() {
    for (int i = 0; i < 3; i++) {
        delete[] filter_[i];
    }
    delete[] filter_;
}

int** SharpeningFilter::CreateFilter() {
    filter_ = new int*[3];
    for (int i = 0; i < 3; i++) {
        filter_[i] = new int[3];
    }

    filter_[0][0] = 0;
    filter_[0][1] = SIDES_SHARPENING;
    filter_[0][2] = 0;
    filter_[1][0] = SIDES_SHARPENING;
    filter_[1][1] = CENTER_SHARPENING;
    filter_[1][2] = SIDES_SHARPENING;
    filter_[2][0] = 0;
    filter_[2][1] = SIDES_SHARPENING;
    filter_[2][2] = 0;

    return filter_;
}

SharpeningFilter::SharpeningFilter() : MatrixFilter(CreateFilter()) {
}

void SharpeningFilter::Process(Image& image) {
    MatrixFilter::Process(image);
}