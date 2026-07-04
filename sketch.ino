//BLYNK data
#define BLYNK_TEMPLATE_ID "TMPL6I1ExD03B"
#define BLYNK_TEMPLATE_NAME "MANUAL MODE"
#define BLYNK_AUTH_TOKEN "lsBtGtIfmq6kBtymsNwon3uTyLx4CREY"

#include <BlynkSimpleEsp32.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <ESP32Servo.h>

//ESP32 Pins
#define DHTPIN  4
#define DHTTYPE  DHT22
#define PIR_PIN  14
#define ECHO_PIN  26
#define TRIG_PIN  27
#define GAS_PIN  34
#define LDR_PIN  35
#define BUZZER_PIN  2
#define ALARM_LED  15
#define WATER_RELAY_PIN  23
#define FAN_RELAY_PIN  22
#define SERVO_PIN  17
#define Light_PIN  21

//connect Data
char ssid[] = "Wokwi-GUEST";
char pass[] = "";
const char* mqtt_server = "broker.hivemq.com";
String thingSpeakAPI = "O8BE0AYMC2O3FU29";


DHT dht(DHTPIN, DHTTYPE);
Servo servo;
WiFiClient espClient;
PubSubClient client(espClient);
BlynkTimer timer;

const int GAS_LIMIT = 1000;
const int TEMP_HOT = 45;
const int TEMP_FIRE = 60;
const int WATER_LOW = 20;
const int WATER_FULL = 8;

float temp = 0, hum = 0, distance = 0;
int gasValue = 0, motion = 0, lightValue = 0;
static unsigned long lastServerSend = 0;
String save_state="", motion_detected="";
bool gasDanger = false;
bool heatDanger = false;
bool fireDanger = false;
bool motionDetected = false;
bool danger = false;
bool autoMode = false;

float Ultrasonic_Distance();
String getLightLevel();
void reconnect();
void NewValues();
void WINDOW_ON();
void WINDOW_HALF();
void WINDOW_OFF();
void FAN_ON();
void FAN_OFF();
void WATER_ON();
void WATER_OFF();
void Light_ON();
void Light_OFF();
void alarmSystem();
void RestAlarm();
void autoControl();
void waterControl();
void lightingControl();
void Full_AUTO_Mode();
BLYNK_WRITE(V0);
BLYNK_WRITE(V1);
BLYNK_WRITE(V2);
BLYNK_WRITE(V3);
BLYNK_WRITE(V4);
BLYNK_WRITE(V5);
BLYNK_WRITE(V6);
BLYNK_WRITE(V7);


void setup() {
  Serial.begin(115200);
  Serial.println("System Started");

  pinMode(PIR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(WATER_RELAY_PIN, OUTPUT);
  pinMode(FAN_RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(ALARM_LED, OUTPUT);
  pinMode(Light_PIN, OUTPUT);

  servo.attach(SERVO_PIN);

  Serial.println("Connecting WiFi");

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n WiFi Connected");

  client.setServer(mqtt_server, 1883);

  timer.setInterval(2000L, [](){
  if (!Blynk.connected()) {
    Blynk.connect();
  }});

  Blynk.config(BLYNK_AUTH_TOKEN);
  Blynk.connect(10000);

  dht.begin();
}

void loop() {
  Blynk.run();
  timer.run();

  if (!client.connected()) {reconnect();}

  client.loop();

  NewValues();

  alarmSystem();

  if(autoMode){Full_AUTO_Mode();}

  String data =String(temp) + "," +String(hum) + "," +
  String(gasValue) + "," +String(motion) + "," +
  String(lightValue) + "," +String(distance);

  if (millis() - lastServerSend >= 3000) {
    if(client.publish("Registernumber", data.c_str())){
    Serial.println("Published");
    Serial.print("MQTT Data: ");
    Serial.println(data);

    HTTPClient http;

    String url =
    "https://api.thingspeak.com/update?api_key=" + thingSpeakAPI +
    "&field1=" + String(temp) +
    "&field2=" + String(hum) +
    "&field3=" + String(gasValue) +
    "&field4=" + String(motion) +
    "&field5=" + String(lightValue) +
    "&field6=" + String(distance);

    http.begin(url);

    int code = http.GET();

    Serial.print("ThingSpeak: ");
    Serial.println(code);

    http.end();
  }
  else{Serial.println("Publish Failed");}
  }
}

float readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  return pulseIn(ECHO_PIN, HIGH) * 0.034 / 2;
}

String getLightLevel() {
  if (lightValue< 1000) {
    return "VERY BRIGHT";
  }
  else if (lightValue< 2000) {
    return "BRIGHT";
  }
  else if (lightValue < 3000) {
    return "MEDIUM";
  }
  else if (lightValue < 3800) {
    return "DARK";
  }
  else {
    return "VERY DARK";
  }
}

void reconnect()
{
  while (!client.connected())
  {
    Serial.println("Connecting MQTT...");

    String clientId =
      "ESP32Client-" +
      String(random(1000));

    if (client.connect(clientId.c_str()))
    {
      Serial.println("✅ MQTT Connected");
    }

    else
    {
      Serial.print("❌ MQTT Failed : ");

      Serial.println(client.state());

      delay(2000);
    }
  }
}

void NewValues(){
  temp = dht.readTemperature();
  hum  = dht.readHumidity();
  if (isnan(temp) || isnan(hum))
    return;

  gasValue = analogRead(GAS_PIN);
  motion = digitalRead(PIR_PIN);
  lightValue = analogRead(LDR_PIN);
  distance = readDistance();

  gasDanger  = (gasValue > GAS_LIMIT);
  heatDanger = (temp > TEMP_HOT && temp <= TEMP_FIRE);
  fireDanger = (temp > TEMP_FIRE);
  motionDetected = (motion == HIGH);
  danger = (gasDanger || fireDanger);

  save_state=(danger)? "Dangurs!!" : "Save";
  motion_detected=(motionDetected)? "Ther is someone" : "No motioun Detected";
  
}

void WINDOW_ON()   { servo.write(180); }
void WINDOW_HALF() { servo.write(90); }
void WINDOW_OFF()  { servo.write(0); }

void FAN_ON()  { digitalWrite(FAN_RELAY_PIN, HIGH); }
void FAN_OFF() { digitalWrite(FAN_RELAY_PIN, LOW); }

void WATER_ON()  { digitalWrite(WATER_RELAY_PIN, HIGH); }
void WATER_OFF() { digitalWrite(WATER_RELAY_PIN, LOW); }

void Light_ON() {digitalWrite(Light_PIN, HIGH);}
void Light_OFF() {digitalWrite(Light_PIN, LOW);}

void alarmSystem() {

  static bool lastDanger = false;

  if (danger && !lastDanger) {
    tone(BUZZER_PIN, 1000);
    digitalWrite(ALARM_LED, HIGH);
    delay(20);
    digitalWrite(ALARM_LED, LOW);
    WINDOW_ON();
    FAN_ON();
  }

  if (!danger && lastDanger) {
    noTone(BUZZER_PIN);
    digitalWrite(ALARM_LED, LOW);
    WINDOW_OFF();
    FAN_OFF();
  }

  lastDanger = danger;

}

void RestAlarm(){
  noTone(BUZZER_PIN);
  digitalWrite(ALARM_LED, LOW);
}

void autoControl() {

  if (danger) return; 

  if (heatDanger) {
    WINDOW_ON();
    FAN_ON();
  }
  else if (temp > 25 && temp <= 45) {
    if (motionDetected) {
      WINDOW_HALF();
      FAN_ON();
    } 
    else {
      WINDOW_OFF();
      FAN_OFF();
    }
  }
  else if (temp <= 25) {
    WINDOW_OFF();
    FAN_OFF();
  }
}

void waterControl() {
  if (distance > WATER_LOW) {
    WATER_ON();
  }
  else if (distance < WATER_FULL) {
    WATER_OFF();
  }
}

void lightingControl(){

  if (lightValue < 2000) {
    Light_OFF();
  }

  else {
    if (motionDetected) {
      Light_ON();
    }
    else {
      Light_OFF();
    }
  }
}

void Full_AUTO_Mode(){
  autoControl();
  waterControl();
  lightingControl();
}

BLYNK_WRITE(V0)
{
  int state = param.asInt();
  if(state){WINDOW_ON();}
}

BLYNK_WRITE(V1)
{
  int state = param.asInt();
  if(state){WINDOW_HALF();}
}

BLYNK_WRITE(V2)
{
  int state = param.asInt();
  if(state){WINDOW_OFF();}
}

BLYNK_WRITE(V3)
{
  int state = param.asInt();
  if(state){FAN_ON();}
  else{FAN_OFF();}
}

BLYNK_WRITE(V4)
{
  int state = param.asInt();
  if(state){Light_ON();}
  else{Light_OFF();}
}

BLYNK_WRITE(V5)
{
  int state = param.asInt();
  if(state){WATER_ON();}
  else{WATER_OFF();}
}

BLYNK_WRITE(V6)
{
  int state = param.asInt();
  if(state){RestAlarm();}
}

BLYNK_WRITE(V7)
{
  autoMode = param.asInt();
}

