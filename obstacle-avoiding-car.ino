// Obstacle Avoiding Car using Arduino + L298N (no enable pins) + HC-SR04

// Motor Driver Pins
#define IN1 6   // Left motor forward
#define IN2 7   // Left motor backward
#define IN3 10  // Right motor forward
#define IN4 11  // Right motor backward

// Ultrasonic Sensor Pins
#define TRIG 8
#define ECHO 9

long duration;
int distance;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
  Serial.println("Obstacle Avoiding Car Ready");
}

void loop() {
  distance = getDistance();

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 20) {
    forward();
  } else {
    stopCar();
    delay(300);
    backward();
    delay(400);

    stopCar();
    delay(300);

    // Random turn
    if (random(2) == 0) {
      left();
    } else {
      right();
    }
    delay(500);
    stopCar();
  }
}

int getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  int dist = duration * 0.034 / 2; // convert to cm
  return dist;
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
