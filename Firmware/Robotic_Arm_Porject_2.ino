#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 100
#define SERVOMAX 650

// PCA9685 Channels
int shoulderCh = 0;   // 180 degree servo
int baseCh = 1;       // 270 degree servo
int elbowCh = 2;      // 180 degree servo
int gripperCh = 3;    // small 180 degree servo

// Joystick pins
int joy1X = A0;   // Base
int joy1Y = A1;   // Shoulder
int joy2X = A2;   // Elbow
int joy2Y = A3;   // Gripper

// Servo starting angles
int baseAngle = 135;
int shoulderAngle = 90;
int elbowAngle = 90;
int gripperAngle = 90;

// Joystick settings
int joystickCenter = 512;

// Her servo için ayrı deadzone
int baseDeadZone = 70;
int shoulderDeadZone = 70;
int elbowDeadZone = 70;
int gripperDeadZone = 50;   // küçük servo daha hassas tepki versin

// Her servo için ayrı maksimum hız
int baseMaxSpeed = 3;
int shoulderMaxSpeed = 2;
int elbowMaxSpeed = 3;
int gripperMaxSpeed = 5;    // küçük servo: küçük adım, daha smooth

void setup() {
  Serial.begin(9600);

  pwm.begin();
  pwm.setPWMFreq(50);
  delay(500);

  // Elektrik geldikten sonra biraz bekle
  delay(2000);

  // Servoları yavaş yavaş başlangıç pozisyonuna götür
  slowMove270(baseCh, 135, baseAngle, 20);
  slowMove180(shoulderCh, 90, shoulderAngle, 25);
  slowMove180(elbowCh, 90, elbowAngle, 25);
  slowMove180(gripperCh, 90, gripperAngle, 20);

  

  Serial.println("Robotic arm ready.");
}

void slowMove180(int channel, int startAngle, int endAngle, int stepDelay) {
  if (startAngle < endAngle) {
    for (int angle = startAngle; angle <= endAngle; angle++) {
      moveServo180(channel, angle);
      delay(stepDelay);
    }
  } else {
    for (int angle = startAngle; angle >= endAngle; angle--) {
      moveServo180(channel, angle);
      delay(stepDelay);
    }
  }
}

void slowMove270(int channel, int startAngle, int endAngle, int stepDelay) {
  if (startAngle < endAngle) {
    for (int angle = startAngle; angle <= endAngle; angle++) {
      moveServo270(channel, angle);
      delay(stepDelay);
    }
  } else {
    for (int angle = startAngle; angle >= endAngle; angle--) {
      moveServo270(channel, angle);
      delay(stepDelay);
    }
  }
}
void loop() {
  int j1x = analogRead(joy1X);
  int j1y = analogRead(joy1Y);
  int j2x = analogRead(joy2X);
  int j2y = analogRead(joy2Y);

  // Her servo kendi hız/deadzone ayarıyla kontrol ediliyor
  // Left joystick
elbowAngle -= joystickToSpeed(j2y, elbowDeadZone, elbowMaxSpeed);   // up/down = arm lift
gripperAngle  += joystickToSpeed(j2x, gripperDeadZone, gripperMaxSpeed);

// Right joystick
baseAngle  += joystickToSpeed(j1y, baseDeadZone, baseMaxSpeed);     // right/left = base rotation
shoulderAngle += joystickToSpeed(j1x, shoulderDeadZone, shoulderMaxSpeed);

  // Her servo için ayrı güvenli açı limitleri
  baseAngle = constrain(baseAngle, 10, 260);
  shoulderAngle = constrain(shoulderAngle, 20, 160);
  elbowAngle = constrain(elbowAngle, 20, 160);
  gripperAngle = constrain(gripperAngle, 30, 120);

  // Servo komutları
  moveServo270(baseCh, baseAngle);
  moveServo180(shoulderCh, shoulderAngle);
  moveServo180(elbowCh, elbowAngle);
  moveServo180(gripperCh, gripperAngle);

  Serial.print("Base: ");
  Serial.print(baseAngle);
  Serial.print(" | Shoulder: ");
  Serial.print(shoulderAngle);
  Serial.print(" | Elbow: ");
  Serial.print(elbowAngle);
  Serial.print(" | Gripper: ");
  Serial.println(gripperAngle);

  // Daha sık update için düşük delay
  delay(10);
}

int joystickToSpeed(int value, int deadZone, int maxSpeed) {
  int difference = value - joystickCenter;

  if (abs(difference) < deadZone) {
    return 0;
  }

  int speedAmount;

  if (difference > 0) {
    speedAmount = map(difference, deadZone, 511, 1, maxSpeed);
  } else {
    speedAmount = map(difference, -deadZone, -512, -1, -maxSpeed);
  }

  return speedAmount;
}

void moveServo180(int channel, int angle) {
  angle = constrain(angle, 0, 180);
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(channel, 0, pulse);
}

void moveServo270(int channel, int angle) {
  angle = constrain(angle, 0, 270);
  int pulse = map(angle, 0, 270, SERVOMIN, SERVOMAX);
  pwm.setPWM(channel, 0, pulse);
}