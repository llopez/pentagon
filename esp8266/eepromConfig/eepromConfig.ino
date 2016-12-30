#include <EEPROM.h>

int address = 0;
int i;
int t;
String data;
String input;
String ssid;
String pass;
String server;
char buff;

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  EEPROM.begin(512);

  delay(10);

  Serial.println("configure [yes/no]");

  t = 0;
  while(t < 10){
    Serial.print(".");
    if(Serial.available() > 0) {
      input = Serial.readStringUntil('\n');

      if(input == "yes\r") {
        clearEEPROM();
        Serial.println();
        ssid = prompt("SSID");
        pass = prompt("PASS");
        server = prompt("SERVER");
        ssid.trim();
        pass.trim();
        server.trim();
        writeEEPROM(0, ssid);
        writeEEPROM(ssid.length() + 1, pass);
        writeEEPROM(pass.length() + ssid.length() + 2, server);
        
        EEPROM.commit();
        break;
      }
    }
    t += 1;
    delay(1000);
  }

  ssid = readEEPROM(0);
  pass = readEEPROM(ssid.length() + 1);
  server = readEEPROM(pass.length() + ssid.length() + 2);
}

void loop() {

  Serial.println(ssid);
  Serial.println(pass);
  Serial.println(server);

  delay(1000);
}

String readEEPROM(int address) {
  data = "";
  buff = EEPROM.read(address);
  while (buff != 0) {
    data += buff;
    address += 1;
    buff = EEPROM.read(address);
  }
  return data;
}

void writeEEPROM(int address, String value) {
  for(i = 0; i < value.length(); i++) {
    EEPROM.write(i + address, value[i]);
  }
  EEPROM.write(i + address + 1, 0);
}

void clearEEPROM() {
  for(i=0; i<255; i++) {
    EEPROM.write(i, 0);
  }
  EEPROM.commit();
}

String prompt(String valueName) {
  Serial.print("Enter "+ valueName + ": ");
  while(true){
    if(Serial.available() > 0) {
      input = Serial.readStringUntil('\n');
      break;
    }
  delay(10);
  }
  Serial.println(input);
  return input;
}

