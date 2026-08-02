# 🌐 ESP32 Web-Based Servo Motor Control

> **Developed by:** Meshal Al Mehmady

---

<p align="center">
 <img src="https://github.com/user-attachments/assets/abd86c9f-93bf-4316-8e54-9d3cdf4cfecd"
 width="90%">
</p>

---

## 📖 Project Overview

This project demonstrates how to control a **Servo Motor wirelessly using an ESP32 microcontroller through a web-based control interface**.

The ESP32 is configured as a **WiFi Access Point**, allowing users to connect directly to the board without requiring an external WiFi router.

A simple web page is hosted directly on the ESP32 using a built-in **Web Server**, providing two control buttons:

- **OPEN** → Moves the servo motor to the opening position, turns ON the green LED, and turns OFF the red LED.
- **CLOSE** → Returns the servo motor to the closing position, turns ON the red LED, and turns OFF the green LED.

The project was first designed and tested using **Wokwi ESP32 Simulation**, then successfully implemented and verified on real ESP32 hardware.

---

## 📂 Project Structure

```text
ESP32-Web-Servo-Control/
│
├── ESP32_Web_Servo_Control.ino
├── README.md
└── demo_live-2.mp4
```

---

## 🔌 Hardware Components

- ESP32 D1 Mini (ESP32-WROOM-32)
- SG90 Servo Motor
- Green LED
- Red LED
- 220Ω Resistors
- Breadboard
- Jumper Wires
- USB Cable

---

## 🔗 System Connections

### Servo Motor

| Servo Wire | ESP32 Pin |
|------------|-----------|
| Signal | GPIO 18 |
| VCC | VCC (5V) |
| GND | GND |

---

### Green LED

| LED Pin | ESP32 Pin |
|---------|-----------|
| Anode (+) | GPIO 26 (through 220Ω resistor) |
| Cathode (-) | GND |

---

### Red LED

| LED Pin | ESP32 Pin |
|---------|-----------|
| Anode (+) | GPIO 27 (through 220Ω resistor) |
| Cathode (-) | GND |

---

## 🖥️ Wokwi Simulation

The project was initially developed and tested using **Wokwi ESP32 Simulator** before moving to the physical hardware implementation.

The simulation stage was used to verify:

- Servo motor control.
- LED status indicators.
- ESP32 program logic.
- Web server functionality.

After successful testing, the same system was transferred to the real ESP32 board.

<p align="center">
 <img src="https://github.com/user-attachments/assets/4d15c628-b51c-410f-8fd5-a7486899699a" 
 width="90%">
</p>

---

## 📱 Web Interface

The ESP32 creates its own WiFi network using **Access Point Mode**.

Users can connect directly to the ESP32 network and access the control webpage through:

```
192.168.4.1
```

The webpage provides two simple control buttons:

- OPEN
- CLOSE

Each button sends a command to the ESP32 Web Server to control the servo motor and update the LED indicators.

---

## 📸 Real Hardware Setup

<p align="center">
 <img src="https://github.com/user-attachments/assets/21968edd-19ac-4769-9767-57b181406968"
 width="90%">
</p>

---

## ⚙️ Program Behavior

The ESP32 program performs the following sequence:

1. Initializes the servo motor and LED pins.
2. Creates a WiFi Access Point.
3. Starts a local Web Server.
4. Hosts a web control interface.
5. Receives user commands from the webpage.
6. Controls the servo position and LED status.

### OPEN Command

When the **OPEN** button is pressed:

- Servo motor rotates to **90°**.
- Green LED turns ON.
- Red LED turns OFF.

---

### CLOSE Command

When the **CLOSE** button is pressed:

- Servo motor rotates to **0°**.
- Red LED turns ON.
- Green LED turns OFF.

---

## 🛠️ Development Process

The project was developed through multiple stages:

### 1. Simulation Stage

The system was first tested using **Wokwi ESP32 Simulator** to verify the circuit behavior and control logic.

### 2. Hardware Implementation

After confirming the design, the project was transferred to a real ESP32 D1 Mini board.

### 3. Wireless Control Testing

The final system was tested using a mobile device connected directly to the ESP32 WiFi Access Point.

---

## 🚧 Challenges & Solutions

During development, several challenges were encountered:

- Testing the web interface inside the simulation environment was limited compared to real hardware.
- The ESP32 Access Point mode was tested and verified on the physical board.
- Servo power requirements were considered to ensure stable operation.
- The final system successfully achieved wireless servo control through a local webpage.

---

## 🧰 Technologies Used

- ESP32
- Arduino IDE
- C++ (Arduino Framework)
- WiFi Access Point Mode
- Web Server
- HTML
- ESP32Servo Library
- Wokwi Simulator

---

## 📚 References

- ESP32 Documentation
- Arduino IDE Documentation
- ESP32Servo Library
- Wokwi ESP32 Simulator
