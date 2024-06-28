#include <VirtualWire.h>

int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int data = 11;

void setup() {
  vw_rx_start();
  vw_set_rx_pin(11);
  vw_setup(2000);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(data, INPUT);
  Serial.begin(11520);
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) {
    if (buf[0] == '1') {
      forward();
    } else if (buf[0] == '2') {
      backward();
    } else if (buf[0] == '3') {
      left();
    } else if (buf[0] == '4') {
      right();
    } else {
      stop();
    }
  }
}

  void forward() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("forward");
  }
  void backward() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.println("backward");
  }
  void left() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.println("left");
  }
  void right() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("right");
  }
  void stop() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    Serial.println("stop");
  }
