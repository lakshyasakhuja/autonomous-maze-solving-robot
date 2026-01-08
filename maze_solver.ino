#include <Servo.h>

Servo servoLeft;
Servo servoRight;
bool Stop = false;
// Pin assignments
const int irLeft = 10;     // Left IR LED emitter
const int irMid = 6;       // Middle IR LED emitter
const int irRight = 2;     // Right IR LED emitter

const int sensorLeft = 11; // Left IR receiver
const int sensorMid = 7;   // Middle IR receiver
const int sensorRight = 3; // Right IR receiver

const int leftLed = A2;    // Left indicator LED
const int midLed = A1;     // Middle indicator LED
const int rightLed = A0;   // Right indicator LED

void setup() {
  servoRight.attach(13);
  servoLeft.attach(12);

  // Set up sensor pins
  pinMode(sensorLeft, INPUT);   // Left receiver pin
  pinMode(sensorMid, INPUT);    // Middle receiver pin
  pinMode(sensorRight, INPUT);  // Right receiver pin

  // Set up IR emitter pins
  pinMode(irLeft, OUTPUT);      // Left IR emitter
  pinMode(irMid, OUTPUT);       // Middle IR emitter
  pinMode(irRight, OUTPUT);     // Right IR emitter

  // Set up indicator LEDs
  pinMode(leftLed, OUTPUT);     // Left indicator LED
  pinMode(midLed, OUTPUT);      // Middle indicator LED
  pinMode(rightLed, OUTPUT);    // Right indicator LED

  Serial.begin(9600);
}

void loop() {
  int leftDetect = LeftDetect(37000);
  int midDetect = MidDetect(39000);
  int rightDetect = RightDetect(38000);

  // Update indicator LEDs
  digitalWrite(leftLed, leftDetect == 0 ? HIGH : LOW);
  digitalWrite(midLed, midDetect == 0 ? HIGH : LOW);
  digitalWrite(rightLed, rightDetect == 0 ? HIGH : LOW);

  // Decision-making logic
  if (midDetect == 0 && leftDetect == 0 && rightDetect == 0) {
    // Walls ahead and on both sides; stop
    stopMoving();
  } else if (midDetect == 0 && rightDetect == 0) {
    // Obstacles on middle and right; turn left (away from obstacles)
    turnRight90();
  } else if (midDetect == 0 && leftDetect == 0) {
    // Obstacles on middle and left; turn right (away from obstacles)
    turnLeft90();
  } else if (midDetect == 0 && leftDetect == 1 && rightDetect == 1) {
    // Only middle sensor detects wall; slow down
    slowDown();
  } else if (leftDetect == 0 && midDetect == 1 && rightDetect == 1) {
    // Only left sensor detects wall; adjust to the right
    adjustRight();
  } else if (rightDetect == 0 && midDetect == 1 && leftDetect == 1) {
    // Only right sensor detects wall; adjust to the left
    adjustLeft();
  } else {
    // No walls detected or walls on both sides; move forward
    moveForward();
  }

  delay(100); // Short delay for loop stability
}

void moveForward() {
  servoRight.writeMicroseconds(1572);
  servoLeft.writeMicroseconds(1414);   
}

void adjustRight() {
  // Adjust to the right by slowing down left motor
  servoRight.writeMicroseconds(1640); // Normal speed
  servoLeft.writeMicroseconds(1415);  // Slightly slower speed to turn right
  delay(10);
}

void adjustLeft() {
  // Adjust to the left by slowing down right motor
  servoRight.writeMicroseconds(1515); // Slightly slower speed to turn left
  servoLeft.writeMicroseconds(1415);  // Normal speed
  delay(10);
}

void slowDown() {
  // Slow down both motors
  servoRight.writeMicroseconds(1450); // Slightly slower speed
  servoLeft.writeMicroseconds(1600);  // Slightly slower speed
}

void stopMoving() {
  servoRight.writeMicroseconds(1490); // Stop right servo
  servoLeft.writeMicroseconds(1490);  // Stop left servo
  if (!Stop) {
    Stop = true;
    servoRight.writeMicroseconds(1414);
    servoLeft.writeMicroseconds(1572);   
    delay(1350);
    Spin720();
    }
  else if (Stop == true) {
    exit(0);
    }
}

void Spin720() {
  servoRight.writeMicroseconds(1560); // Right wheel forward
  servoLeft.writeMicroseconds(1560);
  delay(6000);
}

void turnLeft90() {
  // Turn left by moving right wheel forward and left wheel backward
  servoRight.writeMicroseconds(1560); // Right wheel forward
  servoLeft.writeMicroseconds(1560);  // Left wheel backward
  delay(500); // Adjust this delay based on your servo's speed for 90 degrees
  moveForward(); // Resume moving forward
}

void turnRight90() {
  // Turn right by moving left wheel forward and right wheel backward
  servoRight.writeMicroseconds(1435); // Right wheel backward
  servoLeft.writeMicroseconds(1435);  // Left wheel forward
  delay(500); // Adjust this delay based on your servo's speed for 90 degrees
  moveForward(); // Resume moving forward
}

int LeftDetect(long frequency) {
  tone(irLeft, frequency);            // Turn on the IR LED square wave
  delay(1);                           // Wait 1 ms
  noTone(irLeft);                     // Turn off the IR LED
  int ir = digitalRead(sensorLeft);   // IR receiver -> ir variable
  delay(1);                           // Down time before recheck
  return ir;                          // Return 0 detect, 1 no detect
}

int MidDetect(long frequency) {
  tone(irMid, frequency);             // Turn on the IR LED square wave
  delay(1);                           // Wait 1 ms
  noTone(irMid);                      // Turn off the IR LED
  int ir = digitalRead(sensorMid);    // IR receiver -> ir variable
  delay(1);                           // Down time before recheck
  return ir;                          // Return 0 detect, 1 no detect
}

int RightDetect(long frequency) {
  tone(irRight, frequency);           // Turn on the IR LED square wave
  delay(1);                           // Wait 1 ms
  noTone(irRight);                    // Turn off the IR LED
  int ir = digitalRead(sensorRight);  // IR receiver -> ir variable
  delay(1);                           // Down time before recheck
  return ir;                          // Return 0 detect, 1 no detect
}