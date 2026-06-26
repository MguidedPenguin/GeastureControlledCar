//Driver 1
const int M1_EN = 25; const int M1_IN1 = 27; const int M1_IN2 = 26;
const int M2_EN = 33; const int M2_IN1 = 32; const int M2_IN2 = 14;

//Driver 2
const int M3_EN = 19; const int M3_IN1 = 18; const int M3_IN2 = 5;
const int M4_EN = 17; const int M4_IN1 = 16; const int M4_IN2 = 4;

const int PWMFrequency = 5000;
const int PWMResolution = 8;

void moveForward(int speed){
  digitalWrite(M1_IN1,HIGH); digitalWrite(M1_IN2, LOW);
  digitalWrite(M2_IN1, HIGH); digitalWrite(M2_IN2, LOW);
  digitalWrite(M3_IN1, HIGH); digitalWrite(M3_IN2, LOW);
  digitalWrite(M4_IN1, HIGH); digitalWrite(M4_IN2, LOW);

  ledcWrite(M1_EN, speed);
  ledcWrite(M2_EN, speed);
  ledcWrite(M3_EN, speed);
  ledcWrite(M4_EN, speed);

  Serial.println("Moving Forward");
}

void moveBackward(int speed) {
  digitalWrite(M1_IN1, LOW); digitalWrite(M1_IN2, HIGH);
  digitalWrite(M2_IN1, LOW); digitalWrite(M2_IN2, HIGH);
  digitalWrite(M3_IN1, LOW); digitalWrite(M3_IN2, HIGH);
  digitalWrite(M4_IN1, LOW); digitalWrite(M4_IN2, HIGH);

  ledcWrite(M1_EN, speed);
  ledcWrite(M2_EN, speed);
  ledcWrite(M3_EN, speed);
  ledcWrite(M4_EN, speed);

  Serial.println("Moving Backward");
}

void stopMotors() {
  digitalWrite(M1_IN1, LOW); digitalWrite(M1_IN2, LOW);
  digitalWrite(M2_IN1, LOW); digitalWrite(M2_IN2, LOW);
  digitalWrite(M3_IN1, LOW); digitalWrite(M3_IN2, LOW);
  digitalWrite(M4_IN1, LOW); digitalWrite(M4_IN2, LOW);

  ledcWrite(M1_EN, 0);
  ledcWrite(M2_EN, 0);
  ledcWrite(M3_EN, 0);
  ledcWrite(M4_EN, 0);

  Serial.println("Stopped");
}

void setup(){
  Serial.begin(115200);

  pinMode(M1_IN1, OUTPUT); pinMode(M1_IN2, OUTPUT);
  pinMode(M2_IN1, OUTPUT); pinMode(M2_IN2, OUTPUT);
  pinMode(M3_IN1, OUTPUT); pinMode(M3_IN2, OUTPUT);
  pinMode(M4_IN1, OUTPUT); pinMode(M4_IN2, OUTPUT);

  ledcAttach(M1_EN, PWMFrequency, PWMResolution);
  ledcAttach(M2_EN, PWMFrequency, PWMResolution);
  ledcAttach(M3_EN, PWMFrequency, PWMResolution);
  ledcAttach(M4_EN, PWMFrequency, PWMResolution);
}

void loop() {
  moveForward(200);
  delay(2000);

  stopMotors();
  delay(2000);

  moveBackward(200);
  delay(2000);

  stopMotors();
  delay(2000);
}
