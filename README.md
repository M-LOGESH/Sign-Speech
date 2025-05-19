#  Bluetooth Text-to-Speech (TTS) Smart Glove

A wearable assistive system that interprets sign language gestures into text and speech using accelerometers, an ESP32 microcontroller, and a Bluetooth-connected mobile application. Designed to enhance communication accessibility for individuals with speech impairments.

##  Project Overview

This project integrates a **smart glove** with embedded accelerometers and an **Android mobile application**. The glove detects hand gestures corresponding to sign language using the ADXL335 accelerometers, which are processed in real-time by the ESP32 microcontroller. Recognized gestures are transmitted to a mobile device via Bluetooth and then converted into text and synthesized speech using the TTS app.

---

## 🔍 System Components

### 1. Smart Glove Hardware
- **ESP32 Microcontroller**: Main processing unit for gesture recognition and Bluetooth communication.
- **ADXL335 Accelerometers**: Detects hand and finger movements in 3 axes (X, Y, Z).
- **Power Supply**: Battery-powered for portable use.
- **Glove Material**: Mounts the sensors comfortably on the user's hand.

### 2. Mobile Application
- **Bluetooth Connectivity**: Pairs with ESP32 for data reception.
- **Text Display**: Shows recognized sign language words/phrases.
- **Text-to-Speech (TTS)**: Converts received text into audible speech.
- **Audio Settings**: Allows customization of pitch and speed.

---

## ⚙️ Features

- 🔄 Real-time gesture-to-speech conversion.
- 🔗 Wireless Bluetooth communication.
- 🔊 Adjustable speech pitch and speed.
- 📲 Intuitive mobile interface.
- 👨‍🦯 Designed for users with speech and hearing impairments.

---

## 📋 Functional Flow

1. Hand gestures are detected via ADXL335 accelerometers.
2. Data is processed by ESP32 using gesture recognition algorithms.
3. Recognized words are sent via Bluetooth to the mobile application.
4. The app displays the text and speaks it using TTS.

---

## 🔧 Setup Instructions

### 🧤 Hardware
1. Attach **ADXL335** sensors to each finger of the glove.
2. Connect sensors to the **ESP32** analog input pins.
3. Power the ESP32 with a suitable battery module.
4. Upload gesture recognition firmware to the ESP32 using Arduino IDE.

### 📱 Mobile App
1. Install the **Bluetooth TTS App** (APK or from Play Store if available).
2. Pair your phone with the ESP32 via Bluetooth.
3. Open the app and begin using gestures to see and hear the translated speech.

---

## 🔩 Requirements

### Hardware
- ESP32 Development Board
- 5 x ADXL335 Accelerometers
- Lithium Polymer Battery
- Smart Glove (DIY or custom)

### Software
- Arduino IDE
  
---

##  Block Diagram

