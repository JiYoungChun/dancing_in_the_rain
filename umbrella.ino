#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6

#define NUM_LEDS 96

#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

#define trigPin1 34
#define echoPin1 35
#define trigPin2 32
#define echoPin2 33
#define trigPin3 30
#define echoPin3 31
#define trigPin4 2
#define echoPin4 3
#define trigPin5 4
#define echoPin5 5
#define trigPin6 7
#define echoPin6 8
#define trigPin7 9
#define echoPin7 10
#define trigPin8 12
#define echoPin8 13

int detectionCounter=0;
int detectionState = 0;
int lastDetectionState=0;

int groupLevel [8], g;
int i;
long duration, distance, Sensor1, Sensor2, Sensor3, Sensor4, Sensor5, Sensor6, Sensor7, Sensor8;

void setup() {

  Serial.begin(9600);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  //#if defined (__AVR_ATtiny85__)
  //  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  //#endif
  // End of trinket special code
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(trigPin5, OUTPUT);
  pinMode(echoPin5, INPUT);
  pinMode(trigPin6, OUTPUT);
  pinMode(echoPin6, INPUT);
  pinMode(trigPin7, OUTPUT);
  pinMode(echoPin7, INPUT);
  pinMode(trigPin8, OUTPUT);
  pinMode(echoPin8, INPUT);
}

void loop() {

  

  FadeInOut(255, 255, 200);
  
  SonarSensor(trigPin1, echoPin1);
  Sensor1 = distance;
  SonarSensor(trigPin2, echoPin2);
  Sensor2 = distance;
  SonarSensor(trigPin3, echoPin3);
  Sensor3 = distance;
  SonarSensor(trigPin4, echoPin4);
  Sensor4 = distance;
  SonarSensor(trigPin5, echoPin5);
  Sensor5 = distance;
  SonarSensor(trigPin6, echoPin6);
  Sensor6 = distance;
  SonarSensor(trigPin7, echoPin7);
  Sensor7 = distance;
  SonarSensor(trigPin8, echoPin8);
  Sensor8 = distance;

}
void SonarSensor(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

detectionState = distance;

if (detectionState!= lastDetectionState) {
  if (detectionState>1 && detectionState <30) {
  detectionCounter++;
//  Serial.println("on");
//  Serial.print("number of detection: ");
//  Serial.println(detectionCounter);
   

    byte input = Serial.read();

    Serial.print(Sensor1);
    Serial.print(" ");
    Serial.print(Sensor2);
    Serial.print(" ");
    Serial.print(Sensor3);
    Serial.print(" ");
    Serial.print(Sensor4);
    Serial.print(" ");
    Serial.print(Sensor5);
    Serial.print(" ");
    Serial.print(Sensor6);
    Serial.print(" ");
    Serial.print(Sensor7);
    Serial.print(" ");
    Serial.println(Sensor8);
   
  
} else {
//  Serial.println("off");
}
delay(50);
}

lastDetectionState = detectionState;

}


void set(byte channel, byte red, byte green, byte blue) {
//


  for (int i = channel * 12; i < channel * 12 + 12; i++ ) {
    setPixel(i, red, green, blue);
  }


}
void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
//
}

void FadeInOut( byte red, byte green, byte blue) {
  float r, g, b;

  for (int k = 0; k < 256; k = k + 1) {
    r = (k / 256.0) * red;
    g = (k / 256.0) * green;
    b = (k / 256.0) * blue;
    // setPixel(i, red, green, blue);
//
    setAll(r, g, b);
    if  (1 < Sensor1 && Sensor1 < 30) {
      set(0, 0, g, 255);
    }
    if  (1 < Sensor2 && Sensor2 < 30) {
      set(1, 0, g, 255);
    }
     if  (1 < Sensor3 && Sensor3 < 30) {
      set(2, 0, g, 255);
    }

     if  (1 < Sensor4 && Sensor4 < 30) {
      set(3, 0, g, 255);
    }

     if  (1 < Sensor5 && Sensor5 < 30) {
      set(4, 0, g, 255);
    }
     if  (1 < Sensor6 && Sensor6 < 30) {
      set(5, 0, g, 255);
    }
     if  (1 < Sensor7 && Sensor7 < 30) {
      set(6, 0, g, 255);
    }
     if  (1 < Sensor8 && Sensor8 < 30) {
      set(7, 0, g, 255);
    }
    
    
    strip.show();
  }

  for (int k = 255; k >= 0; k = k - 2) {
    r = (k / 256.0) * red;
    g = (k / 256.0) * green;
    b = (k / 256.0) * blue;
   // setPixel(i, red, green, blue);
      setAll(r, g, b);
    if  (1 < Sensor1 && Sensor1 < 30) {
      set(0, 0, g, 255);
    }
    if  (1 < Sensor2 && Sensor2 < 30) {
      set(1, 0, g, 255);
    }
     if  (1 < Sensor3 && Sensor3 < 30) {
      set(2, 0, g, 255);
    } if  (1 < Sensor4 && Sensor4 < 30) {
      set(3, 0, g, 255);
    }
     if  (1 < Sensor5 && Sensor5 < 30) {
      set(4, 0, g, 255);
    } if  (1 < Sensor6 && Sensor6 < 30) {
      set(5, 0, g, 255);
    }
     if  (1 < Sensor7 && Sensor7 < 30) {
      set(6, 0, g, 255);
    } if  (1 < Sensor8 && Sensor8 < 30) {
      set(7, 0, g, 255);
    }
    strip.show();
  }
}


void setPixel(int Pixel, byte red, byte green, byte blue) {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
#endif
}
