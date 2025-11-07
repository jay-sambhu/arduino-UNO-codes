// Blink LED for 5 minutes only, then repeat

const int ledPin = 13;       // Built-in LED pin on most Arduino boards
const unsigned long blinkInterval = 1000;  // 1 second (LED ON/OFF duration)
const unsigned long totalBlinkTime = 300000; // 5 minutes = 300,000 ms

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long startTime = millis();

  // Blink for 5 minutes
  while (millis() - startTime < totalBlinkTime) {
    digitalWrite(ledPin, HIGH);
    delay(blinkInterval / 2); // LED ON for half the interval
    digitalWrite(ledPin, LOW);
    delay(blinkInterval / 2); // LED OFF for half the interval
  }

  // Optional: pause before restarting the 5-minute loop
  delay(1000);
}
