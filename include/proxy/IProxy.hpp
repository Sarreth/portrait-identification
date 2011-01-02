/* 
* File:   IProxy.hpp
* Author: Alex Judge
*
* Created on 31 Декабрь 2010 г., 19:21
*/

#pragma once

#include "cxtypes.h"

#ifdef WIN32
#define PROXY __declspec(dllexport)
#else
#define PROXY
#endif


extern "C" PROXY CvPoint *findPoints(IplImage *face);

