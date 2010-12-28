/* 
 * File:   CImageController.hpp
 * Author: Judge
 *
 * Created on 27 Декабрь 2010 г., 0:49
 */

#pragma once

#include <stdio.h>

#include "cxcore.h"

class CImageController {
private:
    void log(const char *message);
public:
    CImageController();
    ~CImageController();
    void image(IplImage *image);
    void face(IplImage *face);
};
