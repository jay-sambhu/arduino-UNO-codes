#include <Servo.h>

Servo myServo;  // Create a Servo object
const int trigPin = 7;  // TRIG pin of HC-SR04
const int echoPin = 6;  // ECHO pin of HC-SR04
const int servoPin = 11; // PWM pin for Servo

void setup() {
  myServo.attach(servoPin);  // Attach the servo to the PWM pin
  pinMode(trigPin, OUTPUT);   // Set TRIG pin as OUTPUT
  pinMode(echoPin, INPUT);    // Set ECHO pin as INPUT
  myServo.write(0);            // Initialize servo position to closed
}

void loop() {
  long duration, distance;

  // Clear the TRIG pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the TRIG pin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the ECHO pin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distance = (duration * 0.034) / 2; // Distance in cm

  // Check if an object is detected within 10 cm
  if (distance < 10) {
    myServo.write(90);  // Open the dustbin
    delay(1000);        // Wait for 1 second
    myServo.write(0);   // Close the dustbin
    delay(5000);        // Wait for 5 seconds before next detection
  }
}   