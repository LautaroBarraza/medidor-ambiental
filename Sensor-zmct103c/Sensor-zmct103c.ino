const int sensorPin = 14;  // Usamos GPIO34 para la entrada analógica
const float burdenResistor = 200.0;  // Resistencia de carga en ohms
const float turnsRatio = 1000.0;     // Relación de vueltas del transformador
const int numSamples = 500;         // Número de muestras para RMS
const float VREF = 3.3;             // Voltaje de referencia del ESP32
const float ADCResolution = 4095.0; // Resolución ADC del ESP32 (12 bits)

void setup() {
  Serial.begin(115200);  // Monitor serie a velocidad adecuada
  delay(1000);
}

void loop() {
  float sumSquares = 0.0;
  float offset = VREF / 2;  // Centro de la señal (esperado)

  for (int i = 0; i < numSamples; i++) {
    int rawValue = analogRead(sensorPin);  // Leer ADC
    float voltage = rawValue * (VREF / ADCResolution);  // Convertir a voltaje
    float adjustedVoltage = voltage - offset;  // Eliminar el offset (centro)
    sumSquares += adjustedVoltage * adjustedVoltage;  // Cuadrado para RMS
  }

  float rmsVoltage = sqrt(sumSquares / numSamples);  // Voltaje RMS
  float rmsCurrent = (rmsVoltage / burdenResistor) * turnsRatio;  // Corriente RMS

  Serial.print("Corriente RMS: ");
  Serial.print(rmsCurrent, 3);
  Serial.println(" A");

  delay(1000);
}

