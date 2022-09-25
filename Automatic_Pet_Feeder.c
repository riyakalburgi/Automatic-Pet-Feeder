#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "2oReKW--MKgmuahvpKhH9ujcK2dsDhjr";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "good luck bud";
char pass[] = "hellodemocheck";

Servo servo;
int frequency=1000; //Specified in Hz
int buzzPin=2;              
int timeOn=5000; //specified in milliseconds
int timeOff=1000; //specified in millisecods

BLYNK_WRITE(V3)
{
  int button=param.asInt();
  if (button==1){
servo.write(0);
  delay(1000);
servo.write(90);
  tone(buzzPin, frequency);
  delay(timeOn);
noTone(buzzPin);
  delay(timeOff); 
  // Make servo go to 90 degrees

  button=0;
  }
}

void setup()
{
// Debug console
Serial.begin(9600);

Blynk.begin(auth, ssid, pass);

servo.attach(13);
}

void loop()
{
Blynk.run();
}
