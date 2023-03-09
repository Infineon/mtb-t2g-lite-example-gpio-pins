# TRAVEO™ T2G MCU: GPIO pins

This example demonstrates the GPIO pin operation on the TRAVEO™ T2G MCU, using Eclipse IDE for ModusToolbox™. This includes reading, writing, interrupts, and full configuration.

[View this README on GitHub.](https://github.com/Infineon/mtb-t2g-lite-example-gpio-pins)

## Requirements

- [ModusToolbox&trade; software](https://www.infineon.com/modustoolbox) v3.0 or later (tested with v3.0)
- Programming language: C
- Associated parts: [TRAVEO™ T2G body high MCU](https://www.infineon.com/cms/en/product/microcontroller/32-bit-traveo-t2g-arm-cortex-microcontroller/32-bit-traveo-t2g-arm-cortex-for-body/traveo-t2g-cyt4bf-series/)


## Supported toolchains (make variable 'TOOLCHAIN')

- GNU Arm&reg; embedded compiler v10.3.1 (`GCC_ARM`) - Default value of `TOOLCHAIN`
- Arm&reg; compiler v6.16 (`ARM`)
- IAR C/C++ compiler v9.30.1 (`IAR`)


## Supported kits (make variable 'TARGET')

- TRAVEO™ T2G body high evaluation kit (`KIT_T2G-B-H_LITE`) - Default value of `TARGET`

## Hardware setup

This example uses the board's default configuration. See the kit user guide to ensure that the board is configured correctly.


## Software setup

This example requires no additional software or tools.


## Using the code example

Create the project and open it using one of the following:

<details><summary><b>In Eclipse IDE for ModusToolbox&trade; software</b></summary>

1. Click the **New Application** link in the **Quick Panel** (or, use **File** > **New** > **ModusToolbox&trade; Application**). This launches the [Project Creator](https://www.infineon.com/ModusToolboxProjectCreator) tool.

2. Pick a kit supported by the code example from the list shown in the **Project Creator - Choose Board Support Package (BSP)** dialog.

   When you select a supported kit, the example is reconfigured automatically to work with the kit. To work with a different supported kit later, use the [Library Manager](https://www.infineon.com/ModusToolboxLibraryManager) to choose the BSP for the supported kit. You can use the Library Manager to select or update the BSP and firmware libraries used in this application. To access the Library Manager, click the link from the **Quick Panel**.

   You can also just start the application creation process again and select a different kit.

   If you want to use the application for a kit not listed here, you may need to update the source files. If the kit does not have the required resources, the application may not work.

3. In the **Project Creator - Select Application** dialog, choose the example by enabling the checkbox.

4. (Optional) Change the suggested **New Application Name**.

5. The **Application(s) Root Path** defaults to the Eclipse workspace which is usually the desired location for the application. If you want to store the application in a different location, you can change the *Application(s) Root Path* value. Applications that share libraries should be in the same root path.

6. Click **Create** to complete the application creation process.

For more details, see the [Eclipse IDE for ModusToolbox&trade; software user guide](https://www.infineon.com/MTBEclipseIDEUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/docs_{version}/mt_ide_user_guide.pdf*).

</details>

<details><summary><b>In command-line interface (CLI)</b></summary>

ModusToolbox&trade; software provides the Project Creator as both a GUI tool and the command line tool, "project-creator-cli". The CLI tool can be used to create applications from a CLI terminal or from within batch files or shell scripts. This tool is available in the *{ModusToolbox&trade; software install directory}/tools_{version}/project-creator/* directory.

Use a CLI terminal to invoke the "project-creator-cli" tool. On Windows, use the command line "modus-shell" program provided in the ModusToolbox&trade; software installation instead of a standard Windows command-line application. This shell provides access to all ModusToolbox&trade; software tools. You can access it by typing `modus-shell` in the search box in the Windows menu. In Linux and macOS, you can use any terminal application.

The "project-creator-cli" tool has the following arguments:

Argument | Description | Required/optional
---------|-------------|-----------
`--board-id` | Defined in the `<id>` field of the [BSP](https://github.com/Infineon?q=bsp-manifest&type=&language=&sort=) manifest | Required
`--app-id`   | Defined in the `<id>` field of the [CE](https://github.com/Infineon?q=ce-manifest&type=&language=&sort=) manifest | Required
`--target-dir`| Specify the directory in which the application is to be created if you prefer not to use the default current working directory | Optional
`--user-app-name`| Specify the name of the application if you prefer to have a name other than the example's default name | Optional

<br />

The following example will clone the "[mtb-t2g-lite-example-gpio-pins](https://github.com/Infineon/mtb-t2g-lite-example-gpio-pins)" application with the desired name "GpioPins" configured for the *KIT_T2G-B-H_LITE* BSP into the specified working directory, *C:/mtb_projects*:

   ```
   project-creator-cli --board-id KIT_T2G-B-H_LITE --app-id mtb-t2g-lite-example-gpio-pins --user-app-name GpioPins --target-dir "C:/mtb_projects"
   ```

**Note:** The project-creator-cli tool uses the `git clone` and `make getlibs` commands to fetch the repository and import the required libraries. For details, see the "Project creator tools" section of the [ModusToolbox&trade; software user guide](https://www.infineon.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/docs_{version}/mtb_user_guide.pdf*).

To work with a different supported kit later, use the [Library Manager](https://www.infineon.com/ModusToolboxLibraryManager) to choose the BSP for the supported kit. You can invoke the Library Manager GUI tool from the terminal using `make modlibs` command or use the Library Manager CLI tool "library-manager-cli" to change the BSP.

The "library-manager-cli" tool has the following arguments:

Argument | Description | Required/optional
---------|-------------|-----------
`--add-bsp-name` | Name of the BSP that should be added to the application | Required
`--set-active-bsp` | Name of the BSP that should be as active BSP for the application | Required
`--add-bsp-version`| Specify the version of the BSP that should be added to the application if you do not wish to use the latest from manifest | Optional
`--add-bsp-location`| Specify the location of the BSP (local/shared) if you prefer to add the BSP in a shared path | Optional

</details>

<details><summary><b>In third-party IDEs</b></summary>

Use one of the following options:

- **Use the standalone [Project Creator](https://www.infineon.com/ModusToolboxProjectCreator) tool:**

   1. Launch Project Creator from the Windows Start menu or from *{ModusToolbox&trade; software install directory}/tools_{version}/project-creator/project-creator.exe*.

   2. In the initial **Choose Board Support Package** screen, select the BSP, and click **Next**.

   3. In the **Select Application** screen, select the appropriate IDE from the **Target IDE** drop-down menu.

   4. Click **Create** and follow the instructions printed in the bottom pane to import or open the exported project in the respective IDE.

<br />

- **Use command-line interface (CLI):**

   1. Follow the instructions from the **In command-line interface (CLI)** section to create the application, and then import the libraries using the `make getlibs` command.

   2. Export the application to a supported IDE using the `make <ide>` command.

   3. Follow the instructions displayed in the terminal to create or import the application as an IDE project.

For a list of supported IDEs and more details, see the "Exporting to IDEs" section of the [ModusToolbox&trade; software user guide](https://www.infineon.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/docs_{version}/mtb_user_guide.pdf*).

</details>


## Operation

1. Connect the board to your PC using the provided USB cable through the KitProg3 USB connector.

2. Program the board using one of the following:

   <details><summary><b>Using Eclipse IDE for ModusToolbox&trade; software</b></summary>

      1. Select the application project in the Project Explorer.

      2. In the **Quick Panel**, scroll down, and click **\<Application Name> Program (KitProg3_MiniProg4)**.
   </details>

   <details><summary><b>Using CLI</b></summary>

     From the terminal, execute the `make program` command to build and program the application using the default toolchain to the default target. The default toolchain and target are specified in the application's Makefile but you can override those values manually:
      ```
      make program TARGET=<BSP> TOOLCHAIN=<toolchain>
      ```

      Example:
      ```
      make program KIT_T2G-B-H_LITE TOOLCHAIN=GCC_ARM
      ```
   </details>

3. Press the user button (USER BTN1) and observe that the user LED (KIT_LED2) turns ON demonstrating the GPIO read and write function.

5. Release the user button, observe that the user LED turns OFF and then the user LED blinks twice demonstrating the pin interrupt functionality.


## Debugging

You can debug the example to step through the code. In the IDE, use the **\<Application Name> Debug (KitProg3_MiniProg4)** configuration in the **Quick Panel**. For more details, see the "Program and debug" section in the [Eclipse IDE for ModusToolbox&trade; software user guide](https://www.infineon.com/dgdl/Infineon-Eclipse_IDE_for_ModusToolbox_User_Guide_1-UserManual-v01_00-EN.pdf?fileId=8ac78c8c7d718a49017d99bcb86331e8&utm_source=cypress&utm_medium=referral&utm_campaign=202110_globe_en_all_integration-files).

## Design and implementation

### Overview

This example demonstrates the GPIO pin configuration, reading, writing, and interrupts using multiple GPIO PDL methods. This example shows various ways of using the GPIO pins to meet the needs of the project.

To demonstrate individual GPIO pin access, this example reads the value from the reference pin (user button) and writes it to the user LED. The user LED blinks twice to demonstrate various GPIO functions. The user button is configured to generate an interrupt on a falling edge, which occurs on a button release. The interrupt routine sets a flag to run the blinking sequence within the example loop. 

### PDL

See the [ModusToolbox&trade; CAT1 peripheral driver library API documentation](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html).


#### Pin configuration

Device configuration tools such as ModusToolbox&trade; Device Configurator automatically generate the GPIO configuration code and execute it as part of the device boot process. See the [ModusToolbox&trade; Device Configurator guide](https://www.infineon.com/ModusToolboxDeviceConfig) for details.

GPIO PDL initialization methods are typically used only with manual PDL GPIO configuration when not using a configuration tool. They may also be used at run time to dynamically reconfigure GPIO pins independent of how the initial configuration was performed.

Most GPIO pins require only their basic parameters to be set and can use default values for all other settings. This allows the use of a simplified initialization function.

[Cy_GPIO_Pin_FastInit ()](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__gpio__functions__init.html#gaf57c501727276013d3e8974a9fb7d0a7) supports only parameterized configuration of drive mode, output logic level, and high-speed input/output multiplexer (HSIOM) setting. The HSIOM setting determines a pin’s high-level software, peripheral, analog control, and connectivity. All other configuration settings are unchanged from their reset or previously set state. This function is very useful at run time to dynamically change a pin's configuration.

For example, to configure a pin to strong drive mode to write data, and then reconfigure the pin as High-Z to read data, use the following snippet:

```
/* Initialize USER_LED */
Cy_GPIO_Pin_FastInit(CYBSP_USER_LED_PORT, CYBSP_USER_LED_PIN, CY_GPIO_DM_STRONG, 1UL, HSIOM_SEL_GPIO);
```

A method to configure all attributes of a single pin is to use the [Cy_GPIO_Pin_Init ()](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__gpio__functions__init.html#gad61553f65d4e6bd827eb6464a7913461) function and a pin configuration structure. While easy to use, it generates a larger code than other configuration methods.

```
Cy_GPIO_Pin_Init(P21_4_PORT, P21_4_PIN, &P21_4_Pin_Init);
```

The most code-efficient method to configure all attributes for a full port of pins is to use the `Cy_GPIO_Port_Init()` function and a port configuration structure. It packs all the configuration data into direct register writes for the whole port. Its limitation is that it must configure all pins in a port and the user must calculate the combined register values for all pins.

```
Cy_GPIO_Port_Init(GPIO_PRT5, &port5_Init);
```

#### Pin read

The following methods perform the same read from a GPIO pin using various available read methods. Choose the most appropriate method for your specific use case. The [Cy_GPIO_Read ()](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__gpio__functions__gpio.html#ga3d44507453ea90abde3013c1ac867df8) function is thread- and multi-core-safe.

Most GPIO driver functions require a minimum of two arguments to define the port and pin in that port. The port argument expects the base address of the port’s registers. The pin argument expects the pin number within the port.

```c++
Cy_GPIO_Read(CYBSP_USER_BTN_PORT, CYBSP_USER_BTN_PIN);
```


Pin reads using port and pin numbers are also supported. This method is useful for algorithmically generated port and pin numbers. `Cy_GPIO_PortToAddr()` is a helper function that converts the port number into the required port register base address required by other GPIO driver functions.

```c++
portNumber = 0;
pinReadValue = Cy_GPIO_Read(Cy_GPIO_PortToAddr(portNumber), 4);
```

Like any MCU, direct port register access is always available and useful for accessing multiple pins in a port simultaneously or developing application-optimized port accesses. The following example shows a port IN register read with mask and shift of the desired pin data:

```c++
pinReadValue = (GPIO_PRT0->IN >> P21_4_NUM) & CY_GPIO_IN_MASK;
```

#### Pin write

The PDL API documentation provides multiple ways of writing to GPIO pins. The main method is to use the [Cy_GPIO_Write()](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__gpio__functions__gpio.html#ga849c813d6771bf8d3c59b89b28a07bca) function.

```c++
Cy_GPIO_Write(CYBSP_USER_LED_PORT, CYBSP_USER_LED_PIN, CYBSP_LED_STATE_OFF);
```

The pin Invert function inverts the current state of the pin:

```c++
Cy_GPIO_Inv(CYBSP_USER_LED_PORT, CYBSP_USER_LED_PIN);
```

The pin Clear function clears the pin output to logic state LOW:

```c++
Cy_GPIO_Clr(CYBSP_USER_LED_PORT, CYBSP_USER_LED_PIN);
```

The pin Set function sets the pin output to logic state HIGH:

```c++
Cy_GPIO_Set(CYBSP_USER_LED_PORT, CYBSP_USER_LED_PIN);
```


#### Port access

Direct register access is used to interface with multiple pins in one port at the same time. These accesses may not be thread- or multi-core-safe due to possible read-modify-write operations. All pins in a port under direct register control should be accessed only by a single CPU core unless access protections are provided at the system level.

```c++
portReadValue = GPIO_PRT5->IN;

portReadValue++;

GPIO_PRT5->OUT = portReadValue;
```

#### Pin interrupts

To generate a pin interrupt, configure it to trigger on a rising, falling, or both edges, and mask it so that the pin signal is sent to the interrupt controller vector for that port.

```c++
Cy_GPIO_SetInterruptEdge(CYBSP_USER_BTN_PORT, CYBSP_USER_BTN_PIN, CY_GPIO_INTR_RISING);
Cy_GPIO_SetInterruptMask(CYBSP_USER_BTN_PORT, CYBSP_USER_BTN_PIN, CY_GPIO_INTR_EN_MASK);
```

The port interrupt vector must then be configured, cleared, and enabled to be triggered from the port interrupt signal and mapped to the desired interrupt service routine (ISR). See the [PDL Cy_SysInt()](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__sysint__functions.html#gab2ff6820a898e9af3f780000054eea5d) documentation for more information on interrupt configuration and use.

```c++
/* Configure CM7+ CPU GPIO interrupt vector for Port 0 */
Cy_SysInt_Init(&intrCfg, gpio_interrupt_handler_PDL);
NVIC_ClearPendingIRQ((IRQn_Type)intrCfg.intrSrc);
NVIC_EnableIRQ((IRQn_Type) NvicMux3_IRQn);
```

After an interrupt occurs, the pin interrupt must be cleared before exiting the ISR so that the edge detection logic is reset to allow the detection of the next edge:

```c++
static void gpio_interrupt_handler_PDL()
{
   gpio_intr_flag = true;

   /* Clear pin interrupt logic. Required to detect next interrupt */
   Cy_GPIO_ClearInterrupt(CYHAL_GET_PORTADDR(CYBSP_USER_BTN), CYHAL_GET_PIN(CYBSP_USER_BTN));

}
```


### Resources and settings

**Table 1. Application resources**

| Resource  |  Alias/object     |    Purpose     |
| :------- | :------------    | :------------ |
| GPIO (BSP) | CYBSP_USER_LED    | User LED to show the output           |
| GPIO (BSP) | CYBSP_USER_BTN | User button to generate the interrupt |
| GPIO(BSP)  | GPIO_PRT5         | Simultaneous port pin access          |

<br>

## Related resources

Resources  | Links
-----------|----------------------------------
Application notes | AN235305 - GETTING STARTED WITH TRAVEO™ T2G FAMILY MCUS IN MODUSTOOLBOX™
Training  | [Traveo™ II I/O System](https://www.infineon.com/dgdl/Infineon-Traveo_II_I_O_System-Training-v05_00-EN.pdf?fileId=8ac78c8c7d718a49017d9f6ce5033b21)
Code examples  | [TRAVEO™ T2G MCU examples](https://github.com/orgs/Infineon/repositories?q=mtb-t2g-&type=all&language=&sort=) on GitHub
Device documentation | [Device datasheet](https://www.cypress.com/documentation/datasheets/cyt4bf-datasheet-32-bit-arm-cortex-m7-microcontroller-traveo-ii-family) <br> [Architecture Technical reference manuals (TRM)](https://www.cypress.com/documentation/technical-reference-manuals/traveo-ii-automotive-body-controller-high-family) <br> [Registers TRM](https://www.cypress.com/documentation/technical-reference-manuals/traveo-t2g-tvii-b-h-8m-registers-body-controller-high)
Libraries on GitHub  | [mtb-pdl-cat1](https://github.com/Infineon/mtb-pdl-cat1) – Peripheral driver library (PDL)  <br> [mtb-hal-cat1](https://github.com/Infineon/mtb-hal-cat1) – Hardware abstraction layer (HAL) library <br> [retarget-io](https://github.com/Infineon/retarget-io) – Utility library to retarget STDIO messages to a UART port
Middleware on GitHub  | [mcu-middleware](https://github.com/Infineon/modustoolbox-software) – Links to all MCU middleware
Tools  | [Eclipse IDE for ModusToolbox&trade; software](https://www.infineon.com/modustoolbox) – ModusToolbox&trade; software is a collection of easy-to-use software and tools enabling rapid development with Infineon MCUs, covering applications from embedded sense and control to wireless and cloud-connected systems using AIROC&trade; Wi-Fi and Bluetooth® connectivity devices.

<br />

## Other resources

Infineon provides a wealth of data at www.infineon.com to help you select the right device, and quickly and effectively integrate it into your design.

For TRAVEO™ T2G body high MCU devices, see [TRAVEO™ T2G CYT4BF Series](https://www.infineon.com/cms/en/product/microcontroller/32-bit-traveo-t2g-arm-cortex-microcontroller/32-bit-traveo-t2g-arm-cortex-for-body/traveo-t2g-cyt4bf-series/).

## Document history


 Version | Description of change
 ------- | ---------------------
 1.0.0   | New code example
<br />

---------------------------------------------------------

© Cypress Semiconductor Corporation, 2020-2022. This document is the property of Cypress Semiconductor Corporation, an Infineon Technologies company, and its affiliates ("Cypress").  This document, including any software or firmware included or referenced in this document ("Software"), is owned by Cypress under the intellectual property laws and treaties of the United States and other countries worldwide.  Cypress reserves all rights under such laws and treaties and does not, except as specifically stated in this paragraph, grant any license under its patents, copyrights, trademarks, or other intellectual property rights.  If the Software is not accompanied by a license agreement and you do not otherwise have a written agreement with Cypress governing the use of the Software, then Cypress hereby grants you a personal, non-exclusive, nontransferable license (without the right to sublicense) (1) under its copyright rights in the Software (a) for Software provided in source code form, to modify and reproduce the Software solely for use with Cypress hardware products, only internally within your organization, and (b) to distribute the Software in binary code form externally to end users (either directly or indirectly through resellers and distributors), solely for use on Cypress hardware product units, and (2) under those claims of Cypress’s patents that are infringed by the Software (as provided by Cypress, unmodified) to make, use, distribute, and import the Software solely for use with Cypress hardware products.  Any other use, reproduction, modification, translation, or compilation of the Software is prohibited.
<br />
TO THE EXTENT PERMITTED BY APPLICABLE LAW, CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH REGARD TO THIS DOCUMENT OR ANY SOFTWARE OR ACCOMPANYING HARDWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  No computing device can be absolutely secure.  Therefore, despite security measures implemented in Cypress hardware or software products, Cypress shall have no liability arising out of any security breach, such as unauthorized access to or use of a Cypress product. CYPRESS DOES NOT REPRESENT, WARRANT, OR GUARANTEE THAT CYPRESS PRODUCTS, OR SYSTEMS CREATED USING CYPRESS PRODUCTS, WILL BE FREE FROM CORRUPTION, ATTACK, VIRUSES, INTERFERENCE, HACKING, DATA LOSS OR THEFT, OR OTHER SECURITY INTRUSION (collectively, "Security Breach").  Cypress disclaims any liability relating to any Security Breach, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any Security Breach.  In addition, the products described in these materials may contain design defects or errors known as errata which may cause the product to deviate from published specifications. To the extent permitted by applicable law, Cypress reserves the right to make changes to this document without further notice. Cypress does not assume any liability arising out of the application or use of any product or circuit described in this document. Any information provided in this document, including any sample design information or programming code, is provided only for reference purposes.  It is the responsibility of the user of this document to properly design, program, and test the functionality and safety of any application made of this information and any resulting product.  "High-Risk Device" means any device or system whose failure could cause personal injury, death, or property damage.  Examples of High-Risk Devices are weapons, nuclear installations, surgical implants, and other medical devices.  "Critical Component" means any component of a High-Risk Device whose failure to perform can be reasonably expected to cause, directly or indirectly, the failure of the High-Risk Device, or to affect its safety or effectiveness.  Cypress is not liable, in whole or in part, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any use of a Cypress product as a Critical Component in a High-Risk Device. You shall indemnify and hold Cypress, including its affiliates, and its directors, officers, employees, agents, distributors, and assigns harmless from and against all claims, costs, damages, and expenses, arising out of any claim, including claims for product liability, personal injury or death, or property damage arising from any use of a Cypress product as a Critical Component in a High-Risk Device. Cypress products are not intended or authorized for use as a Critical Component in any High-Risk Device except to the limited extent that (i) Cypress’s published data sheet for the product explicitly states Cypress has qualified the product for use in a specific High-Risk Device, or (ii) Cypress has given you advance written authorization to use the product as a Critical Component in the specific High-Risk Device and you have signed a separate indemnification agreement.
<br />
Cypress, the Cypress logo, and combinations thereof, WICED, ModusToolbox, PSoC, CapSense, EZ-USB, F-RAM, and Traveo are trademarks or registered trademarks of Cypress or a subsidiary of Cypress in the United States or in other countries. For a more complete list of Cypress trademarks, visit cypress.com. Other names and brands may be claimed as property of their respective owners.
