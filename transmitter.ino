#include <VirtualWire.h>
String cmd;

char *data;

void setup() {
  Serial.begin(115200);
  Serial.begin(9600);
  vw_set_tx_pin(12);
  vw_setup(2000);
}

void loop() {
  while(Serial.available()==0){

  }
  cmd=Serial.readStringUntil('\r');
  data=cmd;
  vw_send((uint8_t *)data, strlen(data));
  vw_wait_tx();
  delay(10);  
}
