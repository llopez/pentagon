#include <EEPROM.h>

int address = 0;
int i;
int t;
byte value;
String data;
String input;
String ssid;
String pass;
String serverAddress;
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
        
        ssid = prompt("SSID");
        pass = prompt("PASS");
        serverAddress = prompt("SERVER ADDRESS");
        break;
      }
    }
    t += 1;
    delay(1000);
  }

  ssid.trim();
  pass.trim();

  writeEEPROM(0, ssid);
  writeEEPROM(ssid.length(), pass);
  EEPROM.commit();
}

void loop() {
  ssid = readEEPROM(0);
  pass = readEEPROM(ssid.length() + 1);

  Serial.println(ssid);
  Serial.println(pass);

  delay(1000);
}

String readEEPROM(int address) {
  data = "";
  do {
    buff = EEPROM.read(address);
    data += buff;
    address += 1;
    delay(10);
  } while (buff != 0);
  return data;
}

void writeEEPROM(int address, String value) {
  for(i = address; i < value.length(); i++) {
    EEPROM.write(i, value[i]);
  }
  EEPROM.write(i + 1, 0);
}

void clearEEPROM() {
  for(i=0; i<255; i++) {
    EEPROM.write(i, 0);
  }
  EEPROM.commit();
}

void fillEEPROM(int value) {
  for(i=0; i<255; i++) {
    EEPROM.write(i, value);
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

