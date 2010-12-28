/* 
 * File:   capturer.hpp
 * Author: Alex Judge
 *
 * Created on 21 Декабрь 2010 г., 17:50
 */

#pragma once
#include "highgui.h"
#include "detector.hpp"

class CCapturer {
private:
    CvCapture *capture; // camera device
    CFacesDetector *detector;
    void log(const char *message);
public:
    CCapturer(CFacesDetector *detector);
    ~CCapturer();
    void next(void);
};
