
#define XINB

// COMMENT OUT BEFORE FINAL COMPILATION
// This is for testing only 
// #define SERIAL

#include <Adafruit_PCF8574.h>

#ifdef XINB 
  #include <XInput.h>
#endif


/* Example for 8 input buttons that are connected from the GPIO expander pins to ground.
 * Note the buttons must be connected with the other side of the switch to GROUND. There is
 * a built in pull-up 'resistor' on each input, but no pull-down resistor capability.
 */

#define CONSOLE_BUTTON_A   0
#define CONSOLE_BUTTON_B   1

#define CONSOLE_BUTTON_C   2
#define CONSOLE_BUTTON_D   3

#define CONSOLE_BUTTON_E   4
#define CONSOLE_BUTTON_F   5

#define CONSOLE_BUTTON_G   6
#define CONSOLE_BUTTON_H   7

#define CONSOLE_BUTTON_I   8
#define CONSOLE_BUTTON_J   9

#define CONSOLE_BUTTON_K  10
#define CONSOLE_BUTTON_L  11

#define CONSOLE_BUTTON_LEVEL_1  12
#define CONSOLE_BUTTON_LEVEL_2  13
#define CONSOLE_BUTTON_LEVEL_3  14
#define CONSOLE_BUTTON_LEVEL_4  15


// Don't modify

#define TOTAL_MODULES 3

const int valid_modules[] = {0x20, 0x21, 0x22};

const int module_line[] = {0, 0, 0, 0, 0, 0, 0, 0,
                         1, 1, 1, 1, 1, 1, 1, 1,
                         2, 2, 2, 2, 2, 2, 2, 2};
                       
const int pin_line[] =    {0, 1, 2, 3, 4, 5, 6, 7,
                          0, 1, 2, 3, 4, 5, 6, 7,
                          0, 1, 2, 3, 4, 5, 6, 7};



struct JoystickMapping {
    double key;
    int16_t value;
};

// Define the lookup table
const JoystickMapping joystickToIntMap[] = {
    {-1.0, -32767}, {-0.9, -29492}, {-0.8, -26215}, {-0.7, -22938},
    {-0.6, -19661}, {-0.5, -16384}, {-0.4, -13107}, {-0.3, -9831},
    {-0.2, -6554},  {-0.1, -3277},  {0.0, 0},       {0.1, 3277},
    {0.2, 6554},    {0.3, 9830},    {0.4, 13107},   {0.5, 16384},
    {0.6, 19661},   {0.7, 22937},   {0.8, 26215},   {0.9, 29491},
    {1.0, 32767}
};

// Function to lookup a value in the table
int16_t getJoystickValue(double key) {
    for (const auto& entry : joystickToIntMap) {
        if (entry.key == key) {
            return entry.value;
        }
    }
    return 0;
}

Adafruit_PCF8574 pcf[TOTAL_MODULES];
int module_index[TOTAL_MODULES];

bool pressed = false; 

void setup() {

    #ifdef SERIAL
      Serial.begin(9600);
      Serial.println("Adafruit PCF8574 button read test");
    #endif 

  #ifdef XINB
    XInput.begin();
  #endif

  for (int i = 0; i < TOTAL_MODULES; i++)
  {
    #ifdef SERIAL          
        if (!pcf[i].begin(valid_modules[i], &Wire))
        {
          Serial.print("Couldn't find PCF8574 on module ");
          Serial.println(valid_modules[i]);
        }
        else
        {
          for (uint8_t j=0; j<8; j++) 
          {
            pcf[i].pinMode(j, INPUT);
          }
          delay(1000);
        }
    #else
      pcf[i].begin(valid_modules[i], &Wire);
      for (uint8_t j=0; j<8; j++) 
      {
        pcf[i].pinMode(j, INPUT_PULLUP);
      }
    #endif 
  }

}


void loop() {

  // USE THIS!!!!! 
  #ifdef XINB
    // Read button
    bool poseA = readConsole(CONSOLE_BUTTON_A);
    bool poseB = readConsole(CONSOLE_BUTTON_B);
    bool poseC = readConsole(CONSOLE_BUTTON_C);
    bool poseD = readConsole(CONSOLE_BUTTON_D);
    bool poseE = readConsole(CONSOLE_BUTTON_E);
    bool poseF = readConsole(CONSOLE_BUTTON_F);
    bool poseG = readConsole(CONSOLE_BUTTON_G);
    bool poseH = readConsole(CONSOLE_BUTTON_H);
    bool poseI = readConsole(CONSOLE_BUTTON_I);
    bool poseJ = readConsole(CONSOLE_BUTTON_J);
    bool poseK = readConsole(CONSOLE_BUTTON_K);
    bool poseL = readConsole(CONSOLE_BUTTON_L);

    if (poseA) {
      XInput.setJoystick(JOY_LEFT, getJoystickValue(0.1), getJoystickValue(0.1));
    }
    else if (poseB) {
      XInput.setJoystick(JOY_LEFT, getJoystickValue(0.2), getJoystickValue(0.2));
    }
    else if (poseC) {
      XInput.setJoystick(JOY_LEFT, getJoystickValue(0.3), getJoystickValue(0.3));
    }
    else if (poseD) {
      XInput.setJoystick(JOY_LEFT, getJoystickValue(0.4), getJoystickValue(0.4));
    }
    else if (poseE) {
      XInput.setJoystick(JOY_LEFT, getJoystickValue(0.5), getJoystickValue(0.5));
    }
    else if (poseF) {
      XInput.setJoystick(JOY_LEFT, getJoystickValue(0.6), getJoystickValue(0.6));
    }
    else if (poseG) {
      XInput.setJoystick(JOY_LEFT, getJoystickValue(0.7), getJoystickValue(0.7));
    }
    else if (poseH) {
      XInput.setJoystick(JOY_LEFT, getJoystickValue(0.8), getJoystickValue(0.8));
    }
    else if (poseI) {
      XInput.setJoystick(JOY_LEFT, getJoystickValue(0.9), getJoystickValue(0.9));
    }
    else if (poseJ) {
      XInput.setJoystick(JOY_LEFT, getJoystickValue(-0.1), getJoystickValue(-0.9));
    }
    else if (poseK) {
      XInput.setJoystick(JOY_LEFT, getJoystickValue(-0.2), getJoystickValue(-0.8));
    }
    else if (poseL) {
      XInput.setJoystick(JOY_LEFT, getJoystickValue(-0.3), getJoystickValue(-0.7));
    }
    else {
      XInput.setJoystick(JOY_LEFT, 0, 0);
    }

    bool level1 = readConsole(CONSOLE_BUTTON_LEVEL_1);
    bool level2 = readConsole(CONSOLE_BUTTON_LEVEL_2);
    bool level3 = readConsole(CONSOLE_BUTTON_LEVEL_3);
    bool level4 = readConsole(CONSOLE_BUTTON_LEVEL_4);

    XInput.setButton(DPAD_DOWN, level1);
    XInput.setButton(DPAD_LEFT, level2);
    XInput.setButton(DPAD_RIGHT, level3);
    XInput.setButton(DPAD_UP, level4);
    // Set XBOX button
    //XInput.setButton(BUTTON_B, poseA);
    //XInput.setButton(BUTTON_X, val2);
  #endif

 
 #ifdef SERIAL
   for (uint8_t i=0; i < 16; i++) {
      if (readConsole(i)) 
      {
        Serial.print("Button on GPIO #"); 
        if (i<12)
        {
          Serial.print(((char)(i+65)));
        }
        else
        {
          Serial.print("L");
          Serial.print(i-11);
        }
        Serial.println(" pressed!");
      }
    }
 #endif
 
  delay(10); // a short debounce delay
}


bool readConsole(int button)
{
  int module = (int)(((float)button) / 8);
  int pin    = button % 8;

  bool rs = readModule(module, pin);
  
//  #ifdef SERIAL
//    Serial.print("Module: ");
//    Serial.print(module);
//    Serial.print(" Pin: ");
//    Serial.print(pin);
//    Serial.print(" Value: ");
//    Serial.println(rs);
//    delay(1000);
//  #endif

  return rs;
}


bool readModule(int module, int pin)
{
  return !pcf[module].digitalRead(pin);
}
