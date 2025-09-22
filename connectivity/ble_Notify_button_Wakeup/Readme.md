---
name: button_Wakeup
module: connectivity
boards: [da14531_pro, da14585_pro]
keywords:
    - notification 
    - BLE 
    - Button presses
description: |
    This example shows how to configure a DA14531 or DA1458x device to send
    notifications to a BLE central by button presses
---

# DA1453x and DA1458x BLE Notifications on Button Press with Wake-up Controller

## Example description

This example shows how to configure a DA14531 or DA14585/586 device to send notifications to a BLE central by button presses. The application advertises its presence and waits for a connection. When a central is connected and enables notifications, the application will be able to deliver notifications when the user presses one of the programmable buttons. The service also waits for a predefined message to which it will respond. 

- Devices naming:
    - DA1453x is refering to DA14531-00, DA14531-01, DA14530 and DA14535.
    - DA1458x is refering to DA14585 and DA14586.
    - The DA14531-00 is the main DA14531 device. The -00 is just a new naming to introduce the variant DA14531-01. The DA14531-01 is a ROM variant of the main DA14531-00.
    - The DA14535 is a DA14531 upgrade.
	- The DA14533 is optimized for automotive and industrial applications at higher temperatures, and it is rated as operating up to 105 ºC and compliant with the AEC-Q100 (Grade 2) standard.


## HW and SW configuration
- This example runs on the DA1453x or DA1458x Bluetooth Smart SoC devices.	
- The DA145xx Pro Development Kit is needed for this example, and it can be used with either the DA1453x or DA1458x daughterboard evaluation kits.

### Hardware configuration for the DA1453x

- Connect the USB1 connector of the DA145xx Pro Development Kit to the host computer.
- Connect the P24 pin on header J2 with the second pin on header J19 as shown in the figure below (the mark indicates the first pin). Connect with a jumper the third and fourth pins.
 
	![j19_conf](assets/ble-notify-wkup-j19_conf.svg)

### Hardware configuration for the DA1458x

- Connect the USB1 connector of the DA145xx Pro Development Kit to the host computer.
- Connect with a jumper the first and second pins on the J19 header (the mark indicates the first pin). Connect also with a jumper the fourth and fifth pins, as indicated in the figure below.
 
	![j19_conf_585](assets/ble-notify-wkup-j19_585_conf.svg)

### Software configuration

 This example requires:
 - Download the [SDK6 latest version](https://www.renesas.com/sdk6_latest)
 - **SEGGER’s J-Link** tools should be downloaded and installed.
 - Additionally, an application like LightBlue Explorer must be used to act as a BLE central. It can be found on [Google Play](https://play.google.com/store/apps/details?id=com.punchthrough.lightblueexplorer) or on the [App Store](https://apps.apple.com/gb/app/lightblue-explorer/id557428110).


## Note
This example can be built by e2studio and LLVM compiler instead of using Keil.


## How to run the example

For the initial setup of the project that involves linking the SDK to this SW example, please follow the Readme [here](../../Readme.md).

### Initial Setup

 - Start Keil
 - Select the DA14531, DA14585 or DA14586 device in the box shown below 

	![select_box_DA14531](assets/ble-notify-wkup-select_device.png)

 - Compile and launch the example

 ### Connecting to the device
 
 The following instructions are using the LightBlue Explorer app.
 - Start the LightBlue Explorer. The application will list all the Bluetooth devices that are advertising. 
 - Connect to the `DLG_BUTTON_NOTIFY` device
 	
	 ![ble-notify-wkup-device_select](assets/ble-notify-wkup-device_select.png)

 - Once connected, the application will list all discovered services. Connect to the service named `Control Point`.

  	![ble-notify-wkup-device_connected](assets/ble-notify-wkup-device_connected.png)

 - Press the subscribe button to subscribe to notifications.

  	![ble-notify-wkup-subscription.png](assets/ble-notify-wkup-subscription.png)

- Change the data format to `UTF-8 String` and then press the SW3 button on the Pro Development Kit. The device will respond with a notification with the text "Move!"

  	![ble-notify-wkup-move.png](assets/ble-notify-wkup-move.png)

- Press the SW2 button on the Pro Development Kit. The device will respond with a notification with the text "Stop!"

  	![ble-notify-wkup-stop.png](assets/ble-notify-wkup-stop.png)

- In the Written Values field, enter the text "Marco?" in the text box as shown below. Beware to remove any trailing spaces, and press `Write`.

  	![ble-notify-wkup-write.png](assets/ble-notify-wkup-write.png)

- You'll immediately see the device responding "Polo!".

	![ble-notify-wkup-response.png](assets/ble-notify-wkup-response.png)

	
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



