// Bluetooth Controlled Car using Arduino + HC-05 + L298N (NO ENABLE PINS)

// Motor Driver Connections
#define IN1 6   // Left motor forward
#define IN2 7   // Left motor backward
#define IN3 10  // Right motor forward
#define IN4 11  // Right motor backward

// Bluetooth RX/TX
#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); // RX | TX  (HC-05 TX -> pin 2, HC-05 RX -> pin 3)

char command;  // Store received Bluetooth command

void setup() {
  // Motor pins setup
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Communication setup
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("Bluetooth Car Ready (No Enable Pins)");
}

void loop() {
  if (BT.available()) {
    command = BT.read();
    Serial.println(command);
    moveCar(command);
  }
}

void moveCar(char cmd) {
  switch (cmd) {
    case 'F': forward(); break;
    case 'B': backward(); break;
    case 'L': left(); break;
    case 'R': right(); break;
    case 'S': stopCar(); break;
    default: stopCar(); break;
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
