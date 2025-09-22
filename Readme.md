# Smartbond SDK6 Application Examples

This is the repository storing example for the [DA145xx family](https://www.renesas.com/eu/en/products/interface-connectivity/wireless-communications/bluetooth-low-energy/da14531-smartbond-ultra-low-power-bluetooth-51-system-chip).

For information about the DA145xx platform and how to bring up your development kit, please refer to the [Getting started User Manual](http://lpccs-docs.renesas.com/UM-B-117-DA14531-Getting-Started-With-The-Pro-Development-Kit/index.html)

## Example usage

To run any of these SW examples, the user needs:

- DA1453x/DA14585/DA14586 hardware.
- Keil µvision.
- e2 studio(New Update llvm compiler version support)
- It is essential to always download and use the latest version of Renesas SDK6. These demo examples are continuously synchronized with the most recent SDK6 release unless otherwise specified.



1. First, download [the SDK from the Renesas website](https://www.renesas.com/us/en/document/swo/sdk60221401-da1453x-da145856).  
	_Creating an account and accepting the license agreement are required to download the SDK._
	
2. Enter the projects folder and clone this repository:

	```console
    > cd projects
	> git clone https://github.com/dialog-semiconductor/BLE_SDK6_examples.git
    ```
	
3. Open the project file (.uvprojx) you are interested in in Keil µvision.

4. Select your target:

	![Alt text](https://lpccs-docs.renesas.com/UM-B-117-DA14531-Getting-Started-With-The-Pro-Development-Kit/_images/blinky_project_531.jpg "Select target")

5. Build the project:

	![Alt text](https://lpccs-docs.renesas.com/UM-B-117-DA14531-Getting-Started-With-The-Pro-Development-Kit/_images/blinky_built.jpg "Build")

6. Run:

	![Alt text](https://lpccs-docs.renesas.com/UM-B-117-DA14531-Getting-Started-With-The-Pro-Development-Kit/_images/blinky_run.jpg "Run")



**Note**: _It is highly recommended the user creates files that are added in the *src* folder of the SW example._


## Examples Overview

<!---
AUTOMATICALLY GENERATED CONTENT, DO NOT EDIT!
See .pre-commit-config.yaml for more info
@EXAMPLE_TABLE_BEGIN@
--->
<table><tr><th>Module</th><th>Name</th><th>Boards</th><th>Description</th></tr><tr><td>connectivity</td><td><a href="./connectivity/active_scanner">active_scanner</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">This example shows how to setup the DA145xx device in active scanning mode,
On advertising data report, the data is formatted and pushed on the UART
<br><br>Keywords: scanning mode, advertising data, UART</td></tr><tr><td>connectivity</td><td><a href="./connectivity/Advertising(methods_wakeup_sleep)">advertising</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">This example shows how to Use a button to switch between advertising
methods, Go for sleep and wakeup , Timer callback is used
<br><br>Keywords: button, advertising, Sleep, Wakeup up</td></tr><tr><td>connectivity</td><td><a href="./connectivity/ble-Midi">ble-Midi</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">This example shows how to create MIDI service on DA145xx BLE device
<br><br>Keywords: MIDI, BLE</td></tr><tr><td>connectivity</td><td><a href="./connectivity/BLE2IR">BLE2IR</a></td><td valign="top"><ul><li>DA14585 Basic Kit</li></ul></td><td valign="top">This example provides an implementation of a Simple RCU using a custom BLE
profile
<br><br>Keywords: Remote Control Unit</td></tr><tr><td>connectivity</td><td><a href="./connectivity/ble_temperature_ntf">ble_temperature</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">This is Simple example showing how to interface the DA14585/586 and DA14531
with the Thermo 8 click board™
<br><br>Keywords: MCP9808, Thermo 8 click board, I2C</td></tr><tr><td>connectivity</td><td><a href="./connectivity/Advertising(burst)">burst_adv</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">This is a simple example showing how to implement &#x27;burst&#x27; advertising on
the DA14531 and DA1458x devices
<br><br>Keywords: Burst advertising, UART</td></tr><tr><td>connectivity</td><td><a href="./connectivity/ble_Notify_button_Wakeup">button_Wakeup</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">This example shows how to configure a DA14531 or DA1458x device to send
notifications to a BLE central by button presses
<br><br>Keywords: notification, BLE, Button presses</td></tr><tr><td>connectivity</td><td><a href="./connectivity/central">central</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li><li>DA14531 USB Kit</li></ul></td><td valign="top">This project is intended to illustrate to the user How to scan for peer
devices and how to parse advertisement data during the scan process + BLE
connection
<br><br>Keywords: BLE, Central</td></tr><tr><td>connectivity</td><td><a href="./connectivity/central_Security_Demo">central_Security</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Basic Kit</li></ul></td><td valign="top">The main example purpose is to demonstrate the basic pairing, encryption
and bonding process on central side
<br><br>Keywords: pairing, encryption, bonding</td></tr><tr><td>connectivity</td><td><a href="./connectivity/coexistance_demo">Coexistence</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">The example provides guidelines on how the WiFi coexistence feature can be
enabled on the SDK
<br><br>Keywords: WiFi coexistence, BLE</td></tr><tr><td>connectivity</td><td><a href="./connectivity/hibernation_and_stateaware_hibernation">hibernation</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li></ul></td><td valign="top">This example demonstrates the Hibernation and the State aware hibernation
features on the DA14531
<br><br>Keywords: Hibernation, State aware hibernation</td></tr><tr><td>connectivity</td><td><a href="./connectivity/ibeacon">ibeacon</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li><li>DA14531 USB Kit</li></ul></td><td valign="top">This is an iBeacon implementation for the DA14531, DA1458x
<br><br>Keywords: iBeacon, payload parameters, advertising interval, UUID</td></tr><tr><td>connectivity</td><td><a href="./connectivity/ibeacon_Optim">ibeacon_Optim</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li></ul></td><td valign="top">The example demonstrates an optimized software implementation for ibeacon
on the DA14531
<br><br>Keywords: ibeacon, power optimization</td></tr><tr><td>connectivity</td><td><a href="./connectivity/multi_con_periph">multi_con_periph</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">This example demonstrates how a single peripheral can be connected to more
than one central.
<br><br>Keywords: Central, peripheral, connection</td></tr><tr><td>connectivity</td><td><a href="./connectivity/multirole">multirole</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">The example demonstrates the capabilities of the DA14531/58x as a
Central and a peripheral i.e. scan and advertise role
<br><br>Keywords: Central, peripheral, scan, advertise roles</td></tr><tr><td>connectivity</td><td><a href="./connectivity/ble_pressure_sensor_bmp388">pressure_sensor</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">This is Simple example showing how to interface the DA1458x and DA14531
with the PRESSURE 5 CLICK Board™
<br><br>Keywords: BLE, PRESSURE 5 CLICK Board™</td></tr><tr><td>connectivity</td><td><a href="./connectivity/Quuppa_DialogTag">Quuppa Tag Emu</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li></ul></td><td valign="top">this is the QUUPPA Tag Emu Demo on the DA14531
<br><br>Keywords: Quuppa Intelligent Locating System™, real-time location, BLE, Tag</td></tr><tr><td>connectivity</td><td><a href="./connectivity/scan_request_track">scan_request_track</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">This example demonstrates how a peripheral device can track if it is
scanned and which central device performs the scanning procedure
<br><br>Keywords: scan, central, track</td></tr><tr><td>connectivity</td><td><a href="./connectivity/simple_beacon">simple_beacon</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">The main purpose of this Software Εxample is to demonstrate creating a
Non-Connectable Advertising application example
<br><br>Keywords: Beacon, Non, Connectable Advertising</td></tr><tr><td>connectivity</td><td><a href="./connectivity/svc_data_beacon">svc_data_beacon</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">The main purpose of this software example is to demonstrate creating a
Non-Connectable Advertising application example that includes service data.
Specifically, this example illustrates the idea of including Service Data
from a 16-bit UUID as defined by the Bluetooth SIG
<br><br>Keywords: Beacon, Non, Connectable Advertising, UUID</td></tr><tr><td>connectivity</td><td><a href="./connectivity/ble_weight_scale_nau7802">Weight Scale</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li></ul></td><td valign="top">The goal of this example is to show an implementation of a generic BLE
profile by showing a weight scale implementation
<br><br>Keywords: Weight Scale</td></tr><tr><td>features</td><td><a href="./features/dynamic_L2CAP_Packet_size_Optimization">L2CAP</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">This project is intended to illustrate to the user how to do a peer feature
request for determining peer DLE capability and how to request DLE and
utilize larger packets to enhance throughput
<br><br>Keywords: L2CAP, DLE, throughput</td></tr><tr><td>features</td><td><a href="./features/reset_Indication_update">reset_Indication</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li><li>DA14531 USB Kit</li></ul></td><td valign="top">The current SW example demonstrates how to issue and identify the different
kinds of reset on the DA14531 and DA14585/586 devices as well as
identifying if the device run into a Hardfault or an NMI interrupt.
<br><br>Keywords: Reset, source</td></tr><tr><td>features</td><td><a href="./features/social_distancing">social-distancing</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li><li>DA14531 USB Kit</li></ul></td><td valign="top">This example configures a DA14531 device to be used for social distancing
purposes
<br><br>Keywords: DA14531, social distancing (SDT)</td></tr><tr><td>features</td><td><a href="./features/DA1453x_Timer1_SW_Example">Timer1</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li></ul></td><td valign="top">This software example demonstrates the usage of the TIMER1 hardware block.
The SW example exposes the basic functions that TIMER1 offers
<br><br>Keywords: Timer 1, DA14531</td></tr><tr><td>helpers</td><td><a href="./helpers/usb_preloaded_firmware">usb_preloaded</a></td><td valign="top"><ul><li>DA14531 USB Kit</li></ul></td><td valign="top">The main purpose of this software example is to provide the source files
containing the firmware for the preloaded binary in the DA14531 USB kit.
<br><br>Keywords: USB, DA14531, OTP unique random address, BD address, UART print</td></tr><tr><td>interfaces</td><td><a href="./interfaces/accel-Sensor">accel-Sensor</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">This example shows how to acquire data from an I2C accelerometer and send
the measurements with BLE notifications using a DA14531 or DA14585/586
device
<br><br>Keywords: I2C accelerometer, BLE notifications</td></tr><tr><td>interfaces</td><td><a href="./interfaces/external-processor-renesas">External processor Renesas</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li></ul></td><td valign="top">The goal of this example is to show how to load a program into the RAM of
the DA14531 via a Renesas microcontroller EK-RA2E1.
<br><br>Keywords: EK, RA2E1, DA14531 RAM, External MCU</td></tr><tr><td>interfaces</td><td><a href="./interfaces/HID-Gamepad-Digitizer">HID-Gamepad</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">A DA14585/6 HID gamepad demo project. Used to demonstrate the usage of HID
features over BLE with HOGPD profile.
<br><br>Keywords: HID gamepad, BLE HOGPD profile.</td></tr><tr><td>interfaces</td><td><a href="./interfaces/I2C-Master-Slave">I2C-Master-Slave</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li></ul></td><td valign="top">This example describes how to perform I2C data buffer
transmission/reception between two boards in asynchronous mode
(non-blocking communication). The project is split in two parts: the Master
Board and the Slave Board.
<br><br>Keywords: I2C, Master-slave</td></tr><tr><td>interfaces</td><td><a href="./interfaces/MCube-Accel-MC36xx">MCube-Accel</a></td><td valign="top"><ul><li>DA14585 Basic Kit</li></ul></td><td valign="top">Sample software application to interface Dialog DA14585/586 BLE SoC&#x27;s with
mCube MC36xx (MC3672/35) accelerometers.
<br><br>Keywords: I2C, MC36xx (MC3672/35) accelerometers.</td></tr><tr><td>interfaces</td><td><a href="./interfaces/segger_rtt">segger_rtt</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li><li>DA14585 Pro Dev Kit</li><li>DA14531 USB Kit</li></ul></td><td valign="top">This example illustrates to the user, how to use SEGGER RTT in conjunction
with the DA145xx family.
<br><br>Keywords: Segger RTT</td></tr><tr><td>interfaces</td><td><a href="./interfaces/SPI-Master-Slave">SPI-Master-Slave</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li></ul></td><td valign="top">This example describes how to perform SPI data buffer
transmission/reception between two DA14531 devices via DMA. The project is
split in two parts: the Master Board and the Slave Board.
<br><br>Keywords: SPI, Master-slave</td></tr><tr><td>interfaces</td><td><a href="./interfaces/external-processor-stm32">STM32-external-processor</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li></ul></td><td valign="top">The goal of this example is to show how to load a program into the RAM of
the DA14531 via a STM32 microcontroller
<br><br>Keywords: STM32, DA14531 RAM, External MCU</td></tr><tr><td>interfaces</td><td><a href="./interfaces/wakeup_hibernation_ext_timer">wakeup_ext_timer</a></td><td valign="top"><ul><li>DA14531 Pro Dev Kit</li></ul></td><td valign="top">This example configures a DA14531 device to be used as an Eddystone beacon.
<br><br>Keywords: Eddystone beacon, TPL5010EVM, Wakeup</td></tr></table>
<!---
@EXAMPLE_TABLE_END@
--->


## Example compatibility

Not all the examples will run on the latest version of the SDK6, the tested version is indicated in the Readme. If you find and example that needs porting to the latest version please report it in the issues.


