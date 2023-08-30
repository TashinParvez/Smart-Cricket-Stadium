int ldrPin = A3; // Analog pin for LDR
int ledPin = 9;  // Digital pin for LED

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Initially turn off LED
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin); // Read LDR value
  int brightness = map(ldrValue, 0, 1023, 0, 255); // Map LDR value to LED brightness range (0-255)

  analogWrite(ledPin, brightness); // Set LED brightness
  
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" | Brightness: ");
  Serial.println(brightness);

  delay(100); // Add a small delay to prevent rapid changes
}
