#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Luigi";
const char* password = "lacasadeluigi2016";
const char* mqtt_server = "192.168.0.40";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  pinMode(2, OUTPUT);  
  pinMode(0, INPUT);
  
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  Serial.println("ready to send signal");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  
  client.loop();
}

void setup_wifi() {

  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  if ((char)payload[0] == '0') {
    Serial.println("turning off");
    turnOff();
  } else {
    Serial.println("turning on");
    turnOn();
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("Device3")) {
      log("3", "Connected");
      client.subscribe("device/3");
    } else {
      delay(5000);
    }
  }
}

void log(char* deviceId, char* msg) {
  client.publish("device/3/log", msg);
}


void pulseIR(long microsecs) {
  cli();
 
  while (microsecs > 0) {
   digitalWrite(2, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(2, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   microsecs -= 26;
  }
 
  sei();
}

void turnOn() {
delayMicroseconds(52928);pulseIR(8600);
delayMicroseconds(4360);pulseIR(540);
delayMicroseconds(1780);pulseIR(540);
delayMicroseconds(600);pulseIR(520);
delayMicroseconds(640);pulseIR(500);
delayMicroseconds(620);pulseIR(540);
delayMicroseconds(1760);pulseIR(520);
delayMicroseconds(620);pulseIR(540);
delayMicroseconds(600);pulseIR(520);
delayMicroseconds(640);pulseIR(500);
delayMicroseconds(620);pulseIR(540);
delayMicroseconds(620);pulseIR(500);
delayMicroseconds(640);pulseIR(520);
delayMicroseconds(600);pulseIR(560);
delayMicroseconds(600);pulseIR(520);
delayMicroseconds(640);pulseIR(500);
delayMicroseconds(620);pulseIR(540);
delayMicroseconds(580);pulseIR(540);
delayMicroseconds(1780);pulseIR(540);
delayMicroseconds(600);pulseIR(520);
delayMicroseconds(640);pulseIR(500);
delayMicroseconds(1740);pulseIR(540);
delayMicroseconds(640);pulseIR(520);
delayMicroseconds(620);pulseIR(540);
delayMicroseconds(600);pulseIR(520);
delayMicroseconds(640);pulseIR(500);
delayMicroseconds(1760);pulseIR(520);
delayMicroseconds(640);pulseIR(520);
delayMicroseconds(620);pulseIR(540);
delayMicroseconds(1760);pulseIR(520);
}

void turnOff() {
delayMicroseconds(976);pulseIR(8600);
delayMicroseconds(4360);pulseIR(540);
delayMicroseconds(1780);pulseIR(540);
delayMicroseconds(600);pulseIR(520);
delayMicroseconds(640);pulseIR(520);
delayMicroseconds(600);pulseIR(540);
delayMicroseconds(1780);pulseIR(500);
delayMicroseconds(620);pulseIR(540);
delayMicroseconds(600);pulseIR(520);
delayMicroseconds(640);pulseIR(500);
delayMicroseconds(1760);pulseIR(520);
delayMicroseconds(1820);pulseIR(500);
delayMicroseconds(600);pulseIR(520);
delayMicroseconds(640);pulseIR(520);
delayMicroseconds(600);pulseIR(540);
delayMicroseconds(620);pulseIR(520);
delayMicroseconds(640);pulseIR(500);
delayMicroseconds(620);pulseIR(540);
delayMicroseconds(620);pulseIR(500);
delayMicroseconds(640);pulseIR(500);
delayMicroseconds(620);pulseIR(540);
delayMicroseconds(620);pulseIR(500);
delayMicroseconds(660);pulseIR(500);
delayMicroseconds(1760);pulseIR(520);
delayMicroseconds(640);pulseIR(520);
delayMicroseconds(1760);pulseIR(520);
delayMicroseconds(640);pulseIR(520);
delayMicroseconds(600);pulseIR(540);
delayMicroseconds(620);pulseIR(500);
delayMicroseconds(1740);pulseIR(560);
}
