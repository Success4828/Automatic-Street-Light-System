// Project: Automatic Street Light System
// Course: ICT 215
// Group: 8 (Bells University of Technology)

// Pin Configuration
int ldrPin = A0;      // LDR connected to Analog Pin 0
int ledPin1 = 13;     // Street Light 1 (LED)
int ledPin2 = 12;     // Street Light 2 (LED)

// Sensitivity Setting
// Increase this number if the lights won't turn on in a dim room.
// Decrease this number if the lights won't turn off in a bright room.
int threshold = 500;  

void setup() {
  // Initialize LED pins as outputs
  pinMode(ledPin1, OUTPUT); 
  pinMode(ledPin2, OUTPUT); 
  
  // Start Serial Monitor for debugging
  Serial.begin(9600);       
  Serial.println("Group 8 System Initializing...");
}

void loop() {
  // Read the light level from the LDR
  int ldrStatus = analogRead(ldrPin); 
  
  // Display the light level on your laptop screen
  Serial.print("Current Light Level: ");
  Serial.println(ldrStatus);

  // Logic: If it gets dark (reading falls below threshold), turn lights ON
  if (ldrStatus <= threshold) {
    digitalWrite(ledPin1, HIGH); 
    digitalWrite(ledPin2, HIGH); 
    Serial.println("STATUS: NIGHT - Lights ON");
  } 
  // Otherwise, it is bright enough, turn lights OFF
  else {
    digitalWrite(ledPin1, LOW);  
    digitalWrite(ledPin2, LOW);  
    Serial.println("STATUS: DAY - Lights OFF");
  }
  
  delay(200); // Small delay for stability
}