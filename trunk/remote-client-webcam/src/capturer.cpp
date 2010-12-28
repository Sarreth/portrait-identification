#include "capturer.hpp"
#include <stdio.h>

CCapturer::CCapturer(CFacesDetector *detector) {
    this->detector = detector;
    // Initialize webcamera
    this->capture = cvCaptureFromCAM(CV_CAP_ANY);
    if (!capture) {
        //fprintf(stderr, "Could not initialize capturing.\n");
        this->log("Could not initialize capturing.\n");
        return;
    } else {
        this->log("Capturing have been initialized.\n");
    }
}

CCapturer::~CCapturer() {
    cvReleaseCapture(&this->capture);
}

void CCapturer::log(const char* message) {
    puts(message);
}

void CCapturer::next(void) {
    IplImage *frame = cvQueryFrame(this->capture);
    if (!frame) {
        //fprintf(stderr, "Frame could not be captured.\n");
        this->log("No frame\n");
        return;
    }
    this->log("Return frame");
    this->detector->recognize(frame);
}
