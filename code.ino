// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>


// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2
int temp;
float grad;
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);





/*
 * The setup function. We only start the sensors here
 */
void setup(void)
{
    pinMode(A1, INPUT); //Internal temperature = analogic
  Serial.begin(9600);
  sensors.begin();
}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{
 
sensors.requestTemperatures(); // Send the command to get temperatures


 delay(500); //Wait 500ms

  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if (tempC != DEVICE_DISCONNECTED_C)
  {
    Serial.print("Temperature exterieure en Celsius: ");
    Serial.println(tempC); //tempC = external sensor
       Serial.println(" "); 
  
    temp = analogRead(A1);
  grad = (temp/1023.0)*5.0*1000/10;
  Serial.print("Temperature interieure en Celsius: ");
  Serial.print(grad);
     Serial.println(" ");
  }

}
