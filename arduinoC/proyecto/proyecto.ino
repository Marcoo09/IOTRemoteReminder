#include <LiquidCrystal_I2C.h> // Libreria LCD_I2C

LiquidCrystal_I2C lcd(0x27,16,2) ; // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

const int TrigPin = 6; //define los pines a utilizar
const int EchoPin = 5;
float cm;
char title[100]; //Initialized variable to store recieved data
char ant[100] = "";
//Contstants to use with passive buzzer
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

const int buzzerPin = 8;
const int ledPin1 = 12;
const int ledPin2 = 13;
int counter = 0;
bool sound = false;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(11,OUTPUT);
  pinMode(9,INPUT);
  pinMode(TrigPin, OUTPUT); //define cual es entrada y cual salida
  pinMode(EchoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
Serial.readBytes(title,100); //Read the serial data and store in var
digitalWrite(11,HIGH);
digitalWrite(TrigPin, LOW);       
delayMicroseconds(2);
digitalWrite(TrigPin, HIGH); //Genera un pulso ultrasónico...
delayMicroseconds(10); //...que dura 10 micro segundos
digitalWrite(TrigPin, LOW);
float c = 340.0; // velocidad del sonido en m/s
float t = pulseIn(EchoPin, HIGH); //microsegundos
float distance = c * t / 2 / 1000000; //distancia

Serial.print("Distancia\t=\t");
Serial.print(distance,2); //2 decimales
Serial.print("m");
Serial.println();
lcd.clear();
if(strcmp(title,ant) != 0){
  sound = false;
}
/*if(distance <= 0.25 && distance > 0.10 && !sound){
  starWarsSound();
  sound = true;
}else if(distance <= 0.50 && distance > 0 && sound && strlen(title) > 0){
   lcd.print("Recuerda:");
   lcd.setCursor (0,1);  
   lcd.print(title);
   lcd.display();   
     //lcd.autoscroll();
   sound = false;
   delay(2000);
}*/
if(distance <= 0.50 && distance >= 0 && strlen(title) > 0){   
   lcd.print("Recuerda:");
   lcd.setCursor (0,1);  
   lcd.print(title);
   lcd.display();  
   if(!sound){
    starWarsSound();
    strcpy(ant,title);
    sound = true;
   } 
   
}
/*if(strlen(title) > 0){
   lcd.print("Recuerda:");
   lcd.setCursor (0,1);  
   lcd.print(title);
   lcd.display();   
   for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(250);
  }*//*
   lcd.setCursor(0,0);
   lcd.print("Recuerda:");
   lcd.setCursor (0,1);  
   lcd.print(title);
   sound = false;
   delay(2000);
}*/
delay(5000);
}

void beep(int note, int duration)
{
  tone(buzzerPin, note, duration);
  delay(duration);
  noTone(buzzerPin);
  delay(50);
  counter++;
}

void starWarsSound(){
  firstSection();
  delay(500);
}


void firstSection()
{
  beep(a, 500);
  beep(a, 500);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);

  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);
}

void secondSection()
{
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);
  beep(fSH, 250);

  delay(325);

  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);
  beep(cSH, 175);
  beep(cH, 125);
  beep(b, 125);
  beep(cH, 250);

  delay(350);
}
