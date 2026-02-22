// To use multiple pins of arduino nano as interrupt signals, 
// it is important to download PinChangeInterrupt.h header file and then add it to your arduino IDE. 
#include <PinChangeInterrupt.h>

// 3 pins to cretae 3 interrupts using one lidar signal
// pin number can be changed as per your own circuit design
const int lidarPin1 = 2;
const int lidarPin2 = 3;
const int lidarPin3 = 4;

// pin number can be changed as per your own circuit design
const int cameraPin1 = 7;
const int cameraPin2 = 6;
const int cameraPin3 = 5;

// time delay should be configured as per the geomerty of 
// cameras on the sensor setup with respect to lidar
const unsigned long delay1 = 25; // ms
const unsigned long delay2 = 45; // ms
const unsigned long delay3 = 60; // ms

volatile unsigned long triggerTime1 = 0;
volatile unsigned long triggerTime2 = 0;
volatile unsigned long triggerTime3 = 0;

void setup() {
  pinMode(lidarPin1, INPUT);
  pinMode(lidarPin2, INPUT);
  pinMode(lidarPin3, INPUT);
  
  pinMode(cameraPin1, OUTPUT);
  pinMode(cameraPin2, OUTPUT);
  pinMode(cameraPin3, OUTPUT);

  attachPCINT(digitalPinToPCINT(lidarPin1), &lidarInterrupt1, RISING);
  attachPCINT(digitalPinToPCINT(lidarPin2), &lidarInterrupt2, RISING);
  attachPCINT(digitalPinToPCINT(lidarPin3), &lidarInterrupt3, RISING);

}

void loop() {
  unsigned long currentTime = millis();

  if (triggerTime1 > 0 && currentTime - triggerTime1 >= delay1) {
    triggerCamera(cameraPin1);
    triggerTime1 = 0;
  }

  if (triggerTime2 > 0 && currentTime - triggerTime2 >= delay2) {
    triggerCamera(cameraPin2);
    triggerTime2 = 0;
  }

  if (triggerTime3 > 0 && currentTime - triggerTime3 >= delay3) {
    triggerCamera(cameraPin3);
    triggerTime3 = 0;
  }
}

void lidarInterrupt1() {
  triggerTime1 = millis();
}

void lidarInterrupt2() {
  triggerTime2 = millis();
}

void lidarInterrupt3() {
  triggerTime3 = millis();
}

// the pulse width and its polarity can be changed as per need. 
// But should be well tested accordingly.
void triggerCamera(int pin) {
  digitalWrite(pin, HIGH);
  delay(5); // 5 ms pulse width
  digitalWrite(pin, LOW);
}
