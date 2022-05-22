#include <AvrI2c_Greiman.h>
#include <LiquidCrystal_I2C_AvrI2C.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <virtuabotixRTC.h>
#include <RTClib.h>
#include <SPI.h>
#include <SD.h>

// LCD address and geometry and library initialization
const byte lcdAddr = 0x27;  // Address of I2C backpack
const byte lcdCols = 16;    // Number of character in a row
const byte lcdRows = 2;     // Number of lines
//const byte lcdAddr = 0x3F;  // Address of I2C backpack
//const byte lcdCols = 20;    // Number of character in a row
//const byte lcdRows = 4;     // Number of line
File dataFile;

LiquidCrystal_I2C lcd(lcdAddr, lcdCols, lcdRows);
virtuabotixRTC myRTC(6,7,8);
// Demo parameters
const char demoText[]= "   Date & Time   ";
const unsigned int scrollDelay = 500;   // Miliseconds before scrolling next char
const unsigned int demoDelay = 500;    // Miliseconds between demo loops
byte textLen;                           // Number of visible characters in the text

void setup() {
  textLen = sizeof(demoText) - 1;
  lcd.init();
  lcd.backlight();
  lcd.print(demoText);
  delay(demoDelay);
  Serial.begin(9600);
  while (!Serial)
    ; // wait for serial port to connect. Needed for native USB port only
  Serial.print("Initializing SD card...");
  if (!SD.begin()) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  delay(2000);
}



uint16_t line = 1;
void loop() {
  // Scroll entire text in a row to the left outside the screen
  for (byte positionCounter = 0; positionCounter < textLen; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(scrollDelay);
     myRTC.updateTime();
  lcd.setCursor(3,1); 
  lcd.print(myRTC.dayofmonth); //Günü ekrana bastırıyoruz.
  lcd.print("/");
  lcd.print(myRTC.month); //Ayı ekrana bastırıyoruz.
  lcd.print("/");
  lcd.print(myRTC.year); //Yılı ekrana bastırıyoruz
  lcd.print(" ");
  lcd.print(myRTC.hours); //Saati ekrana bastırıyoruz.
  lcd.print(":");
  lcd.print(myRTC.minutes);
  }
  // Scroll hidden text through entire row to the right outside the screen
  for (byte positionCounter = 0; positionCounter < textLen + lcdCols; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(scrollDelay);
    /*myRTC.updateTime();
  lcd.setCursor(0, 1); 
  lcd.print(myRTC.dayofmonth); //Günü ekrana bastırıyoruz.
  lcd.print("/");
  lcd.print(myRTC.month); //Ayı ekrana bastırıyoruz.
  lcd.print("/");
  lcd.print(myRTC.year); //Yılı ekrana bastırıyoruz
  lcd.print(" ");
  lcd.print(myRTC.hours); //Saati ekrana bastırıyoruz.
  lcd.print(":");
  lcd.print(myRTC.minutes);*/
  }
  // Scroll text to the right back to original position
  for (byte positionCounter = 0; positionCounter < lcdCols; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(scrollDelay);
  }
  delay(demoDelay);
   /* myRTC.updateTime();
  lcd.setCursor(0, 1); 
  lcd.print(myRTC.dayofmonth); //Günü ekrana bastırıyoruz.
  lcd.print("/");
  lcd.print(myRTC.month); //Ayı ekrana bastırıyoruz.
  lcd.print("/");
  lcd.print(myRTC.year); //Yılı ekrana bastırıyoruz
  lcd.print(" ");
  lcd.print(myRTC.hours); //Saati ekrana bastırıyoruz.
  lcd.print(":");
  lcd.print(myRTC.minutes);*/
  dataFile = SD.open("datalogg.txt", FILE_WRITE);
  // if the file opened okay, write to it:
  if (dataFile) {
  //  Serial.print(line);
    Serial.print(": Ay = ");
    Serial.print(myRTC.month);
    Serial.print(",Yıl = ");
    Serial.print(myRTC.year);
    Serial.print(":   Saat = ");
    Serial.print(myRTC.hours);
    Serial.print(":   Dakika = ");
    Serial.print(myRTC.minutes);
     
    // Write data to SD card file (Datalogg.txt)
   dataFile.print(line++);
    dataFile.print("Ay = ");
    dataFile.print(myRTC.month);
    dataFile.print(",   Yıl = ");
    dataFile.print(myRTC.year);
    dataFile.println(",Saat = ");
     dataFile.print(myRTC.hours);
     dataFile.print(",Dakika = ");
       dataFile.print(myRTC.minutes);
     
    
    dataFile.close();
  }
 

  
}
