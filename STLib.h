#ifndef STLIB_H
#define STLIB_H

#define    DWT_CYCCNT    *(volatile unsigned long *)0xE0001004
#define    DWT_CONTROL   *(volatile unsigned long *)0xE0001000
#define    SCB_DEMCR     *(volatile unsigned long *)0xE000EDFC


void DWT_Init(void);

static __inline uint32_t delta(uint32_t t0, uint32_t t1);

void delay_us(uint32_t us);

void delay_ms(uint32_t ms);

int FRQ_CALCULATOR(int frequency);

void TIM_EN();

void SET_PWM(int pwm);

void SET_FRQ(int frq, int pwm);

#endif
