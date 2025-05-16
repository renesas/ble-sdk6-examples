# DA1453x/58x Multirole Example

## Example Description

The example demonstrates the capabilities of the DA1453x/58x as a Central and a peripheral i.e. scan and advertise role. 

**Note**: This example applies for DA1458x as well. The DA1453x is capable of handling up to 3 connections and the DA1458x can handle up to 8 connections.

The project works as a Central connecting to 2 peripherals, and once connected, it advertises so another central can connect to it.

**Note**: This project assumes that the 2 peripherals will stay connected to the DA14531 central. 

- Devices naming:
    - DA1453x is refering to DA14531-00, DA14531-01, DA14530 and DA14535.
    - DA1458x is refering to DA14585 and DA14586.
    - The DA14531-00 is the main DA14531 device. The -00 is just a new naming to introduce the variant DA14531-01. The DA14531-01 is a ROM variant of the main DA14531-00.
    - The DA14535 is a DA14531 upgrade.
	- The DA14533 is optimized for automotive and industrial applications at higher temperatures, and it is rated as operating up to 105 ºC and compliant with the AEC-Q100 (Grade 2) standard.

## HW setup
 - 3 DA1453x Pro-DK kit with Module/Daugherboard connected to host computer via USB and an android or iPhone.
 - For Central, extra jumpers are required for the UART to see the communication logs. Check the setup shown below for DA14531 and DA14585/586.
 
 <ins>DA14531 daughterboard</ins>
 
 ![da14531.jpg](assets/da14531.svg)
 

  <ins>DA14535 daughterboard</ins>
 
 ![da14535.jpg](assets/da14535_535dau.svg)

  <ins>DA14531 module</ins>
  
 ![module.jpg](assets/module.svg)
 
 <ins>DA14585 daughterboard</ins>
 
 ![da14585.jpg](assets/da14585.svg)
 
 
 The user manuals for the development kits can be found [here](https://www.renesas.com/eu/en/document/mat/um-b-117-da14531-getting-started-pro-development-kit-html-chinese?r=1564826) for the DA145xxDEVKT-P PRO-Motherboard.

## SW setup 

 - [SDK6 latest version](https://www.renesas.com/sdk6_latest)
 - SmartSnippets Toolbox 5.0.26 
 - a terminal for UART logs (teraterm, termite, etc..)
 
## How to run the example

1/ For the initial setup of the project that involves linking the SDK to this SW example, please follow this: https://github.com/renesas/ble-sdk6-examples/blob/main/Readme.md.

    - For the DA14531 getting started guide you can refer to [UM-B-117](https://lpccs-docs.renesas.com/UM-B-117-DA14531-Getting-Started-With-The-Pro-Development-Kit/index.html)

    - For the DA14535 getting started guide you can refer to this [UM-B-165](https://lpccs-docs.renesas.com/DA14535/UM-B-165-DA14531-Getting-Started-With-The-Pro-Development-Kit/index.html#device-family-getting-started-with-the-pro-development-kits)

    - For the DA14531 Module getting started guide you can refer to this [UM-B-139](https://lpccs-docs.renesas.com/UM-B-139-Getting-Started-with-DA14531-TINY-Module/index.html)

    - For the DA14533 getting started guide you can refer to this [R19US0026EE0100](https://lpccs-docs.renesas.com/da14533_getting_started_guide/index.html)


2. Download Prox_reporter binaries with **different BD addresses and default device name "DLG-PROXR"** to 2 DA14531 devices.
You can refer to this [document](https://lpccs-docs.renesas.com/UM-B-083/index.html) to program the flash with the prox_reporter binaries. Press reset (SW1) on the motherboard and verify with an Android device that they have all started advertising

Note: To configure your device with different BD addresses, follow [Advertising Tutorial](https://lpccs-docs.renesas.com/DA145xx_Advertising_Tutorial/index.html).

3. Using Keil IDE, open the multirole project and compile the project to build the indexes. 

4. Download the binary to another DA14531 device (Use flash programmer tool as mentioned in step 1). 

**Note**: Use any android/iPhone BLE scanner to connect/disconnect to/from the DA14531.

**Note: For the DA14585, using more than 4 active connections, the default value of the #define CFG_RET_DATA_SIZE 2048, needs to changed to 4096, in the user_config.h file.**


## Supported use-case for the example

Below mentioned is the use-case that is supported with this example. In future releases, more use-cases will be added especially with regards to the disconnections.

For the ease of understanding, following notations are used. 

* C0/P0 -> DA14531 central/peripheral
* P1,P2 -> DA14531 peripheral 
* C1 -> Phone central

**Use case:** The flow of this use-case is mentioned below. Basically the peripherals starts to advertise first and then the Central starts scan process, and it finds and connects to 2 peripherals. 

<ins>Connection<ins>
- P1 is advertising
- P2 is advertising
- C0 starts to scan, finds P1 and P2 and connects
- P0 advertises
- C1 connects to P0

<ins>Disconnection<ins>
- C1 disconnects
- P0 advertises
- C1 connects to P0 again

This can be verified in the UART logs.

**Note**: While using iPhone, if you wish to disconnect C1 from DA14531 device, please check the iPhone bluetooth settings as the phone might have to be disconnected from there. 
Once it disconnects, you will see P0 advertising again while being connected to P1 and P2. 
For Android, you can use any BLE scanner app to connect and disconnect.

**Note**: UART terminal: 921600, 8N1, no flow control

![logs.jpg](assets/logs.jpg)

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

