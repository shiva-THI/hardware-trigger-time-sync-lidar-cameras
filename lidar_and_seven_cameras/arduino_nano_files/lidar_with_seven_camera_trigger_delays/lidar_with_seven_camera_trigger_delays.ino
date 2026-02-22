// To use multiple pins of arduino nano as interrupt signals, 
// it is important to download PinChangeInterrupt.h header file and then add it to your arduino IDE. 
#include <PinChangeInterrupt.h>

// 7 pins to cretae 7 interrupts using one lidar signal
// pin number can be changed as per your own circuit design
const int lidarPin1 = 2;
const int lidarPin2 = 3;
const int lidarPin3 = 4;
const int lidarPin4 = 5;
const int lidarPin5 = 6;
const int lidarPin6 = 7;
const int lidarPin7 = 8;


// pin number can be changed as per your own circuit design
const int cameraPin1 = 9;  // camera 1
const int cameraPin2 = 10; // camera 2
const int cameraPin3 = 11; // camera 3
const int cameraPin4 = 12; // camera 4
const int cameraPin5 = A0; // camera 5
const int cameraPin6 = A1; // camera 6
const int cameraPin7 = A2; // camera 7

// time delay should be configured as per the geomerty of cameras on the sensor setup with respect to lidar
const unsigned long delay1 = 10; // ms
const unsigned long delay2 = 15; // ms
const unsigned long delay3 = 25; // ms
const unsigned long delay4 = 35; // ms
const unsigned long delay5 = 45; // ms
const unsigned long delay6 = 55; // ms
const unsigned long delay7 = 65; // ms


volatile unsigned long triggerTime1 = 0;
volatile unsigned long triggerTime2 = 0;
volatile unsigned long triggerTime3 = 0;
volatile unsigned long triggerTime4 = 0;
volatile unsigned long triggerTime5 = 0;
volatile unsigned long triggerTime6 = 0;
volatile unsigned long triggerTime7 = 0;

void setup() {
  pinMode(lidarPin1, INPUT);
  pinMode(lidarPin2, INPUT);
  pinMode(lidarPin3, INPUT);
  pinMode(lidarPin4, INPUT);
  pinMode(lidarPin5, INPUT);
  pinMode(lidarPin6, INPUT);
  pinMode(lidarPin7, INPUT);

  
  pinMode(cameraPin1, OUTPUT);
  pinMode(cameraPin2, OUTPUT);
  pinMode(cameraPin3, OUTPUT);
  pinMode(cameraPin4, OUTPUT);
  pinMode(cameraPin5, OUTPUT);
  pinMode(cameraPin6, OUTPUT);
  pinMode(cameraPin7, OUTPUT);

  attachPCINT(digitalPinToPCINT(lidarPin1), &lidarInterrupt1, RISING);
  attachPCINT(digitalPinToPCINT(lidarPin2), &lidarInterrupt2, RISING);
  attachPCINT(digitalPinToPCINT(lidarPin3), &lidarInterrupt3, RISING);
  attachPCINT(digitalPinToPCINT(lidarPin4), &lidarInterrupt4, RISING);
  attachPCINT(digitalPinToPCINT(lidarPin5), &lidarInterrupt5, RISING);
  attachPCINT(digitalPinToPCINT(lidarPin6), &lidarInterrupt6, RISING);
  attachPCINT(digitalPinToPCINT(lidarPin7), &lidarInterrupt7, RISING);

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

  if (triggerTime4 > 0 && currentTime - triggerTime4 >= delay4) {
    triggerCamera(cameraPin4);
    triggerTime4 = 0;
  }

  if (triggerTime5 > 0 && currentTime - triggerTime5 >= delay5) {
    triggerCamera(cameraPin5);
    triggerTime5 = 0;
  }

  if (triggerTime6 > 0 && currentTime - triggerTime6 >= delay6) {
    triggerCamera(cameraPin6);
    triggerTime6 = 0;
  }

  if (triggerTime7 > 0 && currentTime - triggerTime7 >= delay7) {
    triggerCamera(cameraPin7);
    triggerTime7 = 0;
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

void lidarInterrupt4() {
  triggerTime4 = millis();
}

void lidarInterrupt5() {
  triggerTime5 = millis();
}

void lidarInterrupt6() {
  triggerTime6 = millis();
}

void lidarInterrupt7() {
  triggerTime7 = millis();
}

// the pulse width and its polarity can be changed as per need. But should be well tested accordingly.
void triggerCamera(int pin) {
  digitalWrite(pin, HIGH);
  delay(5); // 5 ms pulse width
  digitalWrite(pin, LOW);
}
