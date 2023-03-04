#include <IBusBM.h>
IBusBM IBus; // IBus object

#include <Servo.h>

Servo servo1;
Servo servo2;

int ch1;
int ch2;
int ch3;
int ch4;
int ch5;
int ch6;
int ch7;
int ch8;
int ch9;
int ch10;

float drive1;
float drive2;
float drive3;

float out1;
float out2;
float out3;
float out1a;
float out2a;
float out3a;

unsigned long currentMillis;
long previousMillis = 0;    // set up timers


void setup() {
  Serial.begin(115200);   // remove comment from this line if you change the Serial port in the next line
  IBus.begin(Serial3, IBUSBM_NOTIMER);    // change to Serial1 or Serial2 port when required

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  servo1.attach(42);
  servo2.attach(44);

  
}

void loop() {

    IBus.loop();

    ch1 = IBus.readChannel(0); // get latest value for servo channel 0
    //ch2 = IBus.readChannel(1); // get latest value for servo channel 1
    //ch3 = IBus.readChannel(2); // get latest value for servo channel 3
    ch4 = IBus.readChannel(3); // get latest value for servo channel 4
    ch5 = IBus.readChannel(4); // get latest value for servo channel 5
    //ch6 = IBus.readChannel(5); // get latest value for servo channel 6
    //ch7 = IBus.readChannel(6); // get latest value for servo channel 7
    //ch8 = IBus.readChannel(7); // get latest value for servo channel 8
    //ch9 = IBus.readChannel(8); // get latest value for servo channel 9
    //ch10 = IBus.readChannel(9); // get latest value for servo channel 10

    currentMillis = millis();
    if (currentMillis - previousMillis >= 10) {  // start timed event
          
        previousMillis = currentMillis;

        out1 = thresholdStick(ch4);
        out2 = thresholdStick(ch1);
        out3 = thresholdStick(ch5);

        // drive motor
                
        if (out1 > 0) {
            analogWrite(7, out1);
            analogWrite(6, 0);
        }

        else if (out1 < 0) {
            out1a = abs(out1);
            analogWrite(6, out1a);
            analogWrite(7, 0);
        }

        else {
            analogWrite(7, 0);
            analogWrite(6, 0);
        }

        

        servo1.write(0 + out3);
        servo2.write(180 + out3);        

    }

}


