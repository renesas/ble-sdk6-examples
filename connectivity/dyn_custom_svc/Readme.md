# DA14531/DA1458x Dynamic Custom Service

## Example description

The main purpose of this software example is to demonstrate creating a service dynamically using the Generic Transport Layer (GTL).

For more information about the GTL, please refer to the [GTL Manual](https://www.renesas.com/eu/en/document/swo/um-b-143-dialog-external-processor-interface-gtl-interface).

The service can be interrogated using a BLE scanning app. 

- Devices naming:
    - DA1453x is refering to DA14531-00, DA14531-01, DA14530, DA14533 and DA14535.
    - DA1458x is refering to DA14585 and DA14586.
    - The DA14531-00 is the main DA14531 device. The -00 is just a new naming to introduce the variant DA14531-01. The DA14531-01 is a ROM variant of the main DA14531-00.
    - The DA14535 is a DA14531 upgrade.
	- The DA14533 is optimized for automotive and industrial applications at higher temperatures, and it is rated as operating up to 105 ºC and compliant with the AEC-Q100 (Grade 2) standard.

## HW and SW configuration

- **Hardware configuration**
  - This example runs on the DA14531, DA1458x Bluetooth Smart SoC devices.
  - The DA1458x / DA14531 Pro Development kit is needed for this example with the jumper configuration depicted below ![Uart_Jumper](assets/uart_connection.svg)
  - DA1453x Pro Development kit is needed for this example with the jumper configuration depicted below ![Uart_Jumper](assets/uart_connection_535.svg)
  - Connect the USB Development kit to the host computer.
- **Software configuration**
  - [SDK6 latest version](https://www.renesas.com/sdk6_latest).
  - A smartphone with a BLE scanning app.
  - A terminal emulator (for example **Tera Term**)

## How to run the example

### Initial Setup

For the initial setup of the project that involves linking the SDK to this SW example, please follow the Readme [here](https://github.com/renesas/ble-sdk6-examples/blob/main/Readme.md).

- For the DA14531 getting started guide you can refer to [UM-B-117](https://lpccs-docs.renesas.com/UM-B-117-DA14531-Getting-Started-With-The-Pro-Development-Kit/index.html)
- For the DA14535 getting started guide you can refer to this [UM-B-165](https://lpccs-docs.renesas.com/DA14535/UM-B-165-DA14531-Getting-Started-With-The-Pro-Development-Kit/index.html#device-family-getting-started-with-the-pro-development-kits).
- For the DA14531 Module getting started guide you can refer to this [UM-B-139](https://lpccs-docs.renesas.com/UM-B-139-Getting-Started-with-DA14531-TINY-Module/index.html)
- For the DA14585/586 getting started guide you can refer to this [UM-B-049](https://lpccs-docs.renesas.com/da14585_getting_started/index.html).
- For the DA14533 getting started guide you can refer to this [R19US0026EE0100](https://lpccs-docs.renesas.com/da14533_getting_started_guide/index.html)


### Terminal Setup

- Launch terminal emulator with below serial port settings 

![teraterm_settings](assets/teraterm_settings.png)

### Compile & Run
- Navigate to ``project_environment`` folder and open the **Keil** project, dyn_custom_svc
- Select the target device you are building for, like so,

![Expand_Select_Device](assets/Expand_Select_Device.png)

- Compile (F7) and launch (ctrl + F5) the example.
- You can also download the firmware into SPI Flash. To download the firmware into SPI Flash, the  SPI Flash programmer from SmartSnippets Toolbox should be used as described 
  [here](http://lpccs-docs.dialog-semiconductor.com/UM-B-083/index.html), or the stand-alone flash programmer.

## How it works
- A custom service with 2 characteristics is created using the GTL. The first characteristic has read and write permissions. The second characteristic has write and notify permissions. The device can be interrogated using a BLE scanning app. Below shows the custom service with the 2 characteristics. 

![service_def1](assets/dyn_service_1_of_2.png)
![service_def2](assets/dyn_service_2_of_2_highlight.png)

 <br/><br/>
 
- Investigating the first characteristic, each time a read is performed a 4 byte random number is returned. The terminal prints the bytes sent in response to the read request which can be verified in the BLE scanning app.

![read_ex_1](assets/read_example_1_of_2.png)
![read_ex_2](assets/read_example_2_of_2.png)

 <br/><br/>

- Writing a value to the first characteristic, you can verifiy the data is received by the device and printed to the terminal.

![write_ex_2](assets/write_example_2_of_2.png)
![write_ex_1](assets/write_example_1_of_2.png)

 <br/><br/>

- To verify notifications on characteristic two, enable notifications.

![ntf_enable_1](assets/enable_ntf.png)

 <br/><br/>
- Once notifications are enabled, writing data to characteristic 1 will result in a notification on characteristic 2 with a 4 byte random number. 

![ntf_ex_1](assets/notification_example_1_of_2.png)
![ntf_ex_2](assets/notification_example_2_of_2.png)

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

