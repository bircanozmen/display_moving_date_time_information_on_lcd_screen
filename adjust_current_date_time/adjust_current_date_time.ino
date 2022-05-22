#include <virtuabotixRTC.h>
//RTC bağlantı pinleri
//CLK -> 6, Data -> 7, RST -> 8
virtuabotixRTC myRTC(6, 7, 8);
void setup() {
Serial.begin(9600);
// RTC üzerindeki tarih ve saati aşağıdaki kod ile ayarlayabilirsiniz.
// saniye, dakika, saat, haftanın günü, ayın günü, ay, yıl (haftanın günü pazartesi için 1 yazıyoruz.)
myRTC.setDS1302Time(35, 26, 15,3, 11, 05, 2022);
}
void loop() {
myRTC.updateTime(); //Bu kod ile RTC deki anlık zamanı alıyoruz.
// Tüm bilgileri tek tek okuyup seri ekrana yazdırıyoruz.
Serial.print("Tarih / Saat : ");
Serial.print(myRTC.dayofmonth);
Serial.print("/");
Serial.print(myRTC.month);
Serial.print("/");
Serial.print(myRTC.year);
Serial.print(" ");
Serial.print(myRTC.hours);
Serial.print(":");
Serial.print(myRTC.minutes);
Serial.print(":");
Serial.println(myRTC.seconds);
delay( 1000); // 1 saniye bekletiyoruz.
}
