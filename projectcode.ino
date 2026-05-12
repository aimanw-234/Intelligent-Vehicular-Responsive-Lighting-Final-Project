// Pin Definitions for IR Sensors (Inputs)
const int IR1 = 2;
const int IR2 = 3;
const int IR3 = 4;
const int IR4 = 5;

// Pin Definition for LDR Sensor (Input)
const int LDR_PIN = 7;

// Pin Definitions for LEDs (PWM Outputs)
const int LED1 = 6;
const int LED2 = 9;
const int LED3 = 10;
const int LED4 = 11;

// Brightness Levels (Range: 0 to 255)
int dimBrightness = 40;   // Low glow for night standby
int fullBrightness = 255; // Full brightness when motion is detected
int offBrightness = 0;    // Completely off during the day

void setup() {
  // Initialize Sensor Pins
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(LDR_PIN, INPUT);

  // Initialize LED Pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  // Read the LDR sensor (Low usually means dark, depending on the module)
  // If LDR output is HIGH, it's Night/Dark
  if (digitalRead(LDR_PIN) == HIGH) {
    
    // Check IR Sensor 1
    if (digitalRead(IR1) == LOW) { // LOW means object detected
      analogWrite(LED1, fullBrightness);
    } else {
      analogWrite(LED1, dimBrightness);
    }

    // Check IR Sensor 2
    if (digitalRead(IR2) == LOW) {
      analogWrite(LED2, fullBrightness);
    } else {
      analogWrite(LED2, dimBrightness);
    }

    // Check IR Sensor 3
    if (digitalRead(IR3) == LOW) {
      analogWrite(LED3, fullBrightness);
    } else {
      analogWrite(LED3, dimBrightness);
    }

    // Check IR Sensor 4
    if (digitalRead(IR4) == LOW) {
      analogWrite(LED4, fullBrightness);
    } else {
      analogWrite(LED4, dimBrightness);
    }

  } else {
    // It is Day Time - Turn all lights OFF
    analogWrite(LED1, offBrightness);
    analogWrite(LED2, offBrightness);
    analogWrite(LED3, offBrightness);
    analogWrite(LED4, offBrightness);
  }
}