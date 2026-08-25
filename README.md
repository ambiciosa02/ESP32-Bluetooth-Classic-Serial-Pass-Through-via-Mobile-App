 # ESP32 Bluetooth Classic Serial Pass-Through via Mobile App
A simple ESP32 demonstration project that creates a bi-directional serial bridge between the USB Serial Monitor and a smartphone using the Serial Bluetooth Terminal app over Bluetooth Classic (Serial Port Profile / SPP).

## Overview
This project configures the ESP32 as a Bluetooth Classic slave device named ESP32-BT-Client. It listens for incoming serial data from a computer via USB and forwards it over Bluetooth, while simultaneously receiving Bluetooth data and printing it back to the Serial Monitor.

## Features
Bluetooth Classic (SPP): Implements standard Bluetooth Serial Port Profile for transparent wireless serial communication.

Bi-Directional Communication: Real-time data pass-through between USB UART (Serial) and Bluetooth (SerialBT).

Pre-Compile Verification: Includes preprocessor checks to ensure Bluetooth and SPP stacks are enabled before compilation.

## Hardware & Software Requirements
Hardware: ESP32 Development Board (e.g., NodeMCU-32S / ESP-WROOM-32).

Software Environment: Arduino IDE with the ESP32 board support package installed.

Testing Tool: Serial Terminal App on a smartphone (e.g., Serial Bluetooth Terminal for Android) or a PC Bluetooth terminal.

## Hardware Configuration
Baud Rate: 115200 baud

Target Board: ESP32 Dev Module (or equivalent ESP32 board)

## How It Works
setup(): Initializes USB serial communication at 115200 baud and starts the Bluetooth stack under the device name ESP32-BT-Client.

loop(): Continuously polls Serial.available() and SerialBT.available() to relay bytes back and forth with a 20 ms polling delay.

## Getting Started
1. Open bluetooth_serial_client.ino in the Arduino IDE.

2. Select your ESP32 board and correct COM port under Tools.

3. Upload the sketch to your ESP32 board.

4. Open the Arduino Serial Monitor and set the baud rate to 115200 baud.

5. On your smartphone or PC, turn on Bluetooth, search for ESP32-BT-Client, and pair with it.

6. Open your Bluetooth terminal app, connect to ESP32-BT-Client, and begin typing messages to test bi-directional data transmission.

## Test Verification & Output

The project was validated using an **ESP32-S module** paired with the **Serial Bluetooth Terminal** app (Android) over **Bluetooth Classic (SPP)**.

### 1. ESP32 Boot Log (USB Serial Monitor @ 115200 baud)
<br><br><img width="400" height="400" alt="image" src="https://github.com/user-attachments/assets/53bbfe27-a5d6-441a-8d74-421503d46d03" />
<br><br>
### 2. Smartphone Terminal Log (Serial Bluetooth Terminal)
<br><br>
<img width="400" height="400" alt="image" src="https://github.com/user-attachments/assets/46d6cb2f-725c-4719-af5b-451822b4cdd1" />
<br><br>
<img width="400" height="400" alt="image" src="https://github.com/user-attachments/assets/0cdf5af4-64a2-49eb-b94b-0c807947bd9f" />
<br><br>
### 3. App Connection & Terminal Interface
<br><br>
<img width="400" height="400" alt="image" src="https://github.com/user-attachments/assets/69af2343-0a15-4d39-b934-8a162744d97c" />
<br><br>


## Conclusion

This project successfully demonstrates basic wireless serial communication using an ESP32-S module configured under Bluetooth Classic (SPP). By bridging the hardware UART interface (`Serial`) with the Bluetooth protocol stack (`SerialBT`), the system establishes a reliable, bi-directional link with external terminal applications. This setup serves as a foundational template for telemetry streaming, remote parameter configuration, and embedded system diagnostics.
