#include "stdafx.h"

#include "CWrapper.hpp"

CWrapper	*CWrapper::instance		= NULL;
char		*CWrapper::model_name	= NULL;

CWrapper *CWrapper::getInstance(){
	if(CWrapper::instance == NULL){
		try{
			CWrapper::instance = new CWrapper();
		}
		catch (char *mes){
			printf(mes);
		}		
	}
	return CWrapper::instance;
}

void CWrapper::setModelname(char *model_name){
	CWrapper::model_name = model_name;
}

CWrapper::CWrapper() {
	n_iteration = 50;
	if(!fit_asm.Read(CWrapper::model_name)){
		throw "Fail to load model\n";
	}
}

asm_shape CWrapper::main_fit(IplImage * image) {
	asm_shape retval, detshape;

	double t = (double) cvGetTickCount();

	detshape.Resize(2);

	detshape[0] = cvPointTo32f(cvPoint(0, 0));
	detshape[1] = cvPointTo32f(cvPoint(image->width, image->height));

	InitShapeFromDetBox(retval, detshape, fit_asm.GetMappingDetShape(),
		fit_asm.GetMeanFaceWidth());

	fit_asm.Fitting(retval, image);

	t = ((double) cvGetTickCount() - t) / (cvGetTickFrequency()*1000.);
	printf("ASM fitting time cost: %.2f millisec\n", t);

	return retval;
}
