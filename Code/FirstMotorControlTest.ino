const int EnA = 27;
const int In1 = 26;
const int In2 = 14;
const int EnB = 25;
const int In3 = 32;
const int In4 = 33;

const int PWMFrequecy = 5000;
const int PWMResolution = 8;

void moveForward(int speed){
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  ledcWrite(EnA, speed);
  ledcWrite(EnB, speed);

  Serial.println("Moving Forwards ");
}

void moveBackward(int speed){
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  ledcWrite(EnA, speed);
  ledcWrite(EnB, speed);

  Serial.println("Moving Backwards ");
}

void Stop(){
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  ledcWrite(EnA, 0);
  ledcWrite(EnB, 0);

  Serial.println("Stoped Moving ");
}

void setup() {
  Serial.begin(115200);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);

  ledcAttach(EnA, PWMFrequecy, PWMResolution);
  ledcAttach(EnB, PWMFrequecy, PWMResolution);
}

void loop() {
  moveForward(200);
  delay(2000);

  Stop();
  delay(2000);

  moveBackward(200);
  delay(2000);

  Stop();
  delay(2000);
  }

