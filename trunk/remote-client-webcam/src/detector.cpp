#include "detector.hpp"
#include "cxcore.h"
#include "cv.h"

CFacesDetector::CFacesDetector(char* filename, CSender *sender) {
    this->cascade = (CvHaarClassifierCascade*) cvLoad(filename);
    this->storage = cvCreateMemStorage(0);
    this->sender = sender;
}

CFacesDetector::~CFacesDetector() {
    cvReleaseHaarClassifierCascade(&this->cascade);
    cvReleaseMemStorage(&this->storage);
}

void CFacesDetector::log(const char* message) {
    puts(message);
}

void CFacesDetector::recognize(IplImage* img) {
    if (this->sender->begin()) {
        this->log("Sending image");
        if (this->sender->send_image(img)) {
            CvSeq *faces = cvHaarDetectObjects(
                    img,
                    this->cascade,
                    this->storage,
                    1.1,
                    3,
                    CV_HAAR_DO_CANNY_PRUNING);

            for (int i = 0; i < (faces ? faces->total : 0); i++) {
                IplImage *face = cvCreateImage(cvSize(img->width, img->height),
                        img->depth, img->nChannels);
                cvResize(img, face);
                this->log("Sending face image");
                this->sender->send_face(face);
                cvReleaseImage(&face);
            }
        }
        this->sender->finish();
    }
}
