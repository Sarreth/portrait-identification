/* 
 * File:   CImageController.cpp
 * Author: Judge
 * 
 * Created on 27 Декабрь 2010 г., 0:49
 */

#include "CImageController.hpp"

CImageController::CImageController() {
}

CImageController::~CImageController() {
}

void CImageController::log(const char* message) {
    puts(message);
}

void CImageController::image(IplImage *image) {
    this->log("\nIt's an image");
    cvReleaseImage(&image);
};

void CImageController::face(IplImage *face) {
    this->log("\nIt's a face");
    cvReleaseImage(&face);
};
