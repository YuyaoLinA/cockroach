const uint8_t motor1Pins[4] = {2, 4, 3, 5};
unsigned int forward[4] = {0x03, 0x06, 0x0C, 0x09};
unsigned int reverse[4] = {0x03, 0x09, 0x0C, 0x06};

#define HEART_PIN A0
#define IR1_PIN A1
#define IR2_PIN A2

int bpm = 0;
int signal = 0;
bool pulseDetected = false;
unsigned long lastBeatTime = 0;

int ir1_now, ir2_now;
float diff_now = 0;
float diff_prev = 0;
float roachSpeed = 0;
unsigned long lastSampleTime = 0;
const unsigned long interval = 5000;

float deltaThreshold = 0.1;
int bpmMin = 60, bpmMax = 120;
float roachMaxSpeed = 300.0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(motor1Pins[i], OUTPUT);
    digitalWrite(motor1Pins[i], LOW);
  }
  lastSampleTime = millis();
}

void rotateMotor(bool direction, int steps, int delayTime) {
  for (int i = 0; i < steps; i++) {
    for (int j = 0; j < 4; j++) {
      uint8_t pattern = direction ? forward[j] : reverse[j];
      for (int k = 0; k < 4; k++) {
        digitalWrite(motor1Pins[k], (pattern >> k) & 0x01);
      }
      delay(delayTime);
    }
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(motor1Pins[i], LOW);
  }
}

void loop() {
  signal = analogRead(HEART_PIN);
  if (signal > 550 && !pulseDetected) {
    pulseDetected = true;
    unsigned long now = millis();
    if (now - lastBeatTime > 300) {
      bpm = 60000 / (now - lastBeatTime);
      lastBeatTime = now;
    }
  }
  if (signal < 550) {
    pulseDetected = false;
  }

  unsigned long nowTime = millis();
  if (nowTime - lastSampleTime >= interval) {
    ir1_now = analogRead(IR1_PIN);
    ir2_now = analogRead(IR2_PIN);
    diff_now = abs(ir1_now - ir2_now);

    roachSpeed = abs(diff_now - diff_prev) / 5.0;
    diff_prev = diff_now;
    lastSampleTime = nowTime;

    float humanTension = constrain((float)(bpm - bpmMin) / (bpmMax - bpmMin), 0.0, 1.0);
    float roachTension = constrain(roachSpeed / roachMaxSpeed, 0.0, 1.0);
    float tensionDelta = humanTension - roachTension;

    // Send to Processing
    Serial.print(humanTension, 3);
    Serial.print(",");
    Serial.println(roachTension, 3);

    // Motor control
    if (abs(tensionDelta) < deltaThreshold) {
      // do nothing
    } else if (tensionDelta > 0) {
      rotateMotor(true, 50, 5);
    } else {
      rotateMotor(false, 50, 5);
    }
  }

  delay(10);
}
