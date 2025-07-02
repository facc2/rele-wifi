#include "WiFi.h"
#include <DHT11.h>

DHT11 dht11(21);

int rele1 = 19;

void setup() {
Serial.begin(9600);
pinMode(rele1, OUTPUT);
WiFi.mode(WIFI_STA);
WiFi.disconnect();
delay(100);
}

void loop() {
 int n = WiFi.scanNetworks();
    Serial.println("Scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        Serial.println("Nr | SSID                             | RSSI | CH | Encryption");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.printf("%2d",i + 1);
            Serial.print(" | ");
            Serial.printf("%-32.32s", WiFi.SSID(i).c_str());
            Serial.print(" | ");
            Serial.printf("%4d", WiFi.RSSI(i));
            Serial.print(" | ");
            Serial.printf("%2d", WiFi.channel(i));
            Serial.print(" | ");
                                  }
           }
 int temperature = dht11.readTemperature();     
  if(temperature>17){
    rele1 = 1;
}
}
