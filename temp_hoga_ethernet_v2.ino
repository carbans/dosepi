#include <Ethernet.h>
#include <SPI.h>
#include "DHT.h"

#define DHT1PIN 2 //Definos los pines de los sensores
#define DHT2PIN 3 //El numero que hay detras del DHT es el id del sensor que lo relaciona con la bbdd

#define DHTTYPE DHT11 //Definimos el numero de la serie para que la libreria se inicialice correctamente

DHT dht1(DHT1PIN, DHTTYPE); //Inicializamos los sensores 
DHT dht2(DHT2PIN, DHTTYPE);


// Configuracion del Ethernet Shield
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFF, 0xEE}; // Direccion MAC
byte ip[] = { 192,168,1,100 }; // Direccion IP del Arduino
byte server[] = { 192,168,1,50 }; // Direccion IP del servidor
EthernetClient client; 
 
void setup(void) {
  Serial.begin(9600);
  Ethernet.begin(mac, ip); // Inicializamos el Ethernet Shield
  delay(1000); // Esperamos 1 segundo de cortesia
  Serial.println("Iniciado todos los protocolos!"); 
  
}
 
void loop(void) {
  
  float h1 = dht1.readHumidity();
  float t1 = dht1.readTemperature();
  Serial.println("Sensor 1:");
  Serial.print("Humedad: ");
  Serial.print(h1);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t1);
  Serial.println(" *C ");
  
  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
  Serial.println("Sensor 2:");
  Serial.print("Humedad: ");
  Serial.print(h2);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t2);
  Serial.println(" *C ");
  
  // Proceso de envio de muestras al servidor
  Serial.println("Conectando con el servidor...");
  if (client.connect(server, 80)>0) {  // Conexion con el servidor
    client.print("GET /temp.php?temp1="); // Enviamos los datos por GET
    client.print(t1);
    client.print("&hume1=");
    client.print(h1);
    client.print("&temp2=");
    client.print(t2);
    client.print("&hume2=");
    client.print(h2);
    client.println(" HTTP/1.0");
    client.println("User-Agent: Arduino 1.0");
    client.println();
    
  } else {
    Serial.println("Fallo en la conexion");
  }
    
  if (!client.connected()) {
    Serial.println("Reintento!");
  }
  client.stop();
  client.flush();
  delay(60000); // Espero un minuto antes de tomar otra muestra
}
