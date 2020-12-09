#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 64

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 3
#define CLOCK_PIN 13
#define LED 2
#define ButtonLamp1 19
#define ButtonSW1 4
#define pintest 23

  // Potentiometer is connected to GPIO 34 (Analog ADC1_CH6) 
const int potPin = 34;

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {     
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical    
  //Stayalive Signal
  pinMode(LED,OUTPUT);

  //Joystick lights
  pinMode(pintest,OUTPUT);

//Buttons
  pinMode(ButtonLamp1,OUTPUT);
  pinMode(ButtonSW1,INPUT_PULLUP);


    // Turn the LED on, then pause
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(10);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  
  Serial.begin(115200);
  Serial.println("Restarted");
  Serial.println("");

}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void loop() { 
  
 static uint8_t hue = 0;

// variable for storing the potentiometer value
//int potValue = 0;

    if(digitalRead(ButtonSW1)==LOW) {
      digitalWrite(ButtonLamp1, HIGH);
      }
     else
      {
        digitalWrite(ButtonLamp1, LOW);
      }
      
    

  //Infinite loop
  do {  
    for(int i = 0; i < NUM_LEDS; i++) {
      // Set the i'th led to red 
      leds[i] = CHSV(hue++, 255, 50);
      // Show the leds
      FastLED.show(); 
      // now that we've shown the leds, reset the i'th led to black
      // leds[i] = CRGB::Black;
      fadeall();
      // Wait a little bit before we loop around and do it again
      delay(100);
    }

    // Now go in the other direction.  
	  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
      // Set the i'th led to red 
      leds[i] = CHSV(hue++, 255, 50);
      // Show the leds
      FastLED.show();
      // now that we've shown the leds, reset the i'th led to black
      // leds[i] = CRGB::Black;
      fadeall();
      // Wait a little bit before we loop around and do it again
      delay(10);
	}

    //Joystick lights
    digitalWrite(LED,HIGH);
    digitalWrite(pintest,HIGH);
    delay(1500);
    digitalWrite(LED,LOW);
    digitalWrite(pintest,LOW);
    delay(1500);

    //Read inputs

    //Read ADC
    potValue = analogRead(potPin);
    Serial.println(potValue);
    delay(500);


  }
  while (true);

 

}
