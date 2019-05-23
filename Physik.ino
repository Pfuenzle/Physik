#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4 // not used / nicht genutzt bei diesem Display
Adafruit_SSD1306 display(OLED_RESET);

//BASE http://blog.simtronyx.de/ein-096-zoll-oled-display-i%C2%B2c-mit-128x64-pixel-und-ein-arduino/

const int buttonPinPlus = 2;
int buttonStatePlus = 0;
const int buttonPinMinus = 3;
int buttonStateMinus = 0;

void setup()   {                

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  randomSeed(analogRead(0));

  pinMode(buttonPinPlus, INPUT);
  pinMode(buttonPinMinus, INPUT);
}

#define DRAW_DELAY 118
#define D_NUM 47

int hertz = 1;

void loop()
{
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    
    display.println("Aktuelle Hertz-Anzahl: ");
    display.setCursor(2, 0);
    display.println(hertz);

    buttonStatePlus = digitalRead(buttonPinPlus);
    buttonStateMinus = digitalRead(buttonPinMinus);

    if (buttonStatePlus == HIGH) {
      hertz++;
    }
    if (buttonStateMinus == HIGH) {
      hertz--;
    }
    delay(1000); 
}

/*void loop() {
  
  display.clearDisplay();
  
  // set text color / Textfarbe setzen
  display.setTextColor(WHITE);
  // set text size / Textgroesse setzen
  display.setTextSize(1);
  // set text cursor position / Textstartposition einstellen
  display.setCursor(1,0);
  // show text / Text anzeigen
  display.println("OLED - Display - Test");
  display.setCursor(14,56);
  display.println("blog.simtronyx.de");
  display.setTextSize(2);
  display.setCursor(34,15);
  display.println("Hello");
  display.setCursor(30,34);
  display.println("World!");
  display.display();
  delay(8000);
  display.clearDisplay();
  
  // invert the display / Display invertieren
  display.invertDisplay(true);
  delay(2000); 
  display.invertDisplay(false);
  delay(1000); 
  
  // draw some random pixel / zufaellige Pixel anzeigen
  for(i=0;i<380;i++){
    display.drawPixel(random(128),random(64), WHITE);
    display.display();
  }
  delay(DRAW_DELAY);
  display.clearDisplay();

  // draw some random lines / zufaellige Linien anzeigen
  for(i=0;i<D_NUM;i++){
    display.drawLine(random(128),random(64),random(128),random(64), WHITE);
    display.display();
    delay(DRAW_DELAY);
    display.clearDisplay();   
  }

  // draw some random triangles / zufaellige Dreiecke anzeigen
  for(i=0;i<D_NUM;i++){
    if(random(2))display.drawTriangle(random(128),random(64),random(128),random(64), random(128),random(64), WHITE); // normal
    else display.fillTriangle(random(128),random(64),random(128),random(64), random(128),random(64), WHITE);     // filled / ausgefuellt
    display.display();
    delay(DRAW_DELAY);
    display.clearDisplay();   
  }

  // draw some random rectangles / zufaellige Rechtecke anzeigen
  for(i=0;i<D_NUM;i++){
    int rnd=random(4);
    if(rnd==0)display.drawRect(random(88),random(44),random(40),random(20), WHITE);               // normal
    else if(rnd==1)display.fillRect(random(88),random(44),random(40),random(20), WHITE);            // filled / ausgefuellt
    else if(rnd==2)display.drawRoundRect(random(88),random(44),random(30)+10,random(15)+5,random(5), WHITE);  // normal with rounded edges / normal mit abgerundeten Ecken
    else display.fillRoundRect(random(88),random(44),random(30)+10,random(15)+5,random(5), WHITE);        // filled with rounded edges / ausgefuellt mit  mit abgerundeten Ecken
    display.display();
    delay(DRAW_DELAY);
    display.clearDisplay();   
  }

  // draw some random circles / zufaellige Kreise anzeigen
  for(i=0;i<D_NUM;i++){
    if(random(2))display.drawCircle(random(88)+20,random(44)+20,random(10), WHITE); // normal
    else display.fillCircle(random(88)+20,random(44)+20,random(10), WHITE);     // filled / ausgefuellt
    display.display();
    delay(DRAW_DELAY);
    display.clearDisplay();   
  }

}*/
