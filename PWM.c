#include <stdint.h>
#include "M4MemMap.h"
#include "PWM.h"
#include "PWM_Cfg.h"

typedef volatile uint32_t* const PWM_RegAddType;

#define MODULES_NUMBER      2u

#define PWM0_BASE_ADDRESS   0x40028000
#define PWM1_BASE_ADDRESS   0x40029000

static const uint32_t ModulesBaseAddressLUT[MODULES_NUMBER] =
{
     PWM0_BASE_ADDRESS,
     PWM1_BASE_ADDRESS
};

#define PWM_REG_ADDRESS(PWM_ID, REG_OFFSET)         (ModulesBaseAddressLUT[PWM_ID] + REG_OFFSET)

/* Control registers for all 4 generators */
#define PWMCTL(PWM_ID)                              *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x000))
#define PWMSYNC(PWM_ID)                             *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x004))
#define PWMENABLE(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x008))
#define PWMINVERT(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x00C))
#define PWMFAULT(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x010))
#define PWMINTEN(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x014))
#define PWMRIS(PWM_ID)                              *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x018))
#define PWMISC(PWM_ID)                              *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x01C))
#define PWMSTATUS(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x020))
#define PWMFAULTVAL(PWM_ID)                         *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x024))
#define PWMENUPD(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x028))

/* Control registers for generator 0 (PWM0) */
#define PWM0CTL(PWM_ID)                             *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x040))
#define PWM0INTEN(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x044))
#define PWM0RIS(PWM_ID)                             *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x048))
#define PWM0ISC(PWM_ID)                             *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x04C))
#define PWM0LOAD(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x050))
#define PWM0COUNT(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x054))
#define PWM0CMPA(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x058))
#define PWM0CMPB(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x05C))
#define PWM0GENA(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x060))
#define PWM0GENB(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x064))
#define PWM0DBCTL(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x068))
#define PWM0DBRISE(PWM_ID)                          *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x06C))
#define PWM0DBFALL(PWM_ID)                          *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x070))
#define PWM0FLTSRC0(PWM_ID)                         *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x074))
#define PWM0FLTSRC1(PWM_ID)                         *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x078))
#define PWM0MINFLTPER(PWM_ID)                       *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x07C))

/* Control registers for generator 1 (PWM1) */
#define PWM1CTL(PWM_ID)                             *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x080))
#define PWM1INTEN(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x084))
#define PWM1RIS(PWM_ID)                             *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x088))
#define PWM1ISC(PWM_ID)                             *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x08C))
#define PWM1LOAD(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x090))
#define PWM1COUNT(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x094))
#define PWM1CMPA(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x098))
#define PWM1CMPB(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x09C))
#define PWM1GENA(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0A0))
#define PWM1GENB(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0A4))
#define PWM1DBCTL(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0A8))
#define PWM1DBRISE(PWM_ID)                          *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0AC))
#define PWM1DBFALL(PWM_ID)                          *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0B0))
#define PWM1FLTSRC0(PWM_ID)                         *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0B4))
#define PWM1FLTSRC1(PWM_ID)                         *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0B8))
#define PWM1MINFLTPER(PWM_ID)                       *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0BC))

/* Control registers for generator 2 (PWM2) */
#define PWM2CTL(PWM_ID)                             *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0C0))
#define PWM2INTEN(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0C4))
#define PWM2RIS(PWM_ID)                             *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0C8))
#define PWM2ISC(PWM_ID)                             *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0CC))
#define PWM2LOAD(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0D0))
#define PWM2COUNT(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0D4))
#define PWM2CMPA(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0D8))
#define PWM2CMPB(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0DC))
#define PWM2GENA(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0E0))
#define PWM2GENB(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0E4))
#define PWM2DBCTL(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0E8))
#define PWM2DBRISE(PWM_ID)                          *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0EC))
#define PWM2DBFALL(PWM_ID)                          *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0F0))
#define PWM2FLTSRC0(PWM_ID)                         *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0F4))
#define PWM2FLTSRC1(PWM_ID)                         *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0F8))
#define PWM2MINFLTPER(PWM_ID)                       *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x0FC))

/* Control registers for generator 3 (PWM3) */
#define PWM3CTL(PWM_ID)                             *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x100))
#define PWM3INTEN(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x104))
#define PWM3RIS(PWM_ID)                             *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x108))
#define PWM3ISC(PWM_ID)                             *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x10C))
#define PWM3LOAD(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x110))
#define PWM3COUNT(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x114))
#define PWM3CMPA(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x118))
#define PWM3CMPB(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x11C))
#define PWM3GENA(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x120))
#define PWM3GENB(PWM_ID)                            *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x124))
#define PWM3DBCTL(PWM_ID)                           *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x128))
#define PWM3DBRISE(PWM_ID)                          *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x12C))
#define PWM3DBFALL(PWM_ID)                          *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x130))
#define PWM3FLTSRC0(PWM_ID)                         *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x134))
#define PWM3FLTSRC1(PWM_ID)                         *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x138))
#define PWM3MINFLTPER(PWM_ID)                       *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x13C))

/* Fault registers for all 4 generators */
/* Generator 0 (PWM0) */
#define PWM0FLTSEN(PWM_ID)                          *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x800))
#define PWM0FLTSTAT0(PWM_ID)                        *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x804))
#define PWM0FLTSTAT1(PWM_ID)                        *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x808))
/* Generator 1 (PWM1) */
#define PWM1FLTSEN(PWM_ID)                          *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x880))
#define PWM1FLTSTAT0(PWM_ID)                        *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x884))
#define PWM1FLTSTAT1(PWM_ID)                        *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x888))
/* Generator 2 (PWM2) */
#define PWM2FLTSTAT0(PWM_ID)                        *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x904))
#define PWM2FLTSTAT1(PWM_ID)                        *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x908))
/* Generator 3 (PWM3) */
#define PWM3FLTSTAT0(PWM_ID)                        *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x984))
#define PWM3FLTSTAT1(PWM_ID)                        *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0x988))

#define PWMPP(PWM_ID)                               *((PWM_RegAddType)PWM_REG_ADDRESS(PWM_ID, 0xFC0))

static uint8_t PWM_ModuleState[MODULES_NUMBER] = {0};


PWM_CheckType PWM_Init(void)
{
    PWM_CheckType RetVar;
    const PWM_CfgType* CfgPtr;
    uint8_t ErrorFlag = 0;
    uint8_t LoopIndex;
    for(LoopIndex = 0; ((LoopIndex < PWM_GROUPS_NUMBER) && (ErrorFlag == 0)); LoopIndex++)
    {
        if(PWM_ConfigParameters[LoopIndex].PWMID < MODULES_NUMBER)
        {
            CfgPtr = &PWM_ConfigParameters[LoopIndex];

            /* Enabling the clock for the appropriate PWM module */
            RCGCPWM_REG |= (1 << CfgPtr->PWMID);

            /* Choosing whether the clock divisor is used or not */
            if(CfgPtr->Divisior != NO_DIVISOR)
            {
                /* Enabling the PWM clock divisor */
                RCC_REG |= 0x100000;
                /* Choosing the unit clock divisor of PWM */
                RCC_REG |= ((CfgPtr->Divisior - 1) << 17);
            }
            else
            {
                /* Enabling the system clock source */
                RCC_REG &= ~(0x100000);
            }

            /* Selecting multiple options depending on the configurations */
            if(CfgPtr->Generator == GENERATOR_0)
            {
                /* Disabling PWM0 block */
                PWM0CTL(CfgPtr->PWMID) &= ~(0x01);
                /* Selecting down or up-down counter */
                if(CfgPtr->Mode == UP_DOWN)
                {
                    PWM0CTL(CfgPtr->PWMID) |= 0x02;
                }
                else
                {
                    PWM0CTL(CfgPtr->PWMID) &= ~(0x02);
                }
                /* Selecting multiple actions on the output depending on the configuration */
                if(CfgPtr->Output == OUTPUT_A)
                {
                    PWM0GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForZero << 0);
                    PWM0GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForLoad << 2);
                    PWM0GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompA << 4);
                    PWM0GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompA << 6);
                    PWM0GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompB << 8);
                    PWM0GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompB << 10);
                }
                else
                {
                    PWM0GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForZero << 0);
                    PWM0GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForLoad << 2);
                    PWM0GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompA << 4);
                    PWM0GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompA << 6);
                    PWM0GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompB << 8);
                    PWM0GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompB << 10);
                }
                /* Loading the load register with the corresponding value for one period */
                PWM0LOAD(CfgPtr->PWMID) = ((CfgPtr->Time * 16) / (2 ^ CfgPtr->Divisior));
            }
            else if(CfgPtr->Generator == GENERATOR_1)
            {
                /* Disabling PWM1 block */
                PWM1CTL(CfgPtr->PWMID) &= ~(0x01);
                /* Selecting down or up-down counter */
                if(CfgPtr->Mode == UP_DOWN)
                {
                    PWM1CTL(CfgPtr->PWMID) |= 0x02;
                }
                else
                {
                    PWM1CTL(CfgPtr->PWMID) &= ~(0x02);
                }
                /* Selecting multiple actions on the output depending on the configuration */
                if(CfgPtr->Output == OUTPUT_A)
                {
                    PWM1GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForZero << 0);
                    PWM1GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForLoad << 2);
                    PWM1GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompA << 4);
                    PWM1GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompA << 6);
                    PWM1GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompB << 8);
                    PWM1GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompB << 10);
                }
                else
                {
                    PWM1GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForZero << 0);
                    PWM1GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForLoad << 2);
                    PWM1GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompA << 4);
                    PWM1GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompA << 6);
                    PWM1GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompB << 8);
                    PWM1GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompB << 10);
                }
                /* Loading the load register with the corresponding value for one period */
                PWM1LOAD(CfgPtr->PWMID) = ((CfgPtr->Time * 16) / (2 ^ CfgPtr->Divisior));
            }
            else if(CfgPtr->Generator == GENERATOR_2)
            {
                /* Disabling PWM2 block */
                PWM2CTL(CfgPtr->PWMID) &= ~(0x01);
                /* Selecting down or up-down counter */
                if(CfgPtr->Mode == UP_DOWN)
                {
                    PWM2CTL(CfgPtr->PWMID) |= 0x02;
                }
                else
                {
                    PWM2CTL(CfgPtr->PWMID) &= ~(0x02);
                }
                /* Selecting multiple actions on the output depending on the configuration */
                if(CfgPtr->Output == OUTPUT_A)
                {
                    PWM2GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForZero << 0);
                    PWM2GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForLoad << 2);
                    PWM2GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompA << 4);
                    PWM2GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompA << 6);
                    PWM2GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompB << 8);
                    PWM2GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompB << 10);
                }
                else
                {
                    PWM2GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForZero << 0);
                    PWM2GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForLoad << 2);
                    PWM2GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompA << 4);
                    PWM2GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompA << 6);
                    PWM2GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompB << 8);
                    PWM2GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompB << 10);
                }
                /* Loading the load register with the corresponding value for one period */
                PWM2LOAD(CfgPtr->PWMID) = ((CfgPtr->Time * 16) / (2 ^ CfgPtr->Divisior));
            }
            else if(CfgPtr->Generator == GENERATOR_3)
            {
                /* Disabling PWM3 block */
                PWM3CTL(CfgPtr->PWMID) &= ~(0x01);
                /* Selecting down or up-down counter */
                if(CfgPtr->Mode == UP_DOWN)
                {
                    PWM3CTL(CfgPtr->PWMID) |= 0x02;
                }
                else
                {
                    PWM3CTL(CfgPtr->PWMID) &= ~(0x02);
                }
                /* Selecting multiple actions on the output depending on the configuration */
                if(CfgPtr->Output == OUTPUT_A)
                {
                    PWM3GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForZero << 0);
                    PWM3GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForLoad << 2);
                    PWM3GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompA << 4);
                    PWM3GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompA << 6);
                    PWM3GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompB << 8);
                    PWM3GENA(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompB << 10);
                }
                else
                {
                    PWM3GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForZero << 0);
                    PWM3GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForLoad << 2);
                    PWM3GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompA << 4);
                    PWM3GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompA << 6);
                    PWM3GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForUpCompB << 8);
                    PWM3GENB(CfgPtr->PWMID) |= (CfgPtr->ActionForDownCompB << 10);
                }
                /* Loading the load register with the corresponding value for one period */
                PWM3LOAD(CfgPtr->PWMID) = ((CfgPtr->Time * 16) / (2 ^ CfgPtr->Divisior));
            }
            else
            {
            }

            PWM_ModuleState[LoopIndex] = 1;
            RetVar = PWM_OK;
        }
        else
        {
            ErrorFlag = 1;
            RetVar = PWM_NOK;
        }
    }
    return RetVar;
}

PWM_CheckType PWM_Start(uint8_t ModuleID, uint8_t DutyCycle)
{
    PWM_CheckType RetVar;
    const PWM_CfgType* CfgPtr;
    static uint8_t TempDC = 200;
    if((ModuleID < PWM_GROUPS_NUMBER) && (DutyCycle <= 100) && (PWM_ModuleState[ModuleID] == 1))
    {
        CfgPtr = &PWM_ConfigParameters[ModuleID];
        if(TempDC != DutyCycle)
        {
            if(CfgPtr->Generator == GENERATOR_0)
            {
                if(CfgPtr->Output == OUTPUT_A)
                {
                    PWM0CMPA(CfgPtr->PWMID) = (PWM0LOAD(CfgPtr->PWMID) - ((PWM0LOAD(CfgPtr->PWMID) * DutyCycle) / 100));
                    PWM0CTL(CfgPtr->PWMID) |= 0x01;
                    PWMENABLE(CfgPtr->PWMID) |= 0x01;
                }
                else
                {
                    PWM0CMPB(CfgPtr->PWMID) = (PWM0LOAD(CfgPtr->PWMID) - ((PWM0LOAD(CfgPtr->PWMID) * DutyCycle) / 100));
                    PWM0CTL(CfgPtr->PWMID) |= 0x01;
                    PWMENABLE(CfgPtr->PWMID) |= 0x02;
                }
            }
            else if(CfgPtr->Generator == GENERATOR_1)
            {
                if(CfgPtr->Output == OUTPUT_A)
                {
                    PWM1CMPA(CfgPtr->PWMID) = (PWM1LOAD(CfgPtr->PWMID) - ((PWM1LOAD(CfgPtr->PWMID) * DutyCycle) / 100));
                    PWM1CTL(CfgPtr->PWMID) |= 0x01;
                    PWMENABLE(CfgPtr->PWMID) |= 0x04;
                }
                else
                {
                    PWM1CMPB(CfgPtr->PWMID) = (PWM1LOAD(CfgPtr->PWMID) - ((PWM1LOAD(CfgPtr->PWMID) * DutyCycle) / 100));
                    PWM1CTL(CfgPtr->PWMID) |= 0x01;
                    PWMENABLE(CfgPtr->PWMID) |= 0x08;
                }
            }
            else if(CfgPtr->Generator == GENERATOR_2)
            {
                if(CfgPtr->Output == OUTPUT_A)
                {
                    PWM2CMPA(CfgPtr->PWMID) = (PWM2LOAD(CfgPtr->PWMID) - ((PWM2LOAD(CfgPtr->PWMID) * DutyCycle) / 100));
                    PWM2CTL(CfgPtr->PWMID) |= 0x01;
                    PWMENABLE(CfgPtr->PWMID) |= 0x10;
                }
                else
                {
                    PWM2CMPB(CfgPtr->PWMID) = (PWM2LOAD(CfgPtr->PWMID) - ((PWM2LOAD(CfgPtr->PWMID) * DutyCycle) / 100));
                    PWM2CTL(CfgPtr->PWMID) |= 0x01;
                    PWMENABLE(CfgPtr->PWMID) |= 0x20;
                }
            }
            else if(CfgPtr->Generator == GENERATOR_3)
            {
                if(CfgPtr->Output == OUTPUT_A)
                {
                    PWM3CMPA(CfgPtr->PWMID) = (PWM3LOAD(CfgPtr->PWMID) - ((PWM3LOAD(CfgPtr->PWMID) * DutyCycle) / 100));
                    PWM3CTL(CfgPtr->PWMID) |= 0x01;
                    PWMENABLE(CfgPtr->PWMID) |= 0x40;
                }
                else
                {
                    PWM3CMPB(CfgPtr->PWMID) = (PWM3LOAD(CfgPtr->PWMID) - ((PWM3LOAD(CfgPtr->PWMID) * DutyCycle) / 100));
                    PWM3CTL(CfgPtr->PWMID) |= 0x01;
                    PWMENABLE(CfgPtr->PWMID) |= 0x80;
                }
            }
            else
            {
            }
            TempDC = DutyCycle;
        }
        else
        {
        }
        RetVar = PWM_OK;
    }
    else
    {
        RetVar = PWM_NOK;
    }
    return RetVar;
}
