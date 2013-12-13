// Bluetooth glove
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
HardwareSerial Uart = HardwareSerial();
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

int i;
int x;
int y;
int z;
char message[40];
long now;
void setup() {
  Uart.begin(9600);
  Serial.begin(9600);
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }
  
  accel.setRange(ADXL345_RANGE_16_G);
  // displaySetRange(ADXL345_RANGE_8_G);
  // displaySetRange(ADXL345_RANGE_4_G);
  // displaySetRange(ADXL345_RANGE_2_G);

}

void loop() {
  sensors_event_t event; 
  accel.getEvent(&event);

  now = millis() / 1000L;

  //USB serial
  Serial.print("{\"x\":"); 
  Serial.print(event.acceleration.x); 
  Serial.print(",");
  Serial.print("\"Y\":"); 
  Serial.print(event.acceleration.y); 
  Serial.print(",");
  Serial.print("\"z\":"); 
  Serial.print(event.acceleration.z); 
  Serial.println("}");
 
  //bluetooth
  Uart.print("{\"x\":"); 
  Uart.print(event.acceleration.x); 
  Uart.print(",");
  Uart.print("\"Y\":"); 
  Uart.print(event.acceleration.y); 
  Uart.print(",");
  Uart.print("\"z\":"); 
  Uart.print(event.acceleration.z); 
  Uart.println("}");
 
  delay(100);
}


