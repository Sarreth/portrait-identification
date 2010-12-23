/* 
 * File:   detector.hpp
 * Author: Alex Judge
 *
 * Created on 21 Декабрь 2010 г., 19:11
 */

#pragma once
#include "cv.h"
#include "sender.hpp"

class CFacesDetector {
private:
    CvHaarClassifierCascade *cascade;
    CvMemStorage *storage;
    CSender *sender;
public:
    void recognize(const IplImage* img);
    CFacesDetector(const char* filename);
    ~CFacesDetector();
};
