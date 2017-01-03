#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Luigi";
const char* password = "lacasadeluigi2016";
const char* mqtt_server = "192.168.0.40";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup() {
  pinMode(2, OUTPUT);  
  pinMode(0, INPUT);
  
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  
  client.loop();

  handleInput();
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
    digitalWrite(2, LOW);
  } else {
    digitalWrite(2, HIGH);
  }
}

void handleInput() {
  if(digitalRead(0) == LOW){
    if(digitalRead(2) == HIGH){
      client.publish("device/feedback", "1 off");
      log("1", "button: off");
    }else{ 
      client.publish("device/feedback", "1 on");
      log("1", "button: on");
    }
    delay(500);
  }
}

void reconnect() {
  while (!client.connected()) {
    log("1", "Attempting MQTT connection");
    if (client.connect("Device1")) {
      log("1", "Connected to MQTT");
      client.subscribe("device/1");
    } else {
      delay(5000);
    }
  }
}

void log(char* deviceId, char* msg) {
  Serial.println(msg);
  client.publish("device/log", msg);
}
