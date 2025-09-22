---
name: active_scanner
module: connectivity
boards: [da14531_pro, da14585_pro]
keywords:
    - scanning mode
    - advertising data
    - UART
description: |
    This example shows how to setup the DA145xx device in active scanning mode,
    On advertising data report, the data is formatted and pushed on the UART
---

# DA1453x and DA14585/586 Active scanner

## Example description

The device is setup in active scanning mode. On advertising data report, the data is formatted and pushed on the UART. 
The user can read the peripheral advertising data in a friendly way on its serial terminal.

## HW and SW configuration

* **Hardware configuration**

    - This example runs on the DA14585, DA14586 and DA1453x Bluetooth Smart SoC devices.
    - DA14585/DA14586 or DA14531 daughter board + DA145xxDEVKT-P PRO-Motherboard are required.

* **Software configuration**

    - This example requires:
        * [SDK6 latest version](https://www.renesas.com/sdk6_latest).
        * SEGGER’s J-Link tools should be downloaded and installed.

## Note
This example can be built by e2studio and LLVM compiler instead of using Keil.

For the UART to see the communication logs, check the setup shown below for DA1453x and DA14585/586

# Hardware configuration for the DA14535:

![DA14535 Jumper setting](assets/da14535_535dau.svg)

# Hardware configuration for the DA14531:

![DA14531 Jumper setting](assets/da14531.svg)


# Hardware configuration for the DA14585/586:

 
![DA14585 Jumper setting  ](assets/da14585.svg )


The user manuals for the development kits can be found:

- [Here](http://lpccs-docs.renesas.com/UM-B-117-DA14531-Getting-Started-With-The-Pro-Development-Kit/02_Introduction/Introduction.html) for the DA145xxDEVKT-P PRO-Motherboard.

## Software Configuration
- Download the latest version of Renesas SDK6.
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

 - Start Keil
 - Compile and launch the example
 - Open the development kit serial port with the following parameters

		- baudrate: 115200
		- data: 8 bits
		- stop: 1 bit
		- parity: None
		- flow  control: none

The device should display the advertising data as shown in the picture below

![Scan_results](assets/active_scanner.png)



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


