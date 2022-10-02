// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 3
#define TEMPERATURE_PRECISION 9

#define HEATER_PIN 5
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// arrays to hold device addresses
DeviceAddress *thermometers;

int deviceCount = 0;

void setup(void)
{
  pinMode(HEATER_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();

}

void printDevicesInfo() {
  // report parasite power requirements
  Serial.print("Parasite power is: "); 
  if (sensors.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");

  thermometers = new DeviceAddress[deviceCount];
  for (int i = 0; i < deviceCount; i++) {
      if (!sensors.getAddress(thermometers[i], i)) Serial.println("Unable to find address for Device 0"); 
  }

  // show the addresses we found on the bus
  for (int i = 0; i < deviceCount; i++) {
      Serial.print("Device ");
      Serial.print(deviceCount);
      Serial.print(" Address: ");
      printAddress(thermometers[i]);
      Serial.println();
      sensors.setResolution(thermometers[i], TEMPERATURE_PRECISION);
      Serial.print("Resolution: ");
      Serial.print(sensors.getResolution(thermometers[i]), DEC); 
      Serial.println();
  }
}

// function to print a device address
void printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    // zero pad the address if necessary
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}

// function to print the temperature for a device
void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
  Serial.print("Temp C: ");
  Serial.print(tempC);
}

// function to print a device's resolution
void printResolution(DeviceAddress deviceAddress)
{
  Serial.print("Resolution: ");
  Serial.print(sensors.getResolution(deviceAddress));
  Serial.println();    
}

// main function to print information about a device
void printData(DeviceAddress deviceAddress)
{
  Serial.print("Device Address: ");
  printAddress(deviceAddress);
  Serial.print(" ");
  printTemperature(deviceAddress);
  Serial.println();
}

/*
 * Main function, calls the temperatures in a loop.
 */
void loop(void) { 

  int newDeviceCount = sensors.getDeviceCount();

  if (newDeviceCount != deviceCount) {
      deviceCount = newDeviceCount;
      Serial.print("Device count changed: ");
      deviceCount = sensors.getDeviceCount();
      Serial.println(deviceCount, DEC);
      printDevicesInfo();
  }
    


  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();
  Serial.println("DONE");

  for (int i = 0; i < deviceCount; i++) {
      printData(thermometers[i]);
  }
  
  delay(1000);
}

