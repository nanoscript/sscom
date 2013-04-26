/* Released under GPL. Original sketch by xclusive. As is without warranty. Work in progress with much left to do.
/*
/*version 0.01
*/


String cwrd = "";
char cchar;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready: Try \"test\" command.");
}

void loop() {
  while (Serial.available()) {
    cchar = Serial.read();
    cwrd.concat(cchar); delay (10);
  }
  if (cwrd=="test") {
    Serial.println("\"test\" successul, try \"another command\".");
    cwrd = "";
  }
  if (cwrd=="another command") {
    Serial.println("it works!");
    cwrd = "";
  }
  if (cwrd=="help") {
    Serial.println("available commands are: \"help\", \"test\", and \"another command\".");
    cwrd = "";
  }
  else if (cwrd != "") {
    Serial.print("unknown command: \"");Serial.print(cwrd);Serial.println("\"");
    cwrd = "";
  }
}
