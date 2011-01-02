// proxy_asmlib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "cv.h"
#include "cxcore.h"
#include "highgui.h"

#include "IProxy.hpp"
#include "CWrapper.hpp"

CvPoint *findPoints(IplImage *face) {
	char *model_name = "resources/my.amf";
	
	double t = (double) cvGetTickCount();

	CWrapper::setModelname(model_name);
	CWrapper *wrapper = CWrapper::getInstance();

	t = ((double) cvGetTickCount() - t) / (cvGetTickFrequency()*1000.);
	printf("Model load time cost: %.2f millisec\n", t);

	t = (double) cvGetTickCount();

	asm_shape shape = wrapper->main_fit(face);

	t = ((double) cvGetTickCount() - t) / (cvGetTickFrequency()*1000.);
	printf("Fitting time cost: %.2f millisec\n", t);

	t = (double) cvGetTickCount();

	int n_points = 68;
	CvPoint *retval = new CvPoint[n_points];
	for (int i = 0; i < n_points; i++) {
		retval[i] = cvPointFrom32f(shape[i]);
	}

	t = ((double) cvGetTickCount() - t) / (cvGetTickFrequency()*1000.);
	printf("Convert points time cost: %.2f millisec\n", t);

	return retval;
}

