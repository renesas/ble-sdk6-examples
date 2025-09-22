---
name: multi_con_periph
module: connectivity
boards: [da14531_pro, da14585_pro]
keywords:
    - Central 
    - peripheral
    - connection
description: |
    This example demonstrates how a single peripheral can be connected to more
    than one central.
---

# Multi-peripheral Example

## Example description

This example demonstrates how a single peripheral can be connected to more than one central. DA1453x is able to support up to 3 connections and the DA1458x up to 8 simultaneous connections. Additionally it also demonstrates how one could keep different characteristic values depending on different connections.

The demo will start advertising and will store the 3 first connections from different centrals in a user space variable. In case an extra central tries to connect, the demo will overwrite an inactive connection entry if available, else if there is no available connection slot no connection will be established. Application will also retain the values of the connection orientated characteristics and make sure to report the proper value only to the requesting central.  

The demonstration exposes a custom profile including 3 services.

- Service 1: Includes some of the standard characteristics and functionality of the default custom profile. This database is common to all connected peripherals, hence data values are common to any device is connected.
- Service 2: Includes one characteristic with read and write properties. This is a connection oriented characteristic, hence the device will only report the values that correspond to the requesting central.
- Service 3: Include one characteristic with read properties. This is a connection oriented characteristic, hence the device will only report the values that correspond to the requesting central.

- Devices naming:
    - DA1453x is refering to DA14531-00, DA14531-01, DA14530 and DA14535.
    - DA1458x is refering to DA14585 and DA14586.
    - The DA14531-00 is the main DA14531 device. The -00 is just a new naming to introduce the variant DA14531-01. The DA14531-01 is a ROM variant of the main DA14531-00.
    - The DA14535 is a DA14531 upgrade.
	- The DA14533 is optimized for automotive and industrial applications at higher temperatures, and it is rated as operating up to 105 ºC and compliant with the AEC-Q100 (Grade 2) standard.

## HW and SW configuration

### Hardware configuration

This example runs on The BLE Smart SoC (System on Chip) devices.

- DA14585/DA14586 Daughter board + DA145xxDEVKT-P PRO Motherboard
- DA14531 Daughter board + DA145xxDEVKT-P PRO Motherboard

For running the example on a DA14585/DA14586 Daughter board + DA145xxDEVKT-P PRO Motherboard the following configuration is required.

- Connect the DA145xx Pro Development Kit to the host computer.
- UART TX on P0_4 for DA14585/DA14586 (place jumper between J1:17 and J1:18) for printing functionality.
![DA14585_connection_wires](assets/da14585_pro.svg)

For running the example on a DA14531 Daughter board + DA145xxDEVKT-P PRO Motherboard the following configuration is required.

- Connect the DA145xx Pro Development Kit to the host computer.
- UART TX on P0_8 for DA14531 (Place wire between J1:17 and J2:27) for printing functionality.
![DA14531_connection_wires](assets/da14531_connection.svg)

### Software configuration

This example requires:

- SmartSnippets Toolbox 5.0.26.
- [SDK6 latest version](https://www.renesas.com/sdk6_latest).
- **SEGGER’s J-Link** tools should be downloaded and installed.
- **A simple serial terminal** should be installed on the PC (e.g. Putty or Teraterm)

## How to run the example

For the initial setup of the project that involves linking the SDK to this SW example, please follow the Readme [here](../../Readme.md).

### Initial Setup

- Compile and launch the example.
- Open the development kit serial port with the following parameters.

  - baud-rate: 115200
  - data: 8 bits
  - stop: 1 bit
  - parity: None
  - flow  control: none

- As soon as the example runs the following message should appear on the terminal
  indicating that the device is advertising and there are no currently connected devices.

  ![Advertising_device](assets/Advertising_device.png)

- As soon as the device advertises, one could connect the first central. The following message will be printed
  on the terminal indicating the amount of centrals connected to the peripheral as well as their bd addresses. In every new connection all the bd addresses of the currently connected devices will be printed out.

  ![one_connected_device](assets/one_connected_device.png)

  ![two_connected_device](assets/two_connected_device.png)

- The example includes 2 services where the read and write data are connection dependent. The values of each
  characteristic are not stored in the peripheral's database but in application variables. Each time a read or a write is performed the values of each connection and characteristic is printed out on the terminal.

  ![reporting_con_db_val](assets/reporting_con_db_val.png)

- In every disconnection the currently disconnected device will be printed out along with the disconnection
  reason.

  ![device_disconnection](assets/device_disconnection.png)

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

