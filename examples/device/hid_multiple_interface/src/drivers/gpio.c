#include "ch32v30x.h"
#include "pin_defs.h"
#include "gpio.h"

void setPinOutputOpenDrain(GPIO_TypeDef* port, uint16_t pad) {
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    GPIO_InitStructure.GPIO_Pin = pad;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_Init(port, &GPIO_InitStructure);
}

void setPinOutput(GPIO_TypeDef* port, uint16_t pad) {
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    GPIO_InitStructure.GPIO_Pin = pad;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(port, &GPIO_InitStructure);
}

void setPinInput(GPIO_TypeDef* port, uint16_t pad) {
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    GPIO_InitStructure.GPIO_Pin = pad;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(port, &GPIO_InitStructure);
}

void setPinInputHigh(GPIO_TypeDef* port, uint16_t pad) {
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    GPIO_InitStructure.GPIO_Pin = pad;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(port, &GPIO_InitStructure);
}

void init_buttons(void) {
    // Left Click - NO1 - A9
    // Left Click - NC1 - A8
    // Right Click - NO2 - A0
    // Right Click - NC2 - A1
    // Middle Click - NO3 - A2
    // Middle Click - NC3 - A7
    // M4 Click - NO4 - A11
    // M4 Click - NC4 - A10
    // M5 Click - NO5 - A13
    // M5 Click - NC5 - A12

    // encoder A - A6
    // encoder B - A5

    // EEPROM CS - A14
    EXTI_InitTypeDef EXTI_InitStructure = {0};
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA, ENABLE);

    setPinInput(A1);
    setPinInput(A2);
    setPinInput(A5);
    setPinInput(A6);
    setPinInput(A7);
    setPinInput(A8);
    setPinInput(A9);
    setPinInput(A10);
    setPinInput(A11);
    setPinInput(A12);
    setPinInput(A13);

    setPinInputHigh(A5);
    setPinInputHigh(A6);

    // enable EXTI for the button clicks
    /* GPIOA ----> EXTI_Line0 */
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource1);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource2);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource5);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource6);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource7);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource9);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource10);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource11);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource12);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource13);

    EXTI_InitStructure.EXTI_Line =    EXTI_Line1
                                    | EXTI_Line2
                                    | EXTI_Line5
                                    | EXTI_Line6
                                    | EXTI_Line7
                                    | EXTI_Line8
                                    | EXTI_Line9
                                    | EXTI_Line10
                                    | EXTI_Line11
                                    | EXTI_Line12
                                    | EXTI_Line13;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
}