---
name: burst_adv
boards: [da14531, da14585]
keywords:
    - Burst advertising 
    - UART
description: |
    This is a simple example showing how to implement 'burst' advertising on
    the DA14531 and DA1458x devices
---

# DA1453x and DA1458x Burst Advertising with Bluetooth LE

## Example description

Simple example showing how to implement 'burst' advertising on the DA1453x and DA1458x devices. Burst 
advertising is the process of sending a number of advertising events and then having 
a delay before sending another group of advertising events. This example allows the 
user to configure the number of advertising events to be transmitted per burst and 
the time between bursts. 

- Devices naming:
    - DA1453x is refering to DA14531-00, DA14531-01, DA14530 and DA14535.
    - DA1458x is refering to DA14585 and DA14586.
    - The DA14531-00 is the main DA14531 device. The -00 is just a new naming to introduce the variant DA14531-01. The DA14531-01 is a ROM variant of the main DA14531-00.
    - The DA14535 is a DA14531 upgrade.
	- The DA14533 is optimized for automotive and industrial applications at higher temperatures, and it is rated as operating up to 105 ºC and compliant with the AEC-Q100 (Grade 2) standard.

## HW and SW configuration

- This example runs on the DA1453x (DA14531-00, DA14531-01 and DA14535) and DA14585/586 Bluetooth Smart SoC devices.
- The DA145xxDEVKT-P PRO-Motherboard with jumper setting for SPI flash programming. The user manuals for the development kits can be found [Here](https://www.renesas.com/us/en/products/wireless-connectivity/bluetooth-low-energy/da14531-00fxdevkt-p-smartbond-tiny-da14531-bluetooth-low-energy-51-system-chip-development-kit-pro) for the DA145xxDEVKT-P PRO-Motherboard.

- For the DA14531 getting started guide you can refer to [UM-B-117](https://lpccs-docs.renesas.com/UM-B-117-DA14531-Getting-Started-With-The-Pro-Development-Kit/index.html)

- For the DA14535 getting started guide you can refer to this [UM-B-165](https://lpccs-docs.renesas.com/DA14535/UM-B-165-DA14531-Getting-Started-With-The-Pro-Development-Kit/index.html#device-family-getting-started-with-the-pro-development-kits)

- For the DA14531 Module getting started guide you can refer to this [UM-B-139](https://lpccs-docs.renesas.com/UM-B-139-Getting-Started-with-DA14531-TINY-Module/index.html)
- For the DA14585/586 getting started guide you can refer to this [UM-B-049](https://lpccs-docs.renesas.com/da14585_getting_started/index.html).

For the UART to see the communication logs, check the setup shown below for DA14531 and DA14585/586

### Hardware configuration for the DA14531

![DA14531 Jumper setting](assets/da14531.svg)

### Hardware configuration for the DA14585/586

 
![DA14585 Jumper setting](assets/da14585.svg)

- This example works also on the DA1453x DEVKT-P with with any DA1453x Daughterboard and with the same UART connection.
	![Motherboard_Hardware_Configuration_DA14531](assets/da14535.svg)

## Software Configuration
- Download the [SDK6 latest version](https://www.renesas.com/sdk6_latest)
- Install SEGGER’s J-Link tools.
- If using e² studio with LLVM instead of Keil, ensure your project settings are adjusted accordingly (instructions below).

## Using e² studio with LLVM
Setup for e² studio

#. Switching to e² studio: Instead of using Keil, you can use e² studio with LLVM as the compiler toolchain. Make sure your project is configured for LLVM by selecting the appropriate toolchain in e² studio.


#. Compile and Build: Open your project in e² studio and compile using LLVM. Ensure your environment variables and paths are properly set for the Renesas toolchain.

#. Run and Debug: Connect your device, set the proper debug configuration in e² studio, and start debugging using J-Link.


By switching to e² studio and LLVM, you can take advantage of advanced debugging tools and an open-source toolchain, while maintaining full compatibility with Renesas DA145xx devices.

For detailed steps on using e² studio, refer to the Renesas e² studio User Guide available on the [Renesas website](https://lpccs-docs.renesas.com/e2_studio_sdk6_getting_started/index.html).

## How to run the example

For the initial setup of the project that involves linking the SDK to this SW example, please follow the Readme [here](../../Readme.md).

### Initial Setup

1.  Build and download the example using the Keil IDE. 
2.  Run the example using the Keil debugger.
3.  Observe bursts of advertising events using Power Profiler found within the SmartSnippets Toolbox, monitor UART debug output using a terminal such as Teraterm etc as following:
		   
  		    - baudrate: 115200
		    - data: 8 bits
		    - stop: 1 bit
		    - parity: None
		    - flow control: none
				
4. Undirected connecatable advertising is used for this demonstration. Monitor transmitted advertising events using a Smart Phone App such as LightBlue.

The device should display the advertising data as shown in the picture below:

![Output](assets/output.jpg)
![print](assets/print.jpg)

## Note
This example can be built by e2studio and LLVM compiler instead of using Keil.

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

