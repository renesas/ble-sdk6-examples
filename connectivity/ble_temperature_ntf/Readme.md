---
name: ble_temperature
boards: [da14531, da14585]
keywords:
    - MCP9808
    - Thermo 8 click board 
    - I2C
description: |
    This is Simple example showing how to interface the DA14585/586 and DA14531
    with the Thermo 8 click board™
---

# ble_temperature_ntf

## Example description

This example shows:
- How to use I2C to read MCP9808 temperature register.
- How to use I2C to write MCP9808 resolution register.
- This example uses the [Thermo 8 click board](https://www.mikroe.com/thermo-8-click) from Mikroe which is based on the MCP9808.
- How to measure the temperature using DA14531 internal temperature sensor.

**Note 1** 
The internal temperature sensor is not available for the DA1458x.

**Note 2** 
The functionality can be verified by BLE notifications.

- Devices naming:
    - DA1453x is refering to DA14531-00, DA14531-01, DA14530 and DA14535.
    - DA1458x is refering to DA14585 and DA14586.
    - The DA14531-00 is the main DA14531 device. The -00 is just a new naming to introduce the variant DA14531-01. The DA14531-01 is a ROM variant of the main DA14531-00.
    - The DA14535 is a DA14531 upgrade.
	- The DA14533 is optimized for automotive and industrial applications at higher temperatures, and it is rated as operating up to 105 ºC and compliant with the AEC-Q100 (Grade 2) standard.

## HW and SW configuration

This example runs on the BLE Smart SoC (System on Chip) devices:
- DA14585/DA14586 or DA14531 daughter board + DA145xxDEVKT-P PRO-Motherboard.
- DA14585/DA14586 daughter board + Basic development Kit mother board.

The user manuals for the development kits can be found:

- For the DA14531 getting started guide you can refer to [UM-B-117](https://lpccs-docs.renesas.com/UM-B-117-DA14531-Getting-Started-With-The-Pro-Development-Kit/index.html)

- For the DA14535 getting started guide you can refer to this [UM-B-165](https://lpccs-docs.renesas.com/DA14535/UM-B-165-DA14531-Getting-Started-With-The-Pro-Development-Kit/index.html#device-family-getting-started-with-the-pro-development-kits)

- For the DA14531 Module getting started guide you can refer to this [UM-B-139](https://lpccs-docs.renesas.com/UM-B-139-Getting-Started-with-DA14531-TINY-Module/index.html)

- For the DA14533 getting started guide you can refer to this [R19US0026EE0100](https://lpccs-docs.renesas.com/da14533_getting_started_guide/index.html)

__Hardware configuration DA14531 using DA145xxDEVKT-P PRO-Motherboard__
	
- Using thermo 8 click board.
	
Plug the thermo 8 click board on the mikrobus 2 interface (J17-J18). **Note that the JTAG/Debug interface will be no longer available** because the **P0_2** is shared between the **SWCLK** and the **I2C clock**.
This why we have opted to programme the onboard SPI flash with the generated binary and remove after that the JTAG debug Jumpers (J1:21-22 and J1:23-24). You can refer to the [section 16:SPI Flash Programmer](http://lpccs-docs.dialog-semiconductor.com/UM-B-083/tools/SPIFlashProgrammer.html) to see how to program the SPI flash with the Smarsnippets Toolbox.

Apply the jumper configuration of the image shown below.

![Motherboard_Hardware_Configuration_DA14531](assets/da14531_temp.svg)
![Motherboard_Hardware_Configuration_DA14531](assets/da14535_temp.svg)
	
if you would like to use the JTAG interface for debug purpose you have to choose different i2C GPIOs configurations. Be sure to update the `user_periph_setup.h` with the following configuration as an example:

	*#define MCP9808_SCL_PORT            GPIO_PORT_0
	*#define MCP9808_SCL_PIN	         GPIO_PIN_1
	*#define MCP9808_SDA_PORT            GPIO_PORT_0
	*#define MCP9808_SDA_PIN             GPIO_PIN_3
			
Then use jumpers wires to establish following connections between the DA145xxDEVKT-P PRO-Motherboard and the sensor click board:
 
	- Connect Vdd to V3 on J2.
	- Connect Gnd to ground on J2.
	- Connect SCL to P21 on J2.
	- Connect SDA to P23 on J2.

- Using internal sensor

Uncomment the CFG_USE_INTERNAL_TEMP_SENSOR definition (found in `da1458x_config_basic.h`) to acquire temperature via the internal temperature sensor. See line 205 in the image shown below.

![da1458x_config_basic_capture](assets/da1458x_config_basic_capture.png)


__Hardware configuration DA14585/DA14586 using DA145xxDEVKT-P PRO-Motherboard__

Plug the thermo 8 click board on the mikrobus 1 interface (J15-J16).	

![Motherboard_Hardware_Configuration_DA14585](assets/da14585_temp.svg)

__Hardware configuration DA14585 using the basic development kit__

	- Connect Vdd to V3 on J4 (brown line in the image below).
	- Connect Gnd to ground on J4 (blue line in the image below).
	- Connect SCL to P07 on J4 (yellow line in the image below).
	- Connect SDA to P04 on J4 (red line in the image below).		

![Hardware_Configurations](assets/basic.svg)

__Software configuration__

This example requires:

- The [SDK6 latest version](https://www.renesas.com/sdk6_latest)
- Keil5.
- __SEGGER’s J-Link__ tools should be downloaded and installed..


## How to run the example

### Setup

For the initial setup of the project that involves linking the SDK to this SW example, please follow the Readme [here](../../Readme.md).


Remember to download the binary of the application in to the Flash and then remove the Jtag pins.


## Expected Results

1. Open the BLE scanner app and look for "Temp_ntf".

2. Connect to the device.

3. Subscribe to the notifications.

If everything went well, you should be able to receive temperature data as the value of the custom characteristic, as shown in the image below.

__Note that the DA14531 internal temperature sensor uses int8_t instead of the double temperature value shown below__

![BLE_APP_MCP9808_CAPTURE](assets/BLE_APP_MCP9808_CAPTURE.png)


## How it works

Tutorial 3 on the [Dialog Semiconductor support](https://www.dialog-semiconductor.com/sites/default/files/training_03_custom_profile_gatt_cmd_example_v1.2.pdf) website shows how to make your own custom profile. The **user_catch_rest_hndl** function in `user_peripheral.c` will handle the messages for our custom profile. This application only has one possible 
custom action: a write to the notification. When this occurs the **user_temperature_message_handler** function is called. This function will check the contents of the write. If the content of the write equals zero, the temperature timer is canceled. If the value is 
anything else, a timer is generated that calls **user_send_temperature_ntf** after NOTIFICATION_DELAY ms. **user_send_temperature_ntf** will read out the sensor data and convert it to a string(for demo purposes). The string will be placed in a message, along with some other parameters, like the connection ID
and the characteristic handle. After the message is sent, the app_easy_timer function is used to schedule the next call to the **user_send_temperature_ntf** function. This will ensure the temperature is transmitted regularly. The `app_easy_timer`function
has a resolution of 10ms hence we divide the desired delay in ms by 10.

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

