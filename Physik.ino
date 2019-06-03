#include "Stepper.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4 // not used / nicht genutzt bei diesem Display
Adafruit_SSD1306 display(OLED_RESET);

int speed = 60; //ein Hertz

int speedToHertz()
{
  return speed / 60;
}

void setSpeed(int speedIn)
{
  speed = speedIn;
}

void addSpeed(int speedIn)
{
  if(speed + speedIn <= 135)
    setSpeed(speed + speedIn);
}

void remSpeed(int speedIn)
{
  if(speed + speedIn >= 0)
    setSpeed(speed - speedIn);
}

const int buttonPinPlus = 0;
int buttonStatePlus = 0;
const int buttonPinMinus = 5;
int buttonStateMinus = 0;

void buttonPlus()
{
  addSpeed(1);
  Serial.println("Button plus pressed");
}

void buttonMinus()
{
  remSpeed(1);
  Serial.println("Button minus pressed");
}

#define DRAW_DELAY 118
#define D_NUM 47

const int stepsU = 200;

Stepper myStepper(stepsU, 8, 9, 10, 11);

void setup() {

    Serial.begin(9600);
  // put your setup code here, to run once:

  pinMode(buttonPinPlus, INPUT_PULLUP);
  pinMode(buttonPinMinus, INPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  randomSeed(analogRead(0));

}

long old = 0;
long _new = 0;

long diff = 0;

void updateDisplay()
{
  
    display.clearDisplay();
    display.setTextColor(WHITE);

    display.setCursor(1,0);
    display.setTextSize(2);
    display.println("Frequenz:");
    display.setCursor(2, 15);
    display.setTextSize(2.6);
    display.println(speed);

    display.display();
}

void loop() {
/*
 * Motor
 */
  
    myStepper.setSpeed(speed);
    // put your main code here, to run repeatedly:
    old = millis();
    myStepper.step(200); //200 = 1 Umdrehung
    _new = millis();
    diff = _new - old;
    Serial.println("Diff: ");
    Serial.println(diff);

    buttonStatePlus = digitalRead(buttonPinPlus);
    buttonStateMinus = digitalRead(buttonPinMinus);
    
    if (buttonStateMinus == HIGH) {
      buttonMinus();
      updateDisplay();
    }

    if (buttonStatePlus == HIGH) {
      buttonPlus();
      updateDisplay();
    }
                     
}
