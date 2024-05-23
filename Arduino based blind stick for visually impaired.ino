const int buzzerPin = 8;   // Buzzer connected to digital pin 8
const int triggerPin = 3;  // Ultrasonic sensor trigger pin connected to digital pin 3
const int echoPin = 2;     // Ultrasonic sensor echo pin connected to digital pin 2

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  if (isObjectDetected()) {
    // Trigger the alarm if an object is detected
    activateAlarm();
  } else {
    // Deactivate the alarm
    deactivateAlarm();
  }
}

bool isObjectDetected() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;  // Calculate distance in centimeters

  return (distance < 50);  // Adjust the threshold distance based on your needs
}

void activateAlarm() {
  tone(buzzerPin, 1000);  // Play a 1000Hz tone on the buzzer
  delay(1000);            // Wait for 1 second
  noTone(buzzerPin);      // Turn off the buzzer
}

void deactivateAlarm() {
  noTone(buzzerPin);  // Turn off the buzzer
}
