# ble_dnd_sign

![image](https://github.com/droidecahedron/ble_dnd_sign/assets/63935881/3318a21f-d9d0-4f8a-a84e-e7f799e7c1c7)

## Overview
Some boiler plate code to add a screen using LVGL to draw logos and labels on top of the [peripheral_lbs](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/samples/bluetooth/peripheral_lbs/README.html) sample.

You send bool true or false to the LED service to toggle the status message in the middle.
The status message on the bottom for BLE state is updated when you connect/disconnect from a central device (phone or otherwise).
When connected, the sample sends the state of **Button 1** on the development kit to the connected device, such as a phone or tablet.
The mobile application on the device can display the received button state and control the state of **LED 3** on the development kit, as well as the Current Status displayed on the screen.


You'll either need a mobile device with nRF Connect app, or another devkit to act as the central to interface with the services.
> For more details on exchange in BLE (characteristics, etc), visit this section in the [Nordic DevAcademy]([url](https://academy.nordicsemi.com/courses/bluetooth-low-energy-fundamentals/lessons/lesson-4-bluetooth-le-data-exchange/)).

File | Function
--- | ---
main.c | main application with BLE functionality (just peripheral lbs)
display.c | display task with LVGL functionality
logo.c | nordic logo, you can put whatever image you want. [lvgl/Images](https://docs.lvgl.io/master/overview/image.html)

| Compatible devices|
|---|
| nRF52832DK* |
| nRF52840DK|
| nRF5340DK*|
> *should work, haven't tried.

## hardware / documentation
- nRF52840DK / [nRF52840 doc](https://docs.nordicsemi.com/bundle/nRF52840_PS_v1.8/resource/nRF52840_PS_v1.8.pdf) / [nRF52840DK Doc](https://docs.nordicsemi.com/bundle/ug_nrf52840_dk/page/UG/dk/intro.html)
- [Adafruit 2.8 TFT Touch Shield V2](https://learn.adafruit.com/adafruit-2-8-tft-touch-shield-v2), uses an ILI9341, this repo is with the capacitive touch variant which sports an FT6206.

<img src="https://github.com/droidecahedron/nrf-blueberry/assets/63935881/12612a0e-9f81-4431-8b22-f69704248f89" width=25% height=25%>
<img src="https://github.com/droidecahedron/ble_dnd_sign/assets/63935881/60ed2e09-91bd-4c0b-bcc8-7ae78a7e0d23", width=22% height=22%>

## User Interface
**LED 1:**
   Blinks when the main loop is running (that is, the device is advertising) with a period of two seconds, duty cycle 50%.

**LED 2:**
   Lit when the development kit is connected.

**LED 3:**
   Lit when the development kit is controlled remotely from the connected device.

**Button 1:**
   Send a notification with the button state: "pressed" or "released".

## Additional Screen Details
The Adafruit 2.8" TFT Touch Shield v2 with a
resolution of 320x240 pixels, is based on the ILI9341 controller.
This shield comes with a resistive (STMPE610 controller)
or capacitive (FT6206 controller) touchscreen. While the
Zephyr RTOS supports display output to these screens,
touchscreen input is supported only on Capacitive Touch version.

### Pins Assignment of the Adafruit 2.8" TFT Touch Shield v2

Shield Connector Pin  | Function                                    
---|---
D4                    | MicroSD SPI CSn                             
D7                    | Touch Controller IRQ (see note below)       
D8                    | STMPE610 SPI CSn (Resistive Touch Version)  
D9                    | ILI9341 DC       (Data/Command)             
D10                   | ILI9341 SPI CSn                             
D11                   | SPI MOSI         (Serial Data Input)        
D12                   | SPI MISO         (Serial Data Out)          
D13                   | SPI SCK          (Serial Clock Input)       
SDA                   | FT6206 SDA       (Capacitive Touch Version) 
SCL                   | FT6206 SCL       (Capacitive Touch Version) 

> note:
>   Touch controller IRQ line is not connected by default. You will need to
>   solder the ``ICSP_SI1`` jumper to use it. You will also need to adjust
>   driver configuration and its Device Tree entry to make use of it.


<!-- https://www.adafruit.com/product/4947 e-ink -->
