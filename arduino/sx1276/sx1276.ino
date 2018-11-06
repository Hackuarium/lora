#define M0 A0
#define M1 A1

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(M0, OUTPUT);
  pinMode(M1, OUTPUT);

}

void loop() {
  getParameters();
  delay(500);
  getVersion();
  delay(500);
  test();
  delay(500);
}

void test() {
  setNormalMode();
  Serial.println("Test");
  Serial1.print(0x20);
  Serial1.print(0x21);
  Serial1.print(0x22);
  showResponse();
  setNormalMode();
}

void getParameters() {
  setPowerSaving();
  Serial.println("Send");
  Serial1.print(0xC1);
  Serial1.print(0xC1);
  Serial1.print(0xC1);
  showResponse();
  setNormalMode();
}

void showResponse() {
  delay(100);
  while (Serial1.available()) {
    Serial.println("yes");
    Serial.print(Serial1.read(), "HEX");
  }
  Serial.println();
}

char version[] = {0xC3, 0xC3, 0xC3};

void getVersion() {
  setPowerSaving();
  Serial1.print(version);
  showResponse();
  setNormalMode();
}

void reset() {
  setPowerSaving();
  Serial1.print("C4C4C4");
  setNormalMode();
}



void setNormalMode() {
  Serial.println("WakeUp mode");
  digitalWrite(M0, 0);
  digitalWrite(M1, 0);
  //delay(5);
}

void setWakeUpMode() {
  Serial.println("Wake up mode");
  digitalWrite(M0, 0);
  digitalWrite(M1, 1);
  // delay(5);
}

void setPowerSaving() {
  Serial.println("Power saving mode");
  digitalWrite(M0, 1);
  digitalWrite(M1, 0);
  delay(5);
}

void setSleepMode() {
  Serial.println("Sleep mode");
  digitalWrite(M0, 1);
  digitalWrite(M1, 1);
  delay(5);
}
