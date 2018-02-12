#include <Keypad.h>

char key[4];
int i = 0;
String pass;

const byte ROWS = 4; // Four rows
const byte COLS = 4; // columnsffff
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = {29, 28, 27, 26}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {25, 24, 23, 22}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing keypad module...");
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
  delay(1000);
}

void loop() {
  //Read Keypad
  keypad.getKey();
}

void keypadEvent(KeypadEvent eKey)
{

  switch (keypad.getState())
  {
    case PRESSED:

      key[i] = eKey;
      Serial.print("Enter: ");
      Serial.println(eKey);
      delay(10);
      i++;


      switch (eKey)
      {
        case '#': checkPassword(); delay(1); break;

        case '*': i=0; delay(1); break;

        default: delay(1);
      }
  }
}

void checkPassword()
{
  pass="";
  pass.concat(key[0]);
  pass.concat(key[1]);
  pass.concat(key[2]);
  pass.concat(key[3]);

  if(pass == "1234")
  {

    Serial.println("Accepted");
    i=0;
    delay(10);

  } else
  {
    Serial.println("Denied"); //if passwords wrong keep box locked
    i=0;
    delay(10);


  }

}
