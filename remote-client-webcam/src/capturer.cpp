#include "capturer.hpp"
#include <stdio.h>

CCapturer::CCapturer(CFacesDetector *detector) {
    this->detector = detector;
}

CCapturer::~CCapturer() {
}

void *CCapturer::run() {
    // Initialize webcamera
    this->capture = cvCaptureFromCAM(CV_CAP_ANY);
    if (!capture) {
        //fprintf(stderr, "Could not initialize capturing.\n");
        printf("Could not initialize capturing.\n");
        return;
    } else {
        printf("Capturing have been initialized.\n");
    }
    while (!stopped) {
        IplImage *frame = cvQueryFrame(this->capture);
        if (!frame) {
            //fprintf(stderr, "Frame could not be captured.\n");
            printf("No frame.\n");
            continue;
        }
        printf("Return frame.\n");
        this->detector->recognize(frame);
    }
}

void CCapturer::start() {
    stopped = false;
    pthread_t thread;
    int id = 1;
    int result = pthread_create(thread, NULL, run, &id);
    if (result != 0) {
        perror("Creating the first thread");
    }
}

void CCapturer::stop() {
    this->stopped = true;
    cvReleaseCapture(&this->capture);
}
