# renesas_ble_abstraction_gtl_project

## Example description

This example updates the basic proximity monitor service demonstration from the standard SDK `6.0.24.1464\projects\target_apps\ble_examples\prox_reporter_ext`. It adds the Device Information Client service and uses the External Processor configuration with GTL, so the DA1453x PMOD can be driven by an external host MCU.

Two GTL transports are supported:

| Transport | Boot from host | Image location | Source provided |
|---|---|---|---|
| **UART** | Supported | Downloaded by the host at boot, or burned in flash | Yes |
| **SPI**  | **Not supported** | Must be burned in the DA14531 PMOD's SPI flash | No (see [GTL over SPI](#gtl-over-spi)) |

- Devices naming:
    - DA1453x refers to DA14530, DA14531-00, DA14531-01 and DA14535.
    - DA1458x refers to DA14585 and DA14586.
    - The DA14531-00 is the main DA14531 device. The `-00` is a new naming introduced alongside the DA14531-01 variant. The DA14531-01 is a ROM variant of the main DA14531-00.
    - The DA14535 is a DA14531 upgrade.
    - The DA14533 is optimized for automotive and industrial applications at higher temperatures. It is rated for operation up to 105 °C and is compliant with the AEC-Q100 (Grade 2) standard.

## HW and SW configuration

- **Hardware configuration**
    - This example runs on the DA1453x (DA14531-00, DA14531-01 and DA14535) Bluetooth Smart SoC devices.
    - For the DA14531 PMOD product page, refer to [US159-DA14531EVZ BLE Pmod](https://www.renesas.com/us/en/products/wireless-connectivity/bluetooth-low-energy/us159-da14531evz-low-power-bluetooth-pmod-board-renesas-quickconnect-iot).
    - For the DA14531 getting started guide, refer to [UM-B-117](https://lpccs-docs.renesas.com/UM-B-117-DA14531-Getting-Started-With-The-Pro-Development-Kit/index.html).
    - For the DA14535 getting started guide, refer to [UM-B-165](https://lpccs-docs.renesas.com/DA14535/UM-B-165-DA14531-Getting-Started-With-The-Pro-Development-Kit/index.html#device-family-getting-started-with-the-pro-development-kits).
    - For the DA14531 Module getting started guide, refer to [UM-B-139](https://lpccs-docs.renesas.com/UM-B-139-Getting-Started-with-DA14531-TINY-Module/index.html).
    - For the DA14533 getting started guide, refer to [R19US0026EE0100](https://lpccs-docs.renesas.com/da14533_getting_started_guide/index.html).
    - For detailed instructions to build a fully working solution that allows booting from a host Renesas microcontroller, refer to [UM-B-172: Getting started with DA1453x and FSP BLE Framework on Renesas Microcontrollers](https://lpccs-docs.renesas.com/DA1453x-FSP_BLE_Framework/UM-B-172/index.html).

- **Software configuration**
    - [SDK6 latest version](https://www.renesas.com/sdk6_latest)

## How to run the example

The generated GTL binaries are located in the `renesas_ble_abstraction_gtl_project\binaries` folder. These binaries can be used when compiling with the FSP. In an FSP project, the GTL binary is found at `ra/renesas/wireless/da14xxx/r_ble_gtl/r_ble_gtl_image.c`.

### GTL over UART

This is the default configuration. The host MCU can either download the GTL image into the DA1453x RAM at boot (boot from host), or the image can be burned in flash.

For more details about the SDK updates that enable booting the DA1453x from an external Renesas microcontroller via UART, refer to [UM-B-119](https://lpccs-docs.renesas.com/UM-B-119_DA14585-DA14531_SW_Platform_Reference/User_guides/User_guides.html#fsp-attach).

### GTL over SPI

The SPI variant of the GTL application allows the host MCU to communicate with the DA14531 PMOD over SPI instead of UART.

> **Important boot from host is not supported over SPI.**
> The DA14531 cannot be booted by the host through the SPI GTL interface. The GTL SPI image **must be burned into the SPI flash of the DA14531 PMOD** so that the device boots standalone from its own flash. Once booted, the host communicates with it over SPI.

**Steps:**

1. Take the SPI GTL binary from the `renesas_ble_abstraction_gtl_project\binaries` folder.
2. Burn the binary into the SPI flash of the DA14531 PMOD.
3. Power-cycle the PMOD. The DA14531 boots from its SPI flash and is then ready to accept GTL messages from the host over SPI.
4. Configure the FSP host application to use the SPI transport for GTL.

> **Note source code availability.**
> The source files of the GTL SPI application are **not provided** in this repository. The application is based on a new SDK release that is not yet publicly available. Only the pre-built binary is delivered. The sources will be published once the corresponding SDK release becomes public.

## Further reading

- [Wireless Connectivity Forum](https://lpccs-docs.renesas.com/lpc_docs_index/DA145xx.html)

## Known Limitations

- For general SDK limitations, refer to the [SDK6 known limitations](https://lpccs-docs.renesas.com/sdk6_kll/index.html) application note.

## Feedback and support

If you have any comments or suggestions about this document, you can contact us through:

- [Wireless Connectivity Forum](https://community.renesas.com/wireles-connectivity)
- [Contact Technical Support](https://www.renesas.com/eu/en/support?nid=1564826&issue_type=technical)
- [Contact a Sales Representative](https://www.renesas.com/eu/en/buy-sample/locations)
