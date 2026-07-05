````markdown
<p align="center">

# 🏠 AI Smart Home
### *An End-to-End IoT & Artificial Intelligence Smart Home System*

An intelligent Smart Home platform that combines **ESP32**, **IoT**, **Cloud Computing**, **MQTT**, **Machine Learning**, and **Real-Time Dashboards** into one integrated system capable of monitoring, automation, remote control, and AI-driven analytics.

---

<p align="center">

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
```

