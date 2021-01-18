/*
*/
#include "Bounce2.h";

#define COOL_WATER_PIN 12
#define HOT_WATER_PIN 13
int cool_water_counter = 0;
int hot_water_counter = 0;
long lastDebounce_cool = 0;
long lastDebounce_hot = 0;
long debounceDelay = 500; 

void ICACHE_RAM_ATTR cool_trigger() {
 if ((millis() - lastDebounce_cool) > debounceDelay) 
  { 
    cool_water_counter ++;
    Serial.println("cool_water_counter: " + (String)(cool_water_counter));
    lastDebounce_cool = millis();
  }
}

void ICACHE_RAM_ATTR hot_trigger() {  
 if ((millis() - lastDebounce_hot) > debounceDelay) 
  { 
    hot_water_counter ++;
    Serial.println("hot_water_counter: " + (String)(hot_water_counter));
    lastDebounce_hot = millis();
  }
}


void setup() {
  Serial.begin(115200);
  Serial.println("Water meter satrdted v 1.0.0");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(COOL_WATER_PIN, INPUT_PULLUP);
  pinMode(HOT_WATER_PIN, INPUT_PULLUP);
  digitalWrite(COOL_WATER_PIN, HIGH);
  digitalWrite(HOT_WATER_PIN, HIGH);
  attachInterrupt(digitalPinToInterrupt(COOL_WATER_PIN), cool_trigger, FALLING);
  attachInterrupt(digitalPinToInterrupt(HOT_WATER_PIN),  hot_trigger,  FALLING);
}







void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
