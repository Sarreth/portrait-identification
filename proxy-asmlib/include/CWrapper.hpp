/* 
 * File:   CWrapper.hpp
 * Author: Alex Judge
 *
 * Created on 1 Январь 2011 г., 1:59
 */

#pragma once

#include "asmlib/asmfitting.h"

class CWrapper {
private:
    static char *model_name;
	static CWrapper *instance;
    asmfitting fit_asm;
    int n_iteration;
	CWrapper();
public:
	static const int n_points = 68;
	static void setModelname(char *model_name);
	static CWrapper *getInstance();
    asm_shape main_fit(IplImage * image);
};
