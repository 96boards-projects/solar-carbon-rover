# solar-carbon-rover

# Table of Contents

- [1) Hardware](#1-hardware)
   - [1.1) Hardware Requirements](#11-hardware-requirements)
   - [1.2) Hardware Setup](#12-hardware-setup)
- [2) Software](#2-software)
   - [2.1) Build & Flash](#21-build-and-flash)

# 1) Hardware

## 1.1) Hardware Requirements

- [96Boards Carbon](https://www.96boards.org/product/carbon/)
- [Arduino Uno](https://store.arduino.cc/usa/arduino-uno-rev3)
- 2x [Micro Geared Motors 3v 50RPM](https://robu.in/product/n20-3v-50-rpm-micro-metal-gear-box-dc-motor-copy-2/)
- 2x [N20 Motor Wheel](https://robu.in/product/34mm-mini-car-n20-motor-wheel-rubber-small-wheel/)
- 1x [Ball Caster Wheel](https://robu.in/product/ball-caster-wheel-big/)
- 1x [MX1508 Dual H Bridge](https://robu.in/product/mx1508-dual-h-bridge-dc-pwm-stepper-motor-driver/)
- 1x 6v 100mAh-200mAh Solar Panel, similar to [this.](https://www.amazon.in/Generic-Techamazon-Projects-Robotic-project/dp/B07638B6Z8/)
- 2x [HC-12 Radio](https://www.amazon.in/Generic-433Mhz-Wireless-Replace-Bluetooth/dp/B0722HHCYZ/)
- 1x [FunDuino Joystick Shield](https://protosupplies.com/product/funduino-joystick-shield-v1-a/)
- Connecting wires

## 1.2) Hardware Setup

- **Plugin the FunDuino Joystick Shield on the Arduino.**
- **Plug in one of the HC12 Modules to the Arduino as follows:**

| HC-12 Radio | Arduino Uno |
|:-----------:|:-----------:|
| VCC         | 5v          |
| GND         | GND         |
| TXD         | RX - 0      |
| RXD         | TX - 1      | 

- **Plug in the other HC-12 Radio to the 96Boards Carbon as follows:**

| HC-12 Radio | 96Boards Carbon - ST Header |
|:-----------:|:---------------------------:|
| TXD         | RX-1                        |
| RXD         | TX-1                        |

- **Plug in the MX1508 Motor Controller to the 96Boards Carbon as follows:**

| MX1508 | 96Boards Carbon |
|:-----:|:----------------:|
| IN1   | PB8              |
| IN2   | PB9              |
| IN3   | PC0              |
| IN4   | PC1              |

- **Plug in the MX1508 Motor Controller to the Motors as follows:**

| MX1508  | Motors Left & Right |
|:-------:|:-------------------:|
| Motor A | Motor Left          |
| Motor B | Motor Right         |

- **Connect all 5v and GND to the Solar Panels's 5v and GND**

# 2) Software\

## 2.1) Build And Flash

**Arduino setup**
- Flash ```src/controller-arduino/controller.ino``` using the Arduino IDE.

**Carbon Setup**
- **Compile**

```
cd zephyr_base
source zephyr-env.sh
west build ./src/rover-zephyr/solar-rover -b 96b_carbon
```

- **Flash Vio OTG**
    - Connect the micro-USB cable to the USB OTG Carbon port and to your computer. The board should power ON. Force the board into DFU mode by keeping the BOOT0 switch pressed while pressing and releasing the RST switch
	- You should see following confirmation on your Linux host:
	```shell
	$ dmesg
	usb 1-2.1: new full-speed USB device number 14 using xhci_hcd
	usb 1-2.1: New USB device found, idVendor=0483, idProduct=df11
	usb 1-2.1: New USB device strings: Mfr=1, Product=2, SerialNumber=3
	usb 1-2.1: Product: STM32 BOOTLOADER
	usb 1-2.1: Manufacturer: STMicroelectronics
	usb 1-2.1: SerialNumber: 3574364C3034
	```
	- Flash
	```shell
	$ west flash
	```