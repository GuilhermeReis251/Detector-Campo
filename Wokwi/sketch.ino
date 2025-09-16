#include <WiFi.h>
#include <PubSubClient.h>

// Configuração de rede para o Wokwi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Configuração do broker MQTT
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

// Pinos dos botões
#define BTN_LATERAL    13
#define BTN_ESCANTEIO  12
#define BTN_GOL        14

void setup_wifi() {
  Serial.print("Conectando ao WiFi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conectar ao MQTT...");
    if (client.connect("ESP32Campo")) {
      Serial.println("Conectado ao broker!");
    } else {
      Serial.print("Falhou, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5s");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  // Configura botões com pull-up interno
  pinMode(BTN_LATERAL, INPUT_PULLUP);
  pinMode(BTN_ESCANTEIO, INPUT_PULLUP);
  pinMode(BTN_GOL, INPUT_PULLUP);

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Botão Lateral
  if (digitalRead(BTN_LATERAL) == LOW) { // LOW = pressionado
    client.publish("campo/lateral", "Lateral detectada");
    Serial.println("Lateral detectada");
    delay(300);
  }

  // Botão Escanteio
  if (digitalRead(BTN_ESCANTEIO) == LOW) {
    client.publish("campo/escanteio", "Escanteio detectado");
    Serial.println("Escanteio detectado");
    delay(300);
  }

  // Botão Gol
  if (digitalRead(BTN_GOL) == LOW) {
    client.publish("campo/gol", "Gol detectado");
    Serial.println("Gol detectado");
    delay(300);
  }
}
