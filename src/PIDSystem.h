/*
 * PIDSystem.h
 *
 *  Created on: 2018��7��6��
 *      Author: CF-PC
 */

#ifndef SRC_PIDSYSTEM_H_
#define SRC_PIDSYSTEM_H_

#include <math.h>

class PID{
public:
	double PIDFeedback(double P, double I, double D, double Plan, double Actual);
};




#endif /* SRC_PIDSYSTEM_H_ */
