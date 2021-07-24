#include "Servo.h"

SERVO_HandleTypedef servos;

void servo_init(uint8_t set_servo_tim, uint8_t set_servo_channel,  SERVO_PARAMETERS *servo_params)
{
	switch(set_servo_tim){
		case 1:
			servo_params->servo_timer = TIMER1;
			TIM_EN();
			SET_BIT(TIM1->CCER, TIM_CCER_CC1P);
			TIM1->CCR1 = 0;
			TIM1->CCR2 = 0;
			TIM1->CCR3 = 0;
			TIM1->CCR4 = 0;
			TIM1->ARR = FRQ_CALCULATOR(50);
			break;
		case 2:
			servo_params->servo_timer = TIMER2;
			TIM2->CCR1 = 0;
			TIM2->CCR2 = 0;
			TIM2->CCR3 = 0;
			TIM2->CCR4 = 0;
			TIM2->ARR = FRQ_CALCULATOR(50);
			break;
		case 3:
			servo_params->servo_timer = TIMER3;
			TIM3->CCR1 = 0;
			TIM3->CCR2 = 0;
			TIM3->CCR3 = 0;
			TIM3->CCR4 = 0;
			TIM3->ARR = FRQ_CALCULATOR(50);
			break;
		case 4:
			servo_params->servo_timer = TIMER4;
			TIM4->CCR1 = 0;
			TIM4->CCR2 = 0;
			TIM4->CCR3 = 0;
			TIM4->CCR4 = 0;
			TIM4->ARR = FRQ_CALCULATOR(50);
			break;
		case 5:
			servo_params->servo_timer = TIMER5;
			//TIM5->ARR = FRQ_CALCULATOR(50);
			break;
		case 6:
			servo_params->servo_timer = TIMER6;
			//TIM6->ARR = FRQ_CALCULATOR(50);
			break;
        default:
            break;
	}

	switch(set_servo_channel){
		case 1:
			servo_params->servo_channel = CH1;
			break;
		case 2:
			servo_params->servo_channel = CH2;
			break;
		case 3:
			servo_params->servo_channel = CH3;
			break;
		case 4:
			servo_params->servo_channel = CH4;
			break;
		case 5:
			servo_params->servo_channel = CH5;
			break;
		case 6:
			servo_params->servo_channel = CH6;
			break;
        default:
            break;
	}

}

void servo_set_angle(uint16_t angle, SERVO_PARAMETERS *servo_params)
{
	float one_ms = (TIM1->ARR)/20;
	float angle_ms = angle*(one_ms/180);
	uint16_t request_angle = one_ms+angle_ms;
	if(servo_params->servo_timer == 1)
	{
		switch(servo_params->servo_channel){
			case 1:
				TIM1->CCR1 = request_angle;
				break;
			case 2:
				TIM1->CCR2 = request_angle;
				break;
			case 3:
				TIM1->CCR3 = request_angle;
				break;
			case 4:
				TIM1->CCR4 = request_angle;
				break;
			/*
			case 5:
				TIM1->CCR5 = angle;
				break;
			case 6:
				TIM1->CCR6 = angle;
				break;
				*/
		}
	}

	if(servo_params->servo_timer == 2)
	{
		switch(servo_params->servo_channel){
			case 1:
				TIM2->CCR1 = request_angle;
				break;
			case 2:
				TIM2->CCR2 = request_angle;
				break;
			case 3:
				TIM2->CCR3 = request_angle;
				break;
			case 4:
				TIM2->CCR4 = request_angle;
				break;
			/*
			case 5:
				TIM1->CCR5 = angle;
				break;
			case 6:
				TIM1->CCR6 = angle;
				break;
				*/
		}
	}

	if(servo_params->servo_timer == 3)
	{
		switch(servo_params->servo_channel){
			case 1:
				TIM3->CCR1 = request_angle;
				break;
			case 2:
				TIM3->CCR2 = request_angle;
				break;
			case 3:
				TIM3->CCR3 = request_angle;
				break;
			case 4:
				TIM3->CCR4 = request_angle;
				break;
			/*
			case 5:
				TIM1->CCR5 = angle;
				break;
			case 6:
				TIM1->CCR6 = angle;
				break;
				*/
		}
	}

	if(servo_params->servo_timer == 4)
	{
		switch(servo_params->servo_channel){
			case 1:
				TIM4->CCR1 = request_angle;
				break;
			case 2:
				TIM4->CCR2 = request_angle;
				break;
			case 3:
				TIM4->CCR3 = request_angle;
				break;
			case 4:
				TIM4->CCR4 = request_angle;
				break;
			/*
			case 5:
				TIM1->CCR5 = angle;
				break;
			case 6:
				TIM1->CCR6 = angle;
				break;
				*/
		}
	}

}

void servo_disable_all()
{
	TIM1->CR1 = 0;
	TIM2->CR1 = 0;
	TIM3->CR1 = 0;
	TIM4->CR1 = 0;

}
