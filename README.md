# Displaying Moving Text Current Date & Time on Lcd Screen

## Objective:
The aim of this project is to make nice looks on an LCD screen with date&time and text. When we compile the code we see the current date&time with the text on the LCD Screen. This application can be used for businesses that use light plates. We can display long information text with this application. In every second text is moving so you can display texts no matter what length.

## Materials:
* RTC Module - 2 pieces
* LCD Screen (16x2) - 2 pieces
* Jumper Cable (Male) - 15 pieces 
* Arduino Nano - 1 piece
* SD card & SD card reader - 1 piece 
* RTC module battery - 2 pieces

## Connections:
### For RTC module to Arduino Nano
* VCC -> 5V
* GND -> GND
* CLK -> D6
* DAT -> D7
* RST -> D8

### For LCD SCREEN to Arduino Nano
* GND -> GND
* VCC -> 5V
* SDA -> A4
* SCL -> A5

### For SD Card Reader to Arduino Nano
* 5 -> 5V
* CS -> D10
* MOSI -> D11
* SCK -> D13
* MISO -> D12
* GND -> GND

## Libraries:
* AvrI2c_Greiman.h  (for LCD Screen)
* LiquidCrystal_I2C_AvrI2C.h (for LCD Screen)
* Wire.h (for Connection)
* virtuabotixRTC.h (for RTC Module)
* RTClib.h (for RTC Module)
* SPI.h (for SD Card)
* SD.h (for SD Card)

## Circuit Photo

![circuit_photo](https://user-images.githubusercontent.com/80538415/195995066-77be5156-28f7-42af-8ea4-09a26b62d945.png)

## Informations ( Date&Time ) that Gathering from SD Card

![datalog](https://user-images.githubusercontent.com/80538415/195995167-f3477b5f-a461-4fd0-b400-ae892591bf24.png)

* My file name is datalogg.txt


