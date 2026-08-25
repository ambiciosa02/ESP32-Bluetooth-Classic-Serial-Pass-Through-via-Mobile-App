/*
  Bluetooth Serial Client Demo
  bluetooth_serial_client.ino
  Demonstrates operation of BluetoothSerial Library
  Based upon open-source code sample by Evandro Copercini - 2018
  
  DroneBot Workshop 2024
  https://dronebotworkshop.com
*/

// Include BluetoothSerial library.
#include "BluetoothSerial.h"

// Name of Bluetooth client.
String device_name = "ESP32-BT-Client";

// Check if Bluetooth is available.
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled!
#endif

// Check if Serial Port Profile (SPP) is available.
#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Port Profile for Bluetooth is not available or not enabled!
#endif

// Create a BluetoothSerial object.
BluetoothSerial SerialBT;

void setup() {
  // Start Serial Monitor.
  Serial.begin(115200);

  // Start Bluetooth Serial.
  SerialBT.begin(device_name);

  // Uncomment the next line to delete previously paired devices. Must be called directly after bluetooth begin.
  //SerialBT.deleteAllBondedDevices();

  // Print to serial monitor.
  Serial.printf("The device \"%s\" is started and can be paired with Bluetooth.\n", device_name.c_str());
}

void loop() {
  // Check for messsage from serial monitor.
  if (Serial.available()) {
    // Write message to paired Bluetooth device.
    SerialBT.write(Serial.read());
  }

  // Check for message from paired Bluetooth device.
  if (SerialBT.available()) {
    // Write message to serial monitor.
    Serial.write(SerialBT.read());
  }
  delay(20);
}