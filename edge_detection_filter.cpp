#include "edge_detection_filter.h"

EdgeDetectionFilter::~EdgeDetectionFilter() {
    for (size_t i = 0; i < 3; i++) {
        delete[] filter_[i];
    }
    delete[] filter_;
}

int** EdgeDetectionFilter::CreateFilter() {
    filter_ = new int*[3];
    for (size_t i = 0; i < 3; i++) {
        filter_[i] = new int[3];
    }

    filter_[0][0] = 0;
    filter_[0][1] = SIDES_EDGE_DETECTION;
    filter_[0][2] = 0;
    filter_[1][0] = SIDES_EDGE_DETECTION;
    filter_[1][1] = CENTER_EDGE_DETECTION;
    filter_[1][2] = SIDES_EDGE_DETECTION;
    filter_[2][0] = 0;
    filter_[2][1] = SIDES_EDGE_DETECTION;
    filter_[2][2] = 0;

    return filter_;
}

EdgeDetectionFilter::EdgeDetectionFilter(uint8_t threshold) : MatrixFilter(CreateFilter()), threshold_(threshold) {
}

void EdgeDetectionFilter::Process(Image& image) {
    GrayscaleFilter::Process(image);
    MatrixFilter::Process(image);

    for (size_t x = 0; x < image.Height(); x++) {
        for (size_t y = 0; y < image.Width(); y++) {
            if (image.pixels[x][y].red > threshold_) {
                image.pixels[x][y].red = UINT8_MAX;
                image.pixels[x][y].green = UINT8_MAX;
                image.pixels[x][y].blue = UINT8_MAX;
            } else {
                image.pixels[x][y].red = 0;
                image.pixels[x][y].green = 0;
                image.pixels[x][y].blue = 0;
            }
        }
    }
}
