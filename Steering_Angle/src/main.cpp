// //
// //    FILE: AS5600_outmode_analog_100.ino
// //  AUTHOR: Rob Tillaart
// // PURPOSE: experimental demo
// //     URL: https://github.com/RobTillaart/AS5600
// //
// //  connect the OUT pin to the analog port of the processor


//
//    FILE: AS5600_outmode_analog_100.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: experimental demo
//     URL: https://github.com/RobTillaart/AS5600
//
//  connect the OUT pin to the analog port of the processor


#include "AS5600.h"


AS5600 as5600;   //  use default Wire


void setup()
{
  pinMode(21,PULLUP);
  pinMode(22,PULLUP);
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("AS5600_LIB_VERSION: ");
  Serial.println(AS5600_LIB_VERSION);

  Wire.begin();

  as5600.begin(19);  //  set direction pin.
  as5600.setDirection(AS5600_CLOCK_WISE);  //  default, just be explicit.
  as5600.setOutputMode(AS5600_OUTMODE_ANALOG_100);
}


void loop()
{
  Serial.print(millis());
  Serial.print("\t");
  Serial.println(as5600.readAngle());
}


//  -- END OF FILE --

// #include "HX711.h"

// // HX711 circuit wiring
// const int LOADCELL_DOUT_PIN = 2;
// const int LOADCELL_SCK_PIN = 4;

// HX711 scale;

// void setup() {
//   // pinMode(34,HIGH);
//   Serial.begin(57600);
//   scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
// }

// void loop() {

//   if (scale.wait_ready_timeout(1000)) {
//     long reading = scale.read();
//     Serial.print(millis());
//     Serial.print("HX711 reading: ");
//     Serial.println(reading);
//   } 
// }