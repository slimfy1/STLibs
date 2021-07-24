#ifndef SERVO_H
#define SERVO_H

#include "STLib.h"
#include "stdint.h"

typedef enum
{
    TIMER1 = 1,
    TIMER2 = 2,
    TIMER3 = 3,
	TIMER4 = 4,
	TIMER5 = 5,
	TIMER6 = 6
} SERVO_TIMER;

typedef enum
{
    CH1 = 1,
    CH2 = 2,
    CH3 = 3,
	CH4 = 4,
	CH5 = 5,
	CH6 = 6
} SERVO_CHANNEL;

typedef enum
{
    SERVO_ENABLE = 1,
    SERVO_DISABLE = 2
} SERVO_POWER;

typedef struct {
	SERVO_TIMER servo_timer;
	SERVO_CHANNEL servo_channel;
	SERVO_POWER servo_power;
} SERVO_PARAMETERS;

typedef struct {

    SERVO_PARAMETERS servo_params;

} SERVO_HandleTypedef;

void servo_init(uint8_t set_servo_tim, uint8_t set_servo_channel,  SERVO_PARAMETERS *servo_params);
void servo_set_angle(uint8_t angle, SERVO_PARAMETERS *servo_params);
void servo_disable_all();
#endif
