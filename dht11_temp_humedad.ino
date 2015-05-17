// Libreria para Sensores DHT
#include "DHT.h"

#define DHT1PIN 2     // Pin del Arduino al cual esta conectado el pin 2 del sensor
#define DHT2PIN 3


#define DHTTYPE DHT11   // DHT 11 


// Inicializa el sensor
DHT dht1(DHT1PIN, DHTTYPE);
DHT dht2(DHT2PIN, DHTTYPE);

// Configura Arduino 
void setup() {
  Serial.begin(9600); 
  Serial.println("Prueba de sensor DHT11!\n\n");
 
  dht1.begin();
  dht2.begin();
}

void loop() {
  // Espera dos segundos para realizar la primera medición.
  delay(2000);

  // Lee los datos entregados por el sensor, cada lectura tarda 250 milisegundos
  // El sensor lee la temperatura cada 2 segundos}
  
  // Obtiene la Humedad
  float h1 = dht1.readHumidity();
  // Obtiene la Temperatura en Celsius
  float t1 = dht1.readTemperature();
  
  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
  
  // Control de errores, valida que se obtuvieron valores para los datos medidos
  if (isnan(h1) || isnan(t1)) {
    Serial.println("Fallo al leer el sensor DHT1!");
    return;
  }
  //Lo imprimimos por pantalla
  Serial.println("Sensor 1:");
  Serial.print("Humedad : "); 
  Serial.print(h1);
  Serial.print(" %\t");
  Serial.print("Temperatura: "); 
  Serial.print(t1);
  Serial.println(" *C ");
//Validacion de errores segundo sensor
  if (isnan(h2) || isnan(t2)){
    Serial.println("Falla al leer el sensor DHT2!");
    return;
  }
  Serial.println("Sensor 2:");
  Serial.print("Humedad: "); 
  Serial.print(h2);
  Serial.print(" %\t");
  Serial.print("Temperatura: "); 
  Serial.print(t2);
  Serial.println(" *C ");
}

