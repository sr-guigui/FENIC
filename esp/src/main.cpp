#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "esp";
const char* password = "12345678";
WebServer server(80);

const int pinS0 = 33;
const int pinS1 = 25;
const int pinS2 = 16; // RX2
const int pinS3 = 17; // TX2
const int pinOut = 5;

const char* htmlPagina = R"rawliteral(
<!DOCTYPE html>
<html lang="pt-BR">
<head>
  <meta charset="UTF-8">
  <title>Sensor de Cor</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial; text-align: center; background: #f0f2f5; padding: 20px; }
    .val { font-size: 20px; font-weight: bold; color: #1a73e8; }
  </style>
  <script>
    setInterval(() => {
      fetch('/cor').then(res => res.json()).then(data => {
        document.getElementById('r').innerText = data.r;
        document.getElementById('g').innerText = data.g;
        document.getElementById('b').innerText = data.b;
        document.getElementById('detectada').innerText = data.nome;
      });
    }, 800);
  </script>
</head>
<body>
  <h1>Sensor de Cor TCS3200</h1>
  <p>Vermelho (R): <span id="r" class="val">0</span></p>
  <p>Verde (G): <span id="g" class="val">0</span></p>
  <p>Azul (B): <span id="b" class="val">0</span></p>
  <h2>Cor Detectada: <span id="detectada" class="val">Analisando...</span></h2>
</body>
</html>
)rawliteral";

int lerFrequencia(int s2State, int s3State) {
  digitalWrite(pinS2, s2State);
  digitalWrite(pinS3, s3State);
  delay(10);
  return pulseIn(pinOut, LOW, 20000);
}

void handleCor() {
  int r = lerFrequencia(LOW, LOW);
  int b = lerFrequencia(LOW, HIGH);
  int g = lerFrequencia(HIGH, HIGH);

  String nomeCor = "Indefinida";
  // Quanto menor o valor da frequência no TCS3200, mais intensa é a cor refletida
  if (r < g && r < b) nomeCor = "Vermelho";
  else if (g < r && g < b) nomeCor = "Verde";
  else if (b < r && b < g) nomeCor = "Azul";

  String json = "{\"r\":" + String(r) + ",\"g\":" + String(g) + ",\"b\":" + String(b) + ",\"nome\":\"" + nomeCor + "\"}";
  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);
  pinMode(pinS0, OUTPUT); pinMode(pinS1, OUTPUT);
  pinMode(pinS2, OUTPUT); pinMode(pinS3, OUTPUT);
  pinMode(pinOut, INPUT);

  digitalWrite(pinS0, HIGH); digitalWrite(pinS1, LOW); // Escala 20%

  WiFi.softAP(ssid, password);
  server.on("/", []() { server.send(200, "text/html", htmlPagina); });
  server.on("/cor", handleCor);
  server.begin();
}

void loop() {
  server.handleClient();
}