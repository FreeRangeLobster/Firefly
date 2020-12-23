#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 116

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 3
#define CLOCK_PIN 13
#define LED 2
#define JoystickLamp 27


// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6) 
const int potPin = 34;

// Define the array of leds
CRGB leds[NUM_LEDS];
int ButtonSwitchesID [5]={19,23,35,36,39};
int ButtonLampsID [5]={4,5,16,17,18};
int JoystickID[4]={25,26,32,33};


void setup() {  

  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical    
  //Stayalive Signal
  pinMode(LED,OUTPUT);

  pinMode(ButtonLampsID[0],OUTPUT);
  pinMode(ButtonLampsID[1],OUTPUT);
  pinMode(ButtonLampsID[2],OUTPUT);
  pinMode(ButtonLampsID[3],OUTPUT);
  pinMode(ButtonLampsID[4],OUTPUT);

   //Joystick lights
  pinMode(JoystickLamp,OUTPUT);

  //Buttons
  pinMode(ButtonSwitchesID[0],INPUT_PULLUP);
  pinMode(ButtonSwitchesID[1],INPUT_PULLUP);
  pinMode(ButtonSwitchesID[2],INPUT_PULLUP);
  pinMode(ButtonSwitchesID[3],INPUT_PULLUP);
  pinMode(ButtonSwitchesID[4],INPUT_PULLUP);

  //Joystick
  pinMode(JoystickID[0],INPUT_PULLUP);
  pinMode(JoystickID[1],INPUT_PULLUP);
  pinMode(JoystickID[2],INPUT_PULLUP);
  pinMode(JoystickID[3],INPUT_PULLUP);

  //Turn the LED on, then pause
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(10);

  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  
  //Serial port for debugging
  Serial.begin(115200);
  Serial.println("Restarted");
  Serial.println("");

}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

int i;
int potValue;
int nBrightness=255;

enum eStates{eInitialise =0,
             eButtonRed =1,
             eButtonBlue=2,
             eButtonYellow=3,
             eButtonGreen=4,
             eButtonWhite=5,
             eJoystickUp=6,
             eJoystickDown=7,
             eJoystickLeft=8,
             eJoystickRight=9,
             eRandomLights=10,
             eRightLights=11,
             eLeftLights=12};

int nState=eInitialise;

void ReadPotionemeter(){
  potValue = analogRead(potPin);
  nBrightness=potValue/16;
  
}

void loop() { 

  delay(600);
  static uint8_t hue = 0;
  digitalWrite(JoystickLamp, HIGH);    
       
  //Infinite loop
  do {  
    // digitalWrite(ButtonLampsID[0], HIGH);
    // digitalWrite(ButtonLampsID[1], HIGH);
    // digitalWrite(ButtonLampsID[2], HIGH);
    // digitalWrite(ButtonLampsID[3], HIGH);
    // digitalWrite(ButtonLampsID[4], HIGH);
    // digitalWrite(JoystickLamp, HIGH);

    // if(digitalRead(JoystickID[0])==LOW) {
    //   digitalWrite(ButtonLampsID[0], HIGH);
    // }
    // else{
    //   digitalWrite(ButtonLampsID[0], LOW);
    // }

    for(int i = 0; i < NUM_LEDS; i++) {
      // Set the i'th led to red 
      leds[i] = CHSV(hue++, 255, nBrightness);
      // Show the leds
      FastLED.show(); 
      // now that we've shown the leds, reset the i'th led to black
      // leds[i] = CRGB::Black;
      fadeall();
      // Wait a little bit before we loop around and do it again
      delay(5);
      ReadPotionemeter();
    }

         
   
    // digitalWrite(JoystickLamp, LOW); 

//    Now go in the other direction.  
	  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
      // Set the i'th led to red 
      leds[i] = CHSV(hue++, 255, nBrightness);
      // Show the leds
      FastLED.show();
      // now that we've shown the leds, reset the i'th led to black
      // leds[i] = CRGB::Black;
      fadeall();
      // Wait a little bit before we loop around and do it again
      delay(5);
      ReadPotionemeter();
	  }

    
    delay(50);
    Serial.println(potValue);


  for(int i=0;i<5;i++){
    if(digitalRead(ButtonSwitchesID[i])==LOW) {
      //digitalWrite(ButtonLampsID[i], HIGH);
      Serial.print("Button ");
      Serial.println(i);
    }
    else{
      //digitalWrite(ButtonLampsID[i], LOW);
    }
  }

  for(int i=0;i<4;i++){
    if(digitalRead(JoystickID[i])==LOW) {
      //digitalWrite(ButtonLampsID[i], HIGH);
      Serial.print("Joy ");
      Serial.println(i);
    }
    else{
      //digitalWrite(ButtonLampsID[i], LOW);
    }
  }

  //Buttons
  for(int i=0;i<5;i++){
    if(digitalRead(ButtonSwitchesID[i])==LOW) {
      //digitalWrite(ButtonLampsID[i], HIGH);
      Serial.print("Button ");
      Serial.println(i);
      nState=i+1;
    }
    else{
      //digitalWrite(ButtonLampsID[i], LOW);
    }
  }

  //Joystick
  for(int i=0;i<4;i++){
    if(digitalRead(JoystickID[i])==LOW) {
      //digitalWrite(ButtonLampsID[i], HIGH);
      Serial.print("Joy ");
      Serial.println(i);
      nState=i+1+5;
    }
    else{
      //digitalWrite(ButtonLampsID[i], LOW);
    }
  }


  switch (nState){
    case eInitialise:
    digitalWrite(ButtonLampsID[0], LOW);
    digitalWrite(ButtonLampsID[1], LOW);
    digitalWrite(ButtonLampsID[2], LOW);
    digitalWrite(ButtonLampsID[3], LOW);
    digitalWrite(ButtonLampsID[4], LOW);
    //i=0;
    //nState=eRightLights;
    
      /* code */
      break;

    case eButtonRed:
      //Turn button red
      digitalWrite(ButtonLampsID[0], HIGH);

      //Turn the leds RED
      nState=eInitialise;

    break;

    case eButtonBlue:
      //Turn button red
      digitalWrite(ButtonLampsID[1], HIGH);
      nState=eInitialise;
    break;

    case eButtonYellow:
      //Turn button red
      digitalWrite(ButtonLampsID[2], HIGH);
      nState=eInitialise;
    break;

    case eButtonGreen:
      //Turn button red
      digitalWrite(ButtonLampsID[3], HIGH);
      nState=eInitialise;  
    break;

    case eButtonWhite:
      //Turn button red
      digitalWrite(ButtonLampsID[4], HIGH);
      nState=eInitialise;
    break;

    case eJoystickUp:
      nState=eInitialise;
    break;

    case eJoystickDown:
      nState=eInitialise;
    break;

    case eJoystickLeft:
      nState=eInitialise;
    break;

    case eJoystickRight:
      nState=eInitialise;
    break;

    case eRightLights:
      i = i++;      
      if (i< NUM_LEDS){
          //for(int i = 0; i < NUM_LEDS; i++) {
          // Set the i'th led to red 
          leds[i] = CHSV(hue++, 255, nBrightness);
          // Show the leds
          FastLED.show(); 
          // now that we've shown the leds, reset the i'th led to black
          // leds[i] = CRGB::Black;
          fadeall();
          // Wait a little bit before we loop around and do it again
          delay(5);
          ReadPotionemeter();
      }else{
        i=NUM_LEDS;
        nState=eLeftLights;
      }
      break;

        
    case eLeftLights:
      i--;
      if (i>=0){
                 // for(int i = (NUM_LEDS)-1; i >= 0; i--) {
        // Set the i'th led to red 
        leds[i] = CHSV(hue++, 255, nBrightness);
        // Show the leds
        FastLED.show();
        // now that we've shown the leds, reset the i'th led to black
        // leds[i] = CRGB::Black;
        fadeall();
        // Wait a little bit before we loop around and do it again
        delay(5);
        ReadPotionemeter();
      }
      else{
        i=0;
        nState=eRightLights;
      }




    break;
    
    default:
    break;
    }

  } while (true);
}
