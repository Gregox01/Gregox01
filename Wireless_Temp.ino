#include <SPI.h>
#include <WiFiNINA.h>
char ssid[] = "";          //  your network SSID (name)
char pass[] = "";   // your network password
int sensorPin = 2; 


int status = WL_IDLE_STATUS;
char servername[]="rolfing.berlin";  // remote server we will connect to

WiFiClient client;

void setup() {
  int t=0;
  Serial.begin(9600);
  delay(2500);
  Serial.println("Attempting to connect to WPA network...");
  Serial.print("SSID: ");
  Serial.println(ssid);

  status = WiFi.begin(ssid, pass);
 while( status != WL_CONNECTED) {
    Serial.println("Couldn't get a wifi connection");
    Serial.println("Trying again");
    status = WiFi.begin(ssid, pass);
    delay(300);
  }
  if (status == WL_CONNECTED) {
    Serial.println("Connected to wifi");
    Serial.println("\nStarting connection...");
  }
 }
int temp(){

    int reading = analogRead(2);
    delay(500);
    reading = analogRead(2);  
    int temperature= reading/10;
    
    return temperature;

}

void loop() {
   client.connect(servername, 80);
   int tempe=temp();
   Serial.println("GET http://rolfing.berlin/tmp/arduino/write_get?F=t.txt&W=" + String(tempe));
   client.println("GET http://rolfing.berlin/tmp/arduino/write_get?F=t.txt&W=" + String(tempe));
   Serial.println("Temperature sent is " + String(tempe));
   delay(1000);
   client.stop();


 delay(1000);
}
