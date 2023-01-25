#include <LiquidCrystal.h>


int solVoltPin = 2;                 //Assign solar panel voltage to pin 2

int solCurrentPin = 4;              //Assign solar panel current sensor to pin 4
int greenLEDPin = 1;                //Assign green LED to pin 1
int redLEDPin = 2;                  //Assign red LED to pin 2


double solarKWH = 0;

unsigned long startMillis;          //Pilin Amper Saat ölçümü kullanım kapasitesi
unsigned long endMillis;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  //Assign LCD screen pins, as per LCD shield requirements

void setup() 
{ 
  pinMode(greenLEDPin, OUTPUT);  //Define the pin functions
  pinMode(redLEDPin, OUTPUT);
 
  lcd.begin(16,2);              //Start the LCD, columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();
  lcd.setCursor(0,0);           //Set cursor to column 0, row 0 (the first row)
  lcd.print("Van Life");
  lcd.setCursor(0,1);           //Set cursor to column 0, row 1 (the second row)
  lcd.print("Power Info");
  startMillis = millis();
}

void loop() 
{ 
  
  double solarVoltage = 0;
  double solarCurrent = 0;
  solarVoltage = 20*analogRead(solVoltPin)/1023;            //Read the solar panel voltage
  solarCurrent = 30*(analogRead(solCurrentPin)-511)/512;    //Read the solar panel current
  double solPower = solarVoltage*solarCurrent;
  if(solPower>=0)                                   //Güneş enerjisi ÜRETİLİYOR
  {
    digitalWrite(greenLEDPin, HIGH);
  }
  else
  {
    digitalWrite(greenLEDPin, LOW);
  }
  
  
 
  solarKWH = solarKWH + (solPower * (time/60/60/1000000));       //Başlangıçtan bu yana üretilen güneş paneli kWh'yi hesaplayın
  startMillis = millis();
  delay (4000);
  
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Solar Panel");
  delay (1000);
  lcd.clear();
  lcd.setCursor(0,0);           // Tüm güneş paneli verilerini görüntüler
  lcd.print(solarVoltage);
  lcd.print("V");
  lcd.setCursor(9,0);
  lcd.print(solarCurrent);
  lcd.print("A");
  lcd.setCursor(0,1);
  lcd.print(solPower);
  lcd.print("W");
  lcd.setCursor(9,1);
  lcd.print(solarKWH);
  lcd.print("kWh");
}





---------------------------------------------------------------------------------------------------------------------------------------------------------------

s


---------------------------------------------------------------------------------------------------------------------------------------------------------------