#ifndef PWM_H
#define PWM_H

#include "STLib.h"

int FRQ_CALCULATOR(int frequency);

void TIM_EN();

void SET_PWM(int pwm);

void SET_FRQ(int frq, int pwm);

#endif
