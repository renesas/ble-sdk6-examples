## renesas_ble_abstraction_gtl_project_coax

## Example description

This example updates the basic proximity monitor service demonstration from the standard SDK `6.0.24.1464\projects\target_apps\ble_examples\prox_reporter_ext`. this example includes the device information client service and uses the External Processor configuration with GTL over UART. This setup allows the DA14531 device to boot from an external MCU.

## HW and SW configuration

- **Hardware configuration**

- **Software configuration**
    - [SDK6 latest version](https://www.renesas.com/sdk6_latest)

## How to run the example

The generated GTL binaries are located in the `renesas_ble_abstraction_gtl_project\binaries` folder. These binaries can be used when compiling with the FSP. In an FSP project, the GTL binary is found at `ra/renesas/wireless/da14xxx/r_ble_gtl/r_ble_gtl_image.c`. For more details about the SDK updates that enable booting the DA1453x from an external Renesas microcontroller via UART, refer to [UM-B-119](https://lpccs-docs.renesas.com/UM-B-119_DA14585-DA14531_SW_Platform_Reference/User_guides/User_guides.html#fsp-attach).

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

