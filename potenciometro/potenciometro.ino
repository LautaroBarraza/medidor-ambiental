#define POT_PIN  // Cambiá por el pin correcto de tu placa

void setup() {
  Serial.begin(115200);  // Iniciar comunicación serial
  delay(1000);           // Esperar un segundo para estabilizar
}

void loop() {
  int valor = analogRead(POT_PIN);  // Leer valor analógico (0-4095 en ESP32, 0-1023 en ESP8266)
  Serial.println(valor);            // Mostrar el valor por el monitor serie
  delay(500);                       // Esperar medio segundo
}