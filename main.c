/******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for the Infineon T2G devices GPIO Pins
* example. This code example demonstrates the use of GPIO pins configured
* as inputs, outputs, GPIO interrupts and full configuration in the T2G devices.
*
* Related Document: See README.md
*
*
*******************************************************************************
* Copyright 2022-2023, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/
#include "cy_pdl.h"
#include "cybsp.h"
#include "cycfg_pins.h"

/******************************************************************************
 * Macros for both examples
 *****************************************************************************/
#define GPIO_INTERRUPT_PRIORITY (7u)

/*
 *This code example assumes that the Device Configurator will automatically configure
 * all GPIO pins of the device. To see how PDL drivers are used to manually
 * configure GPIO pins, set the PDL_PIN_CONFIGURATION #define to 1, otherwise leave
 * set to 0. The names of ports and pins will also need to be changed in the PDL code example.
 * This can be done by changing CYBSP_USER_BTN_PORT to P21_4_PORT and CYBSP_USER_BTN_PIN to P21_4_PIN.
 */
#define PDL_PIN_CONFIGURATION 0


/******************************************************************************
 * Definitions and functions for PDL example
 *****************************************************************************/
#if PDL_PIN_CONFIGURATION
/* This structure is used to initialize a single GPIO pin using PDL configuration.*/
const cy_stc_gpio_pin_config_t P21_4_Pin_Init =
    {
        .outVal = 1u,                    /* Pin output state */
        .driveMode = CY_GPIO_DM_PULLUP,  /* Drive mode */
        .hsiom = HSIOM_SEL_GPIO,         /* HSIOM selection */
        .intEdge = CY_GPIO_INTR_FALLING, /* Interrupt Edge type */
        .intMask = CY_GPIO_INTR_EN_MASK, /* Interrupt enable mask */
        .vtrip = CY_GPIO_VTRIP_CMOS,     /* Input buffer voltage trip type */
        .slewRate = CY_GPIO_SLEW_FAST,   /* Output buffer slew rate */
        .driveSel = CY_GPIO_DRIVE_FULL,  /* Drive strength */
        .vregEn = 0u,                    /* SIO pair output buffer mode */
        .ibufMode = 0u,                  /* SIO pair input buffer mode */
        .vtripSel = 0u,                  /* SIO pair input buffer trip point */
        .vrefSel = 0u,                   /* SIO pair reference voltage for input buffer trip point */
        .vohSel = 0u                     /* SIO pair regulated voltage output level */
};
#endif

/* This structure is used to initialize a full GPIO Port using PDL configuration */
const cy_stc_gpio_prt_config_t port13_Init =
    {
        .out = 0x000000FFu,        /* Initial output data for the IO pins in the port */
        .intrMask = 0x00000000u,   /* Interrupt enable mask for the port interrupt */
        .intrCfg = 0x00000000u,    /* Port interrupt edge detection configuration */
        .cfg = 0xEEEEEEEEu,        /* Port drive modes and input buffer enable configuration */
        .cfgIn = 0x00000000u,      /* Port input buffer configuration */
        .cfgOut = 0x00000000u,     /* Port output buffer configuration */
        .cfgSIO = 0x00000000u,     /* Port SIO configuration */
        .sel0Active = 0x00000000u, /* HSIOM selection for port pins 0,1,2,3 */
        .sel1Active = 0x00000000u, /* HSIOM selection for port pins 4,5,6,7 */
};

/* This structure initializes the Port5 interrupt for the NVIC */
cy_stc_sysint_t intrCfg =
{
    .intrSrc = ((NvicMux3_IRQn << CY_SYSINT_INTRSRC_MUXIRQ_SHIFT) | ioss_interrupts_gpio_5_IRQn), /* Interrupt source is GPIO port 5 interrupt */
    .intrPriority = GPIO_INTERRUPT_PRIORITY                            /* Interrupt priority is 7 */
};

uint32 pinState = 0ul;

 /*This section defines the port and pins for the USER_LED and USER_BTN.
   The CYBSP macros for these resources are used in the HAL section. The macros
   are translated using the "CYHAL_GET_PORTADDR" and "CYHAL_GET_PIN" macro expansions to
   translate the CYBSP macros into the port and pin types that are used in PDL functions.
   This is not needed normally unless you are wanting to use the HAL BSP names.*/

/* Port and pin translations for the USER_BTN1 */
#if PDL_PIN_CONFIGURATION
#define  CYBSP_USER_BUTTON_PORT P21_4_PORT
#define  CYBSP_USER_BUTTON_PIN  P21_4_PIN
#else
#define CYBSP_USER_BUTTON_PORT      CYBSP_USER_BTN1_PORT
#define CYBSP_USER_BUTTON_PIN       CYBSP_USER_BTN1_PIN
#endif


/*******************************************************************************
* Function Prototypes
********************************************************************************/

static void pdl_code_example();

/*******************************************************************************
* Global Variables
********************************************************************************/
/* Semaphore from interrupt handler to background process */
volatile bool gpio_intr_flag = false;


/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  System entrance point.
*
* Return: int
*
*******************************************************************************/
int main(void)
{

   pdl_code_example();

}

/*******************************************************************************
* Function Name: GPIO_Interrupt_handler_PDL
********************************************************************************
*
*  Summary:
*  GPIO interrupt handler for the PDL example.
*
*  Parameters:
*  None
*
*  Return:
*  None
*
**********************************************************************************/
static void gpio_interrupt_handler_PDL()
{
    gpio_intr_flag = true;

    /* Clear pin interrupt logic. Required to detect next interrupt */
    Cy_GPIO_ClearInterrupt(CYBSP_USER_BUTTON_PORT, CYBSP_USER_BUTTON_PIN);
}

/*******************************************************************************
* Function Name: pdl_code_example
********************************************************************************
* Summary:
*   PDL version of the GPIO code example.
*
* Parameters:
*  None
*
*******************************************************************************/
static void pdl_code_example()
{
    cy_rslt_t result;
    volatile bool read_val = false;
    uint32 portReadValue = 0ul;

    /* Initialize the device and board peripherals */
    result = cybsp_init();

    /* Enable global interrupts */
    __enable_irq();

    /* Board initialize failed. Stop program execution */
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    /* The most code efficient method to configure all attributes for a full port of pins */
    /* is to use the Cy_GPIO_Port_Init() API function and configuration structure. It packs all */
    /* the configuration data into direct register writes for the whole port. Its limitation */
    /* is that it must configure all pins in a port and the user must calculate the */
    /* combined register values for all pins. */
    Cy_GPIO_Port_Init(GPIO_PRT13, &port13_Init);

    /* Initialize USER_LED */
    Cy_GPIO_Pin_FastInit(CYBSP_USER_LED_PORT, CYBSP_USER_LED_PIN, CY_GPIO_DM_STRONG, 1UL, HSIOM_SEL_GPIO);

    /* Initialize the user button */
    Cy_GPIO_Pin_FastInit(CYBSP_USER_BUTTON_PORT, CYBSP_USER_BUTTON_PIN, CY_GPIO_DM_PULLUP, 1UL, HSIOM_SEL_GPIO);

    /* Pin Interrupts */
    /* Configure GPIO pin to generate interrupts */
    Cy_GPIO_SetInterruptEdge(CYBSP_USER_BUTTON_PORT, CYBSP_USER_BUTTON_PIN, CY_GPIO_INTR_RISING);
    Cy_GPIO_SetInterruptMask(CYBSP_USER_BUTTON_PORT, CYBSP_USER_BUTTON_PIN, CY_GPIO_INTR_EN_MASK);

    /* Configure CPU GPIO interrupt vector */
    Cy_SysInt_Init(&intrCfg, gpio_interrupt_handler_PDL);
    NVIC_ClearPendingIRQ((IRQn_Type)intrCfg.intrSrc);
    NVIC_EnableIRQ((IRQn_Type) NvicMux3_IRQn);

    for (;;)
    {
        /* Read current button state from the user button on pin 21_4 */
        read_val = Cy_GPIO_Read(CYBSP_USER_BUTTON_PORT, CYBSP_USER_BUTTON_PIN);

        /* If button released, LED OFF */
        if (read_val == true)
        {
            Cy_GPIO_Write(CYBSP_USER_LED_PORT, CYBSP_USER_LED_PIN, CYBSP_LED_STATE_OFF);
        }
        /* If button pressed, LED ON */
        if (read_val == false)
        {
            Cy_GPIO_Write(CYBSP_USER_LED_PORT, CYBSP_USER_LED_PIN, CYBSP_LED_STATE_ON);
        }

        /* Check the interrupt status */
        if (true == gpio_intr_flag)
        {
            /* Reset interrupt flag */
            gpio_intr_flag = false;

            /* Flash LED twice */

               /* LED OFF */
               /* Using general PDL Write function */
               Cy_GPIO_Write(CYBSP_USER_LED_PORT, CYBSP_USER_LED_PIN, CYBSP_LED_STATE_OFF);
               Cy_SysLib_Delay(500);

               /* LED ON */
               /* Using general PDL Write function */
               Cy_GPIO_Write(CYBSP_USER_LED_PORT, CYBSP_USER_LED_PIN, CYBSP_LED_STATE_ON);
               Cy_SysLib_Delay(500);

               /* LED OFF */
               /* Using pin invert function, inverts the current state of the pin */
               Cy_GPIO_Inv(CYBSP_USER_LED_PORT, CYBSP_USER_LED_PIN);
               Cy_SysLib_Delay(500);

               /* LED ON */
               /* Using pin Clear function, sets the pin output to logic state Low. */
               Cy_GPIO_Clr(CYBSP_USER_LED_PORT, CYBSP_USER_LED_PIN);
               Cy_SysLib_Delay(500);

               /* LED OFF */
               /* Using pin Set function, sets the pin output to logic state High. */
               Cy_GPIO_Set(CYBSP_USER_LED_PORT, CYBSP_USER_LED_PIN);
        }

        /* Simultaneous Port Pin access */
        /*******************************************************************************/
        /* Direct register access is used to interface with multiple pins in one port */
        /* at the same time. May not be thread or multi-core safe due to possible */
        /* read-modify-write operations. All pins in a Port under direct register */
        /* control should only be accessed by a single CPU core. */

        portReadValue = GPIO_PRT13->IN;
        portReadValue++;
        GPIO_PRT13->OUT = portReadValue;
    }
}


/* [] END OF FILE */
