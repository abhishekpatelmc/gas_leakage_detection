#define BLYNK_PRINT Serial
#define relay 4
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#include<Wire.h>
char auth[]="";
char ssid[]="OnePlus2";
char pass[]="apollyon";
BlynkTimer timer;
const int gasPin=A0;
int buzzer=5;

void setup() {
  //Serial.begin(9600);
  // put your setup code here, to run once:
   pinMode(relay,OUTPUT);
 Serial.begin(115200);
  pinMode(gasPin,INPUT);
  pinMode(buzzer,OUTPUT);
  Blynk.begin(auth,ssid,pass);
  delay(10);
 
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(analogRead(gasPin));
int value=analogRead(gasPin);
  if (value==1024)
  {
    Serial.println("gas presence");
    digitalWrite(buzzer,HIGH);

    digitalWrite(relay,HIGH);
    delay(4000);
  }
  else
  {
    Serial.println("no gas");
    digitalWrite(buzzer,LOW);
    digitalWrite(relay,LOW);
    
  }


delay(1000);
Blynk.run();
timer.run();
}
