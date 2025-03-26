#include<dht.h>
  
/*
A0 :- Moisture Sensor
*/

//Definitions
#define moistureSensor A0 
#define airSensor A1
#define DHT11_PIN 7
#define rainSensor A2
#define flexSensor A3
//Global variables
const int dry = 595; // value for moisture dry sensor
const int wet = 239; // value for moisture wet sensor
dht DHT;


//Setup 
void setup() {
  //Set baud rate
  Serial.begin(9600);
  pinMode(A7,  INPUT);
}

void loop() 
{
  ///Moisture Sensor
  //Get moisture value
  int moistureVal = analogRead(moistureSensor);
  
  //Percentage humidity
  float percentageHumidity = map(moistureVal,wet,dry,100,0);
  
  ///Air Quality Sensor
  int airQuality = analogRead(airSensor);
  

  ///DHT Humidity & Temperature sensor
  int chk = DHT.read11(DHT11_PIN);

  ///Rain Sensor
  int rain = analogRead(rainSensor);// Read the analog value from the sensor
  rain = map(rain,0,1023,255,0);//Map the 10 bit number to 8 bits
  //Flex sensor
  int flex = analogRead(flexSensor); //Read and save analog value
  flex = map(flex,700,900,0,255);

  //Print values
  Serial.print(percentageHumidity);
  Serial.print("% ");
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.print(" Humidity = ");
  Serial.print(DHT.humidity);
  Serial.print(" CO2 (ppm) ");
  Serial.print(airQuality);
  Serial.print(" Rain Quantity ");
  Serial.print(rain);
  Serial.print(" Flex ");
  Serial.print(flex);
  Serial.println();

  //Delay
  delay(100);


}
