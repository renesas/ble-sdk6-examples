# Hibernation and State aware hibernation

## Example description

The DA1453x supports a number of lower power modes; sleep, extended sleep, deep sleep and hibernate. Hibernate mode provides the lowest power operation as no internal clocks are running and the RAM is not retained (although there is an option to retain it if required).

The DA1453x contains a Clockless Wakeup Controller which allows the device to be woken from hibernate mode by a change of state on a GPIO. The following section details how to use the driver provided within SDK6 to put the DA14531 into Hibernate mode and how to handle wakeup events.

See the [DA14531 Datasheet](https://www.renesas.com/us/en/document/dst/da14531-datasheet?r=1564826) or [DA14535 Datasheet](https://www.renesas.com/us/en/document/dst/da14535-datasheet?r=25467666) for a complete description of the Clockless Wakeup Controller and all of the available sleep modes.

- Devices naming:
    - DA1453x is refering to DA14531-00, DA14531-01, DA14530 and DA14535.
    - The DA14531-00 is the main DA14531 device. The -00 is just a new naming to introduce the variant DA14531-01. The DA14531-01 is a ROM variant of the main DA14531-00.
    - The DA14535 is a DA14531 upgrade.
	- The DA14533 is optimized for automotive and industrial applications at higher temperatures, and it is rated as operating up to 105 ºC and compliant with the AEC-Q100 (Grade 2) standard.

- This project starts with undirected connectable advertising

- In between 2 advertising events extended sleep is applied

- There is a maximum advertising period set

- After the maximum advertising period is over, the device enters hibernation/state-aware hibernation mode

- P0_5 (J1 rail in DK Pro motherboard) is connected with P2_5 on J2 rail by using a GPIO breakout of the DK Pro motherboard. It is used to wake up the device from hibernation. 

  Either use a fly-wire from P0_5 to a ground GPIO to create a button press event; or;

  Set a jumper in P0_5 in J1 rail and connect an end of a button at P2_5 and the other end to the ground (GND) to use a button to generate the button press event.

- With respect to the state-aware hibernation, after the device enters the hibernation mode as explained above, external event via GPIO P0_5 (P2_5 on the motherboard) wakes up the device and DA14531 continues execution of application code from where it left before entering hibernation.

Note:
- On wake-up from the hibernation mode, the memory address 0x00 can be remapped either to OTP or ROM when using Flash memory or SysRAM depending on how the device is configured and programmed to handle hibernation wake-up mechanism. 

The expected result of the example can be verified by:
- Connecting the motherboard to the desktop/laptop and observing the power profile in SmartSnippets Studio.


## HW and SW configuration

This example runs on the BLE Smart SoC (System on Chip) devices:
- DA14531 daughter board or DA14531 Tiny Module + DA145xxDEVKT-P PRO-Motherboard.

The user manuals for the development kits can be found:
- [DA14531-00FXDEVKT-P](https://www.renesas.com/us/en/products/wireless-connectivity/bluetooth-low-energy/da14531-00fxdevkt-p-smartbond-tiny-da14531-bluetooth-low-energy-51-system-chip-development-kit-pro) for the DA145xxDEVKT-P PRO-Motherboard.

- [DA14531MOD-00DEVKT-P](https://www.renesas.com/us/en/products/wireless-connectivity/bluetooth-low-energy/da14531mod-00devkt-p-smartbond-tiny-da14531-bluetooth-low-energy-51-system-chip-module-development-kit-pro) for the DA14531 Tiny Module getting started

To run the program from flash or OTP, please visit Programmer operations chapter of the [SmartSnippets Toolbox User Manual](https://lpccs-docs.renesas.com/UM-B-083/index.html)

* **General Hardware configuration DA14531 using DA145xxDEVKT-P PRO-Motherboard**

	- The general hardware configuration remains the same for the 3 use-cases here. Only for the SPI Flash use-case (not for module) we need additional jumper settings.
	- Connect the DA145xxDEVKT-P PRO-Motherboard to the working station through USB1 connector. 

	![Motherboard_Hardware_Configuration_DA14531](assets/jtag.svg)

    - This example works also on the [DA1453x DEVKT-P](https://www.renesas.com/us/en/products/wireless-connectivity/bluetooth-low-energy/da14535-00fxdevkt-p-smartbond-tiny-da14535-bluetooth-low-energy-53-soc-development-kit-pro) with with any DA1453x Daughterboard
	![Motherboard_Hardware_Configuration_DA14531](assets/da14535.svg)	
	
* **Software configuration**

	- SmartSnippets Toolbox v5.0.26
	- [SDK6 latest version](https://www.renesas.com/sdk6_latest)
	- Keil5
	- SEGGER’s J-Link tools should be downloaded and installed.

# Using e² studio with LLVM

Setup for e² studio

#. Switching to e² studio: Instead of using Keil, you can use e² studio with LLVM as the compiler toolchain. Make sure your project is configured for LLVM by selecting the appropriate toolchain in e² studio.


#. Compile and Build: Open your project in e² studio and compile using LLVM. Ensure your environment variables and paths are properly set for the Renesas toolchain.

#. Run and Debug: Connect your device, set the proper debug configuration in e² studio, and start debugging using J-Link.


By switching to e² studio and LLVM, you can take advantage of advanced debugging tools and an open-source toolchain, while maintaining full compatibility with Renesas DA145xx devices.

For detailed steps on using e² studio, refer to the Renesas e² studio User Guide available on the [Renesas website](https://lpccs-docs.renesas.com/e2_studio_sdk6_getting_started/index.html).


## How to run the example

### Setup
1. Start Keil using the `hibernation_example.uvprojx` Keil project file.

2. Expand the dialog shown in the red box in the image below.

	![Expand_Select_Device](assets/keil_531.png)


3. Select the device: DA14531 or DA14535

4. Compile (F7) the program

5. Open the user_hibernation.h and declare the following function,

	``` C
		void user_app_on_init(void);
	```
	
6. Open the user_hibernation.c and add the function, like so, 

	``` C
		void user_app_on_init(void)
		{
			spi_flash_power_down();
			
			default_app_on_init();
		}
	```
	![user_app_on_init function](assets/userinit.png)	

7. Open the user_callback_config.h, and replace the default_app_on_init with user_app_on_init, like so, 

	``` C
		.app_on_init            = user_app_on_init,
	```
	![callback function](assets/callback.png)
	
8. Save and compile 

Now we can start implementing the use-cases. 

## Use-case 1 - Hibernation Mode

To demonstrate the hibernation example there are three use-cases that depends on selecting the source of booting of a firmware either from:
1. SPI Flash (address 0 remap to ROM) OR
2. OTP (address 0 remap to OTP) OR 
3. SysRAM (address 0 remap to SysRAM1)

### Using SPI Flash 

To enter the hibernation after booting from SPI Flash, the following software modification needs to be done. 

1. In Keil, Project explorer, open the *user_hibernation.h*

2. In the defines, define CFG_APP_GOTO_HIBERNATION to select the hibernation sleep mode and also define HIBERNATION_SPI and undefine the others,

	``` C
	#if defined (__DA14531__)
		#define CFG_APP_GOTO_HIBERNATION
		
		#define HIBERNATION_SPI
		#undef HIBERNATION_OTP
		#undef HIBERNATION_SYSRAM
	```

3. In the Hibernation mode configuration, this selection switches off all the three RAM blocks and remap the address 0 to ROM as shown below, 

	![HIBERNATION_SPI](assets/cfg_hibernation_spi.png)
	
4. In *user_periph_setup.h* file configure the GPIO that would be used to wake-up the device from hibernation mode. In our case we have chosen P0_5 as the wake-up GPIO. 

	``` C
	/****************************************************************************************/
	/* Wake-up from hibernation configuration                                               */
	/****************************************************************************************/
	#if defined (__DA14531__) 
		#define HIB_WAKE_UP_PORT        GPIO_PORT_0
		#define HIB_WAKE_UP_PIN         GPIO_PIN_5
		#define HIB_WAKE_UP_PIN_MASK    (1 << HIB_WAKE_UP_PIN)
	#endif
	```

5. Specify the advertisement period in the *user_config* file,  

  ``` C
  /*
   ****************************************************************************************
   *
   * Default handlers configuration (applies only for @app_default_handlers.c)
   *
   ****************************************************************************************
   */
  static const struct default_handlers_configuration  user_default_hnd_conf = {
  	// Configure the advertise operation used by the default handlers
  	// Possible values:
  	//  - DEF_ADV_FOREVER
  	//  - DEF_ADV_WITH_TIMEOUT
  	.adv_scenario = DEF_ADV_WITH_TIMEOUT,
  
  	// Configure the advertise period in case of DEF_ADV_WITH_TIMEOUT.
  	// It is measured in timer units. Use MS_TO_TIMERUNITS macro to convert
  	// from milliseconds (ms) to timer units.
  	.advertise_period = MS_TO_TIMERUNITS(18000), //this is for 30s
  
  	// Configure the security start operation of the default handlers
  	// if the security is enabled (CFG_APP_SECURITY)
  	// Possible values:
  	//  - DEF_SEC_REQ_NEVER
  	//  - DEF_SEC_REQ_ON_CONNECT
  	.security_request_scenario = DEF_SEC_REQ_NEVER
  };
  
  ```

  This will configure the advertising period as 18s after which the device will enter the hibernation mode. To wake-up from hibernation use the P0_5 which was configured before as wake-up GPIO.

  **Note:**

  P0_5 (J1 rail in DK Pro motherboard) is connected with P2_5 on J2 rail by using a GPIO breakout of the DK Pro motherboard. It is used to wake up the device from hibernation. 

  Either use a fly-wire from P0_5 to a ground GPIO to create a button press event; or;

  Set a jumper in P0_5 in J1 rail and connect an end of a button at P2_5 and the other end to the ground (GND) to use a button to generate the button press event.

  

6. Save all the changes done in the project and Compile (F7).

7. Program the DA14531 using the compiled hex file and boot from flash. To do this, please refer to Flash Programmer section in the [SmartSnippets Toolbox User Manual](https://lpccs-docs.renesas.com/UM-B-083/programmer_oper/index.html ).
	
	![SPI Jtag jumper settings](assets/spi.svg)

### Using OTP 

The process is the same as using SPI as we have seen in the previous section, except we define the HIBERNATION_OTP and undefine the rest, 

``` C
#if defined (__DA14531__)
	#define CFG_APP_GOTO_HIBERNATION
	
	#undef HIBERNATION_SPI
	#define HIBERNATION_OTP
	#undef HIBERNATION_SYSRAM
```

This would define the configuration of Hibernation mode to remap the address 0 to ROM while booting. 

![HIBERNATION_OTP](assets/cfg_hibernation_otp.png)

After doing this, repeat the steps from 4 - 7. In order to program the OTP and boot from OTP, please refer to chapter 12 OTP programmer in the [SmartSnippets Toolbox User Manual](http://lpccs-docs.dialog-semiconductor.com/SmartSnippetsToolbox5.0.8_UM/index.html ).


### Using SysRAM1

The process is the same as mentioned in previous section, again, except we define the HIBERNATION_SYSRAM and undefine the rest, 

``` C
#if defined (__DA14531__)
	#define CFG_APP_GOTO_HIBERNATION
	
	#undef HIBERNATION_SPI
	#undef HIBERNATION_OTP
	#define HIBERNATION_SYSRAM
```

This would define the configuration of Hibernation mode to remap the address 0 to SysRAM1 while booting. Also since we are running it from SysRAM we need to retain the retention memory blocks. 

![HIBERNATION_SYSRAM1](assets/cfg_hibernation_sysram.png)

After doing this, repeat the steps from 4 - 7. In order to program the OTP and boot from OTP, please refer to chapter 8 Booter in the [SmartSnippets Toolbox User Manual](https://lpccs-docs.renesas.com/UM-B-083/index.html).


## Use-case 2

To demonstrate the state-aware hibernation example, the following software modification needs to be done. 

1. In Keil, Project explorer, open the *user_hibernation.h*

2. In the defines, define CFG_APP_GOTO_STATEFUL_HIBERNATION to select the state aware hibernation mode and undefine CFG_APP_GOTO_HIBERNATION,

	``` C
	#if defined (__DA14531__)	
		#undef CFG_APP_GOTO_HIBERNATION
		#define CFG_APP_GOTO_STATEFUL_HIBERNATION
	```

3. Additionally, CFG_STATEFUL_HIBERNATION shall be defined (in Options for Target 'DA14531' --> Asm --> Conditional Assembly Control Symbols --> Define) 

	![Keil state-aware define](assets/keil_state.png)


4. In the state aware hibernation mode configuration, this selection switches off all the three RAM blocks and remap the address 0 to ROM as shown below, 

	![HIBERNATION_SPI](assets/cfg_hibernation_spi.png)

5. In *user_periph_setup.h* file configure the GPIO that would be used to wake-up the device from hibernation mode. In our case we have chosen P0_5 as the wake-up GPIO. 

	``` C
	/****************************************************************************************/
	/* Wake-up from hibernation configuration                                               */
	/****************************************************************************************/
	#if defined (__DA14531__) 
		#define HIB_WAKE_UP_PORT        GPIO_PORT_0
		#define HIB_WAKE_UP_PIN         GPIO_PIN_5
		#define HIB_WAKE_UP_PIN_MASK    (1 << HIB_WAKE_UP_PIN)
	#endif
	```

6. Specify the advertisement period in the *user_config* file,  

  ``` C
  /*
   ****************************************************************************************
   *
   * Default handlers configuration (applies only for @app_default_handlers.c)
   *
   ****************************************************************************************
   */
  static const struct default_handlers_configuration  user_default_hnd_conf = {
  	// Configure the advertise operation used by the default handlers
  	// Possible values:
  	//  - DEF_ADV_FOREVER
  	//  - DEF_ADV_WITH_TIMEOUT
  	.adv_scenario = DEF_ADV_WITH_TIMEOUT,
  
  	// Configure the advertise period in case of DEF_ADV_WITH_TIMEOUT.
  	// It is measured in timer units. Use MS_TO_TIMERUNITS macro to convert
  	// from milliseconds (ms) to timer units.
  	.advertise_period = MS_TO_TIMERUNITS(18000), //this is for 30s
  
  	// Configure the security start operation of the default handlers
  	// if the security is enabled (CFG_APP_SECURITY)
  	// Possible values:
  	//  - DEF_SEC_REQ_NEVER
  	//  - DEF_SEC_REQ_ON_CONNECT
  	.security_request_scenario = DEF_SEC_REQ_NEVER
  };
  
  ```

  This will configure the advertising period as 18s after which the device will enter the hibernation mode. To wake-up from hibernation use the P0_5 which was configured before as wake-up GPIO.

  **Note:**

  P0_5 (J1 rail in DK Pro motherboard) is connected with P2_5 on J2 rail by using a GPIO breakout of the DK Pro motherboard. It is used to wake up the device from hibernation. 

  Either use a fly-wire from P0_5 to a ground GPIO to create a button press event; or;

  Set a jumper in P0_5 in J1 rail and connect an end of a button at P2_5 and the other end to the ground (GND) to use a button to generate the button press event.

7. Save all the changes done in the project and Compile (F7).

8. Connect P23 (on J2 header of the motherboard) to V3 (J2 header of the motherboard) using a fly-wire. 

9. Run the code from either Keil (RAM) or from SPI flash, the device will start advertising for the selected duration (step 5) and then enter state-aware hibernation mode.

10. Move the fly-wire from V3 to Ground, the device will wake up and the LED D5 (LED D2 on the module) will turn on for a second or two and get turned off. 
	Both the processor state and system register content will be restored – code execution will resume from the point the device went to stateful hibernation.

11. It will enter extended sleep mode (as configured) and will wait for interrupt to occur (button press on SW2 of the motherboard) and it will advertise for the advertisement period set, and will go back to state aware hibernation mode. 

## Expected Result

### DA14531 with DA145xxDEVKT-P PRO-Motherboard
1. Open the Power Profiler in the SmartSnippets Toolbox. please refer to chapter 6.2 Power Profiler in the [SmartSnippets Toolbox User Manual](https://lpccs-docs.renesas.com/UM-B-083/monitor_oper/power_profiler/power_profiler.html). 

2. After running the program either from SysRAM, Flash or OTP, the device advertises for 30s and enters the hibernation mode. On wake-up (using the P0_5) the device advertises again. 

	![HIBERNATION_powerprofiler](assets/hibernation_powerprofiler.png)

3. End of example.		

## Further reading

- [Wireless Connectivity Forum](https://lpccs-docs.renesas.com/lpc_docs_index/DA145xx.html)


## Known Limitations

- There are no known limitations for this example. But you can check and refer to the following application note for
[SDK6 known limitations](https://lpccs-docs.renesas.com/sdk6_kll/index.html)

## Feedback and support ?

If you have any comments or suggestions about this document, you can contact us through:

- [Wireless Connectivity Forum](https://community.renesas.com/wireles-connectivity)

- [Contact Technical Support](https://www.renesas.com/eu/en/support?nid=1564826&issue_type=technical)

- [Contact a Sales Representative](https://www.renesas.com/eu/en/buy-sample/locations)