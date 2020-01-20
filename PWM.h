#ifndef PWM_H_
#define PWM_H_
#include <stdint.h>
#include "PWM_Cfg.h"


typedef enum {GENERATOR_0, GENERATOR_1, GENERATOR_2, GENERATOR_3} GeneratorID;
typedef enum {OUTPUT_A, OUTPUT_B} OutputID;
typedef enum {NO_DIVISOR, DIVIDE_BY_2, DIVIDE_BY_4, DIVIDE_BY_8, DIVIDE_BY_16, DIVIDE_BY_32, DIVIDE_BY_64} ClockDiv;
typedef enum {DOWN, UP_DOWN} CountMode;
typedef enum {NOTHING, INVERT, LOW, HIGH} Action;

typedef struct
{
    /* Selecting PWM0 or PWM1 module */
    uint8_t PWMID;
    /* Selecting Generator 0, 1, 2 or 3 */
    GeneratorID Generator;
    /* Selecting Output A or B */
    OutputID Output;
    /* Selecting the divisor of the clock */
    ClockDiv Divisior;
    /* Selecting down count or up-down counter */
    CountMode Mode;
    /* Selecting the action happened on the output when the counter equals 0 */
    Action ActionForZero;
    /* Selecting the action happened on the output when the counter equals the loaded value */
    Action ActionForLoad;
    /* Selecting the action happened on the output when the counter equals the comparator A value while counting up */
    Action ActionForUpCompA;
    /* Selecting the action happened on the output when the counter equals the comparator A value while counting down */
    Action ActionForDownCompA;
    /* Selecting the action happened on the output when the counter equals the comparator B value while counting up */
    Action ActionForUpCompB;
    /* Selecting the action happened on the output when the counter equals the comparator B value while counting down */
    Action ActionForDownCompB;
    /* Entering the time of one cycle in microseconds */
    uint32_t Time;
} PWM_CfgType;

typedef enum {PWM_OK, PWM_NOK} PWM_CheckType;

extern const PWM_CfgType PWM_ConfigParameters[PWM_GROUPS_NUMBER];


PWM_CheckType PWM_Init(void);
PWM_CheckType PWM_Start(uint8_t ModuleID, uint8_t DutyCycle);

#endif /* PWM_H_ */
