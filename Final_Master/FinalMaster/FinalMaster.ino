#include <Keypad.h>
#include <LiquidCrystal.h>
#include<Wire.h>

LiquidCrystal lcd(5,4,3,2,1,0);

#define Password_Lenght 7 // Give enough room for six chars + NULL char

    

char Data[Password_Lenght]; // 6 is the number of chars it can hold + the null char = 7
char Master[Password_Lenght] = "123456";
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3','A'},
  {'4', '5', '6','B'},
  {'7', '8', '9','C'},
  {'*', '0', '#','D'}
};
bool door = true;

byte rowPins[ROWS] = {13,12,11,10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9,8,7,6}; //connect to the column pinouts of the keypad

Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); //initialize an instance of class NewKeypad

void setup()
{
  Wire.begin();
  lcd.begin(16, 2);
  lcd.print("      Car    ");
  lcd.setCursor(0, 1);
  lcd.print("--Look project--");
  delay(3000);
  lcd.clear();

}

void loop()
{
  if (door == 0)
  {
    customKey = customKeypad.getKey();

    if (customKey == '#')

    {
      lcd.clear();
      lcd.print("     Reset ");
      delay(3000);
      Wire.beginTransmission(9);
      Wire.write('R');
      Wire.endTransmission();
      door = 1;
    }
  }

  else Open();
}

void clearData()
{
  while (data_count != 0)
  { // This can be used for any array size,
    Data[data_count--] = 0; //clear array for new data
  }
  return;
}

void Open()
{
  lcd.setCursor(0, 0);
  lcd.print(" Enter Password");
  
  customKey = customKeypad.getKey();
  if (customKey) // makes sure a key is actually pressed, equal to (customKey != NO_KEY)
  {
    Data[data_count] = customKey; // store char into data array
    lcd.setCursor(data_count, 1); // move cursor to show each new char
    lcd.print(Data[data_count]); // print char at said cursor
    data_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered
  }

  if (data_count == Password_Lenght - 1) // if the array index is equal to the number of expected chars, compare data to master
  {
    if (!strcmp(Data, Master)) // equal to (strcmp(Data, Master) == 0)
    {
      lcd.clear();
      lcd.print(" Access Granted");
      Wire.beginTransmission(9);
      Wire.write('Y');
      Wire.endTransmission();
      door = 0;
    }
    else
    {
      lcd.clear();
      lcd.print(" Access Denied");
      Wire.beginTransmission(9);
      Wire.write('N');
      Wire.endTransmission();
      delay(3000);
      door = 1;
     
    }
    clearData();
  }
}
