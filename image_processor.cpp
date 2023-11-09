#include "file_worker.h"
#include "image.h"
#include "image_handler.h"
#include "interesting_filter.h"
#include <iostream>

int main(int argc, char** argv) {

    try {
        ImageHandler image_handler;

        image_handler.HandleInput(argc, argv);
        image_handler.StartProcess();
        image_handler.SaveImage();
    } catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
