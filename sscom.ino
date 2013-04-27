/* Released under GPL. As is without warranty. Work in progress with much left to do.
/* Currently only tested for mega2560. Also only supports Arduino IDE's Serial Monitor, or other monitors that allow
/* sending of more than one byte at a time.
/* Original sketch by dave@xtechgeek.com 4/2013
/*
/* version 0.02 */


String cwrd = "";
char cchar;
int menu_level=0;

void setup() {
  Serial.begin(9600);
  Serial.println("SSCOM Ready: type \"help\" or a command.");
}

void loop() {
  while (Serial.available()) {
    cchar = Serial.read();
    cwrd.concat(cchar); delay (10);
  }
  if (menu_level==0) { //Test for menu level
    //Main menu section "0"
    if (cwrd=="test") {
      Serial.println("\"test\" successul, try \"another command\".");
      cwrd = "";
    }
    if (cwrd=="another command") {
      Serial.println("it works!");
      cwrd = "";
    }
    if (cwrd=="commands") {
      Serial.println("available commands are: \"exit\", \"commands\", \"help\", \"main menu\", \"menu1\", \"menu2\", \"test\", \"pmt\", and \"another command\".");
      cwrd = "";
    }
    if (cwrd=="main menu") {
      Serial.println("You are already at the main menu, try \"menu1\" or \"menu2\".");
      cwrd = "";
    }
    if (cwrd=="help") {
      Serial.println("\"commands\"- to list commands. \"pmt\"- to list current menu tree. \"main menu\", \"menuN\" where N is menu number- to change menu levels.");
      cwrd = "";
    }
    if (cwrd=="menu1") {
      Serial.println("Now in menu1 (submenu number 1).");
      menu_level=1;
      cwrd = "";
    }
    if (cwrd=="menu2") {
      Serial.println("Now in menu2 (submenu number 2).");
      menu_level=2;
      cwrd = "";
    }
    if (cwrd=="pmt") {
      Serial.println("main menu.");
      cwrd = "";
    }
    if (cwrd=="exit") {
      Serial.println("Cannot exit, you are in main menu.");
      cwrd = "";
    }
    else if (cwrd != "") {
      Serial.print("unknown command: \"");Serial.print(cwrd);Serial.println("\"");
      cwrd = "";
    }
  }
  if (menu_level==1) {
    if (cwrd=="help") {
      Serial.println("\"commands\"- to list commands. \"pmt\"- to list current menu tree. \"main menu\", \"menuN\" where N is menu number- to change menu levels.");
      cwrd = "";
    }
    if (cwrd=="commands") {
      Serial.println("available commands are: \"pmt\", \"test2\", \"exit\", \"commands\", \"help\", \"main menu\", and \"menu2\".");
      cwrd = "";
    }
    if (cwrd=="pmt") {
      Serial.println("menu1");
      cwrd = "";
    }
    if (cwrd=="test2") {
      Serial.println("test2, for submenu1 works!");
      cwrd = "";
    }
    if (cwrd=="menu1") {
      Serial.println("You are already in menu1 (submenu1)");
      cwrd = "";
    }
    if (cwrd=="menu2") {
      Serial.println("You are now in menu2 (submenu2)");
      menu_level=2;
      cwrd = "";
    }
    if (cwrd=="exit") {
      Serial.println("Exiting menu1 (submenu1), now at main menu.");
      menu_level=0;
      cwrd = "";
    }
    if (cwrd=="main menu") {
      Serial.println("Now at main menu.");
      menu_level=0;
      cwrd = "";
    }
    else if (cwrd != "") {
      Serial.print("unknown command: \"");Serial.print(cwrd);Serial.println("\"");
      cwrd = "";
    }
  }
  else if (menu_level==2) {
    if (cwrd=="help") {
      Serial.println("\"commands\"- to list commands. \"pmt\"- to list current menu tree. \"main menu\", \"menuN\" where N is menu number- to change menu levels.");
      cwrd = "";
    }
    if (cwrd=="commands") {
      Serial.println("available commands are: \"pmt\", \"test3\", \"exit\", \"commands\", \"help\", \"main menu\", and \"menu1\".");
      cwrd = "";
    }
    if (cwrd=="pmt") {
      Serial.println("menu2");
      cwrd = "";
    }
    if (cwrd=="test3") {
      Serial.println("test3, for submenu2 works!");
      cwrd = "";
    }
    if (cwrd=="menu2") {
      Serial.println("You are already in menu2 (submenu2)");
      cwrd = "";
    }
    if (cwrd=="menu1") {
      Serial.println("You are now in menu1 (submenu1)");
      menu_level=1;
      cwrd = "";
    }
    if (cwrd=="exit") {
      Serial.println("Exiting menu2 (submenu2), now at main menu.");
      menu_level=0;
      cwrd = "";
    }
    if (cwrd=="main menu") {
      Serial.println("Now at main menu.");
      menu_level=0;
      cwrd = "";
    }
    else if (cwrd != "") {
      Serial.print("unknown command: \"");Serial.print(cwrd);Serial.println("\"");
      cwrd = "";
    }
  }
}
