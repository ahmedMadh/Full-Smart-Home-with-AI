

# 🏠 AI Smart Home
### *An End-to-End IoT & Artificial Intelligence Smart Home System*

An intelligent Smart Home platform that combines **ESP32**, **IoT**, **Cloud Computing**, **MQTT**, **Machine Learning**, and **Real-Time Dashboards** into one integrated system capable of monitoring, automation, remote control, and AI-driven analytics.


![ESP32](https://img.shields.io/badge/ESP32-IoT-blue?style=for-the-badge)
![Arduino](https://img.shields.io/badge/Arduino-C%2B%2B-success?style=for-the-badge)
![MQTT](https://img.shields.io/badge/MQTT-HiveMQ-orange?style=for-the-badge)
![Blynk](https://img.shields.io/badge/Blynk-IoT-green?style=for-the-badge)
![ThingSpeak](https://img.shields.io/badge/ThingSpeak-Cloud-red?style=for-the-badge)
![Python](https://img.shields.io/badge/Python-AI-yellow?style=for-the-badge)
![Flask](https://img.shields.io/badge/Flask-API-black?style=for-the-badge)
![Jupyter](https://img.shields.io/badge/Jupyter-Notebook-orange?style=for-the-badge)
![Pandas](https://img.shields.io/badge/Pandas-Data-blueviolet?style=for-the-badge)
![Machine Learning](https://img.shields.io/badge/Machine-Learning-purple?style=for-the-badge)

</p>

---

# 📖 Table of Contents

- Project Overview
- Key Features
- System Architecture
- Data Flow
- Hardware Components
- Software Stack
- Folder Structure
- Code Architecture
- Automation Logic
- Cloud Communication
- AI Pipeline
- Installation
- Usage
- Screenshots
- Future Improvements
- Author

---

# 🚀 Project Overview

AI Smart Home is a complete Internet of Things (IoT) platform that monitors environmental conditions inside a smart house while providing both automatic and manual control over connected devices.

The project combines two independent cloud communication methods:

- **ThingSpeak** for real-time cloud visualization.
- **MQTT** for continuous data streaming into Python.

Sensor readings are automatically collected by the ESP32 and transmitted to multiple destinations simultaneously. The stored dataset is later analyzed using Machine Learning techniques inside Jupyter Notebook.

Unlike traditional smart home projects, this system is designed not only for monitoring but also for creating a structured AI-ready dataset capable of supporting predictive analytics.

---

# ⭐ Key Features

## 🌡 Environmental Monitoring

- Temperature Monitoring
- Humidity Monitoring
- Gas Leakage Detection
- Motion Detection
- Ambient Light Detection
- Water Tank Level Monitoring

---

## 🤖 Smart Automation

- Automatic Window Control
- Automatic Fan Control
- Automatic Lighting
- Automatic Water Pump
- Fire Detection
- Gas Emergency Response
- Smart Alarm System

---

## ☁ Cloud Integration

- MQTT Communication
- ThingSpeak Cloud Storage
- Live Charts
- CSV Dataset Generation
- Python Data Pipeline

---

## 🧠 Artificial Intelligence

- Dataset Collection
- Data Cleaning
- Machine Learning Preparation
- Prediction Pipeline
- Future Risk Analysis

---

# 🏗 System Architecture

```text
                    +----------------------+
                    |      Sensors         |
                    |----------------------|
                    | DHT22                |
                    | MQ-2                 |
                    | PIR                  |
                    | LDR                  |
                    | Ultrasonic           |
                    +----------+-----------+
                               |
                               |
                               v
                     +------------------+
                     |      ESP32       |
                     +--------+---------+
                              |
          +-------------------+-------------------+
          |                                       |
          |                                       |
          v                                       v

   ThingSpeak Cloud                       MQTT Broker
          |                                       |
          |                                       |
          v                                       v

  Live IoT Dashboard                    Jupyter Notebook
                                                |
                                                |
                                                v

                                         CSV Dataset
                                                |
                                                |
                                                v

                                        Machine Learning
                                                |
                                                |
                                                v

                                           AI Prediction
````

---

# 🔄 Complete Data Flow

```text
Sensors
      │
      ▼
ESP32 Controller
      │
      ├────────► ThingSpeak
      │              │
      │              ▼
      │       Live Cloud Charts
      │
      │
      └────────► MQTT Broker
                     │
                     ▼
             Jupyter Notebook
                     │
                     ▼
              CSV Dataset Storage
                     │
                     ▼
             Machine Learning Model
                     │
                     ▼
                Future Prediction
```

---

# 💡 Why This Project?

Most IoT projects stop after displaying sensor values on a dashboard.

This project goes one step further by transforming live sensor readings into a structured dataset that can later be used to train Artificial Intelligence models capable of predicting future environmental conditions and supporting autonomous decision making.

It demonstrates how IoT and AI can work together within one complete architecture instead of existing as separate technologies.

```
````markdown
---

# 🛠 Hardware Components

The smart home system is built using six environmental sensors and multiple actuators connected to an ESP32 development board.

| Component | Function |
|-----------|----------|
| ESP32 | Main microcontroller responsible for data acquisition, automation, and cloud communication |
| DHT22 | Measures temperature and humidity |
| MQ-2 Gas Sensor | Detects gas leakage and smoke concentration |
| PIR Motion Sensor | Detects human movement |
| LDR Sensor | Measures ambient light intensity |
| HC-SR04 Ultrasonic Sensor | Monitors the water tank level |
| Servo Motor | Opens and closes the smart window |
| Relay Module | Controls the fan and water pump |
| LED | Visual alarm indicator |
| Buzzer | Audible emergency alarm |

---

# 💻 Software Stack

The project integrates embedded programming, cloud computing, data engineering, and Artificial Intelligence into one complete workflow.

| Technology | Purpose |
|------------|---------|
| Arduino IDE | ESP32 programming |
| Wokwi | Circuit simulation |
| MQTT (HiveMQ) | Real-time data streaming |
| ThingSpeak | Cloud monitoring platform |
| Blynk IoT | Remote mobile control |
| Python | Data processing |
| Jupyter Notebook | AI development environment |
| Flask | Local API Server |
| Pandas | Dataset management |
| Paho MQTT | MQTT communication |
| Machine Learning | Data prediction |

---

# 📂 Project Structure

```text
AI-Smart-Home
│
├── Arduino_Code
│     └── smart_home.ino
│
├── Python
│     ├── mqtt_receiver.py
│     ├── dashboard.ipynb
│     ├── ai_model.ipynb
│     └── server.py
│
├── Dataset
│     └── sensor_data.csv
│
├── Images
│
├── Report
│     └── AI_Full_Smart_Home_Project_Report.pdf
│
└── README.md
```

The repository is organized so that every project layer is separated into its own directory, making the system easier to understand, maintain, and extend.

---

# ⚙ Code Architecture

Instead of writing all functionality inside one long program, the firmware is divided into logical modules, where each module is responsible for a specific task.

```text
setup()

↓

Initialize Hardware

↓

Connect WiFi

↓

Connect MQTT

↓

Connect Blynk

↓

Start Sensors
```

---

## Main Loop

The ESP32 continuously executes the following cycle:

```text
Read Sensors

↓

Update Sensor Variables

↓

Check Safety Conditions

↓

Execute Automation

↓

Publish MQTT Data

↓

Upload ThingSpeak Data

↓

Repeat
```

---

# 📦 Firmware Modules

The ESP32 firmware is divided into several independent modules.

## 🌡 Sensor Module

Responsible for collecting all environmental readings.

**Sensors**

- DHT22
- MQ-2
- PIR
- LDR
- HC-SR04

Output:

- Temperature
- Humidity
- Gas Level
- Motion Status
- Light Level
- Water Tank Distance

---

## 🚨 Safety Module

Continuously evaluates dangerous situations.

Possible events:

- Gas leakage
- High temperature
- Fire
- Safe state

Automatic response:

- Activate buzzer
- Turn alarm LED ON
- Open window
- Start ventilation fan

---

## 🤖 Automation Module

Handles all smart home decisions without user interaction.

Automation includes:

- Smart ventilation
- Smart lighting
- Water tank management
- Emergency handling

Each subsystem operates independently while sharing the same sensor data.

---

## ☁ Cloud Module

Responsible for transmitting sensor readings.

The ESP32 simultaneously sends data to:

- ThingSpeak
- MQTT Broker

This allows the same sensor readings to be used for both live monitoring and AI processing without interfering with each other.

---

## 📱 Manual Control Module

Users can manually operate the smart home through the Blynk mobile application.

Available controls include:

- Window
- Fan
- Lighting
- Water Pump
- Alarm Reset
- Auto Mode

When Auto Mode is enabled, the ESP32 automatically manages all devices according to the predefined control logic.

---

# 🧩 Main Functions

| Function | Responsibility |
|----------|----------------|
| setup() | Initializes the entire system |
| loop() | Main execution cycle |
| NewValues() | Reads all sensors |
| alarmSystem() | Handles emergency situations |
| autoControl() | Controls ventilation |
| waterControl() | Controls water pump |
| lightingControl() | Controls smart lighting |
| Full_AUTO_Mode() | Executes complete automation |
| reconnect() | Restores MQTT connection |

---

# 🔍 Code Design Philosophy

The firmware follows a modular programming approach.

Instead of placing all logic inside the `loop()` function, each task is isolated into dedicated functions.

This design provides several advantages:

- Better readability
- Easier debugging
- Higher scalability
- Improved maintainability
- Simple future expansion

Additional sensors or AI modules can be integrated with minimal modifications to the existing code.
````

```

