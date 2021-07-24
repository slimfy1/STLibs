int SysClockFreq;

#include "pwm.h"

int FRQ_CALCULATOR(int frequency)
{
	//SysClockFreq = SystemCoreClockUpdate();
	int calFreq = SYSCLOCK/((TIM1->PSC+1)*frequency);

	return calFreq;
}

int DUTY_CALCULATE(uint16_t duty_percentage)
{
	uint16_t arr_value = TIM1->ARR;
	uint16_t arr_duty_value = arr_value*(duty_percentage*0.01);

	return arr_duty_value;
}
void TIM_EN()
{
	TIM1->CCMR1=TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE;
	TIM1->CCER=TIM_CCER_CC1E | TIM_CCER_CC2E;
	TIM1->BDTR=TIM_BDTR_MOE;
	//TIM1->CCR1=TMR_T - PWM_VALUE;
	//TIM1->CCR2=PWM_VALUE;
	TIM1->ARR=TMR_T;
	TIM1->CR1=TIM_CR1_ARPE | TIM_CR1_CMS_1 | TIM_CR1_CMS_0;
	TIM1->CR1|=TIM_CR1_CEN;
	TIM1->EGR=TIM_EGR_UG;
}

void SET_PWM(int pwm)
{
	TIM1->CCR1=TMR_T - pwm;
	TIM1->CCR2=pwm;
}

void SET_FRQ(int frq, int pwm)
{
	//CLEAR_BIT(TIM1->CCER, TIM_CCER_CC1E | TIM_CCER_CC2E);
	int frqVal = FRQ_CALCULATOR(frq);
	int pwmVal = frqVal*pwm*0.01;
	TIM1->CCR1=frqVal - pwmVal;
	TIM1->CCR2=pwmVal;
	TIM1->ARR=frqVal;
	//TIM1->CCER=TIM_CCER_CC1E | TIM_CCER_CC2E;
}
