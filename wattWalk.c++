#include "HX711.h"
#include <IRremote.h>

// Pin definitions
const int irReceiverPin = 6;    // Pin for IR Receiver
const int rotaryDT = 2;         // Rotary Encoder DT pin
const int rotaryCLK = 3;        // Rotary Encoder CLK pin
const int ledPin = 13;          // LED for energy indicator
const int analogPin = A0;       // Simulate voltage via potentiometer

// HX711 Load Cell Pins
#define LOADCELL_DOUT_PIN 4
#define LOADCELL_SCK_PIN 5
HX711 scale;

// Global variables
float voltage = 0.0;
float current = 0.0;
float power = 0.0;
float resistance = 10.0;  // Default resistance in ohms
bool irToggle = false;

// IR Receiver object
IRrecv irrecv(irReceiverPin);
decode_results results;

// Rotary Encoder state
int lastRotaryState = LOW;

void setup() {
  // Setup pins
  pinMode(rotaryDT, INPUT_PULLUP);
  pinMode(rotaryCLK, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  // Initialize IR Receiver
  irrecv.enableIRIn();

  // Initialize Load Cell
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale();       // Adjust as needed
  scale.tare();            // Calibrate

  Serial.println("Setup Completo!");
}

void loop() {
  // 1. Check IR Remote
  if (irrecv.decode(&results)) {
    handleIRInput(results.value);
    irrecv.resume();
  }

  // 2. Read Rotary Encoder to adjust resistance
  int rotaryState = digitalRead(rotaryDT);
  if (rotaryState != lastRotaryState) {
    if (digitalRead(rotaryCLK) != rotaryState) {
      resistance += 1;  // Increment resistance
    } else {
      resistance -= 1;  // Decrement resistance
    }
    Serial.print("Resistencia ajustada para: ");
    Serial.print(resistance);
    Serial.println(" ohms");
    lastRotaryState = rotaryState;
  }

  // 3. Read HX711 Load Cell for pressure
  float load = scale.get_units();
  if (load < 0) load = 0; // Ensure no negative values

  // 4. Simulate voltage based on analog input
  voltage = analogRead(analogPin) * (5.0 / 1023.0);
  current = voltage / resistance;  // Ohm's Law
  power = voltage * current;

  // 5. Display energy output
  if (load > 5.0) {  // If load exceeds a threshold, simulate energy generation
    digitalWrite(ledPin, HIGH);
    Serial.print("Peso: ");
    Serial.print(load, 2);
    Serial.print(" kg, Voltagem: ");
    Serial.print(voltage, 2);
    Serial.print(" V, Corrente: ");
    Serial.print(current, 2);
    Serial.print(" A, Potência: ");
    Serial.print(power, 2);
    Serial.println(" W");
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(100);
}

void handleIRInput(unsigned long value) {
  switch (value) {
    case 0xFF629D:  // Example: Button 1
      irToggle = !irToggle;
      Serial.println(irToggle ? "IR Mode ON" : "IR Mode OFF");
      break;
    case 0xFF22DD:  // Example: Button 2
      Serial.println("Displaying Threshold Data:");
      Serial.print("Resistencia: ");
      Serial.print(resistance);
      Serial.println(" ohms");
      break;
    default:
      Serial.println("Unknown IR Command");
      break;
  }
}
