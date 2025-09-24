---
name: L2CAP
boards: [da14531, da14585]
keywords:
    - L2CAP
    - DLE
    - throughput
description: |
    This project is intended to illustrate to the user how to do a peer feature
    request for determining peer DLE capability and how to request DLE and
    utilize larger packets to enhance throughput
---

# DA1458x/DA1453x DLE and L2CAP Packet Optimization

## Example description

This project is intended to illustrate to the user:
- How to do a peer feature request for determining peer DLE capability
- How to request DLE and utilize larger packets to enhance throughput
- Basic principles of L2CAP 100% packet utilization
- Packet optimization for non DLE devices

This functionality can be verified by:
- Using a BLE handset
- Reading serial output from the device.

Devices naming:

- DA1453x is refering to DA14531-00, DA14531-01, DA14530 and DA14535.
- DA1458x is refering to DA14585 and DA14586.
- The DA14531-00 is the main DA14531 device.
-  The -00 is just a new naming to introduce the variant DA14531-01. 
- The DA14531-01 is a ROM variant of the main DA14531-00, not supported by this example.
- The DA14535 is a DA14531 upgrade.		

## HW and SW configuration
This example runs on the BLE Smart SoC (System on Chip) devices:
- DA1458x or DA1453x daughter board + DA14531 or 53x DEVKT-P PRO-Motherboard.
- DA14585/DA14586 Basic development Kit.
- DA14531 USB Kit

The user manuals for the development kits can be found:

- For the DA14531 getting started guide you can refer to [UM-B-117](https://lpccs-docs.renesas.com/UM-B-117-DA14531-Getting-Started-With-The-Pro-Development-Kit/index.html)
- For the DA14535 getting started guide you can refer to this [UM-B-165](https://lpccs-docs.renesas.com/DA14535/UM-B-165-DA14531-Getting-Started-With-The-Pro-Development-Kit/index.html#device-family-getting-started-with-the-pro-development-kits)
- For the DA14531 Module getting started guide you can refer to this [UM-B-139](https://lpccs-docs.renesas.com/UM-B-139-Getting-Started-with-DA14531-TINY-Module/index.html)
- For the DA14585/586 getting started guide you can refer to this [UM-B-049](https://lpccs-docs.renesas.com/da14585_getting_started/index.html).

* **Hardware configuration DA14585 using the DA145xxDEVKT-P PRO-Motherboard**

	- When using DA14585/DA14586, Jumper P0_6 from J2 to UTX (Pin 17 on J1).
	
	![da14585.jpg](assets/da14585.svg).
	
	- When using DA1453x, Jumper P2_6 from J2 to UTX (Pin 17 on J1) for serial UART communication.
	
	![da14531.jpg](assets/da14531.svg).
	
    - When using DA14531 USB development kit no hardware configurationis needed. You need only to Redefine the UART2_TX_PIN to GPIO_PIN_4 (1 wire UART ) 
	  
	  **#define UART2_TX_PIN            GPIO_PIN_4**

	![da14531_usb.png](assets/da14531_usb.svg).
	
* **Software configuration**

	- This example requires:
    * [SDK6 latest version](https://www.renesas.com/sdk6_latest)
	- **SEGGER’s J-Link** tools should be downloaded and installed.
	- If using e² studio with LLVM instead of Keil, ensure your project settings are adjusted accordingly (instructions below).

## Using e² studio with LLVM

**Setup for e² studio**

Switching to e² studio: Instead of using Keil, you can use e² studio with LLVM as the compiler toolchain. Make sure your project is configured for LLVM by selecting the appropriate toolchain in e² studio.

Modify Linker Script (.lds): When using e² studio, you will need to modify the .lds linker script to ensure proper memory allocation for DA14531 devices. You can locate the linker script in the project folder and adjust the memory sections if required.

Compile and Build: Open your project in e² studio and compile using LLVM. Ensure your environment variables and paths are properly set for the Renesas toolchain.

Run and Debug: Connect your device, set the proper debug configuration in e² studio, and start debugging using J-Link.


By switching to e² studio and LLVM, you can take advantage of advanced debugging tools and an open-source toolchain, while maintaining full compatibility with Renesas DA145xx devices.
For detailed steps on using e² studio, refer to the Renesas e² studio User Guide available on the [Renesas website](https://lpccs-docs.renesas.com/e2_studio_sdk6_getting_started/index.html).


## How to run the example

### Setup

For the initial setup of the project that involves linking the SDK to this SW example, please follow the Readme [here](https://github.com/dialog-semiconductor/BLE_SDK6_examples).

-Start Keil using the `tput_optimization.uvprojx` Keil project file.

2. Expand the dialog shown in the red box in the image below.
	
	![Expand_Select_Device](assets/Expand_Select_Device.png)

3. Select your target device: DA14531, DA14585, DA14586

4. Open your favorite serial terminal application, e.g. TeraTerm, RealTerm, Putty - use 115200, 8, N, 1 as your settings.

5. Compile (F7) and launch (ctrl + F5) the example.\
If the warning (shown below) pops up press OK.

### Running the Example

1. Open a BLE application on your handset and look for "DIALOG-TPUT"

2. Connect to the device.
	
	![Connect_Device](assets/Connect_Device.png)
	
3. Subscribe to notifications on the Log Transfer characteristic.
	
	![Log_Characteristic](assets/Log_Characteristic.png)

4. Write the value to 0xAA to the Control Point Characteristic. 
	
	![CP_Characteristic](assets/CP_Characteristic.png)

5. This will begin a log transfer of static bytes. 

6. Check your terminal for debug output and throughput calculation.
	
	![Terminal_Ouptut](assets/Terminal_Output.png)

## How it works
### General Logic

The example uses a successive approach for optimization throughput.  In the Link Layer, we are limited to two basic buffer sizes depending on
The support for DLE: 27, 251.  First, we do a peer feature request to see if DLE is supported - If supported, we utilize
the additional packet space.  From here, we do a connection parameter update, and following the result of this we do an MTU Exchange. 
The MTU exchange is intended to grant a larger payload for non-DLE devices and provide adequate buffer space for DLE devices.
Following the MTU exchange, the optimal packet size is determined.  We calculate the required overhead of the L2CAP and ATT and force
our payload then to utilize the the rest of the space.  For non-DLE devices that have MTUs greater than 104, we statically set the payloadsize to
101.  This number is has been emperically determined to provide good throughput in a noisier environment. Full packet utilization provides
a good enhancement on throughput if otherwised not considered. 

### Note

This example does not consider a more complex connection parameter scheme for throughput optimization.  This would be an exercise to the user.
Note that DSPS does include this functionality for reference and provides optimal connection parameters for DLE and non-DLE devices.

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
