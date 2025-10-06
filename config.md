# ⚙️ Configuration & Setup – Gas Leak Detector with OLED Display

This file explains the **hardware configuration**, **wiring**, and **connections** used in the Gas Leak Detector project.

---

## 🧠 Microcontroller
**ESP32 (recommended)**  
Alternatively, you can use **Arduino UNO**, but the pin numbers may vary.

---

## 🔌 Pin Connections

| Component        | ESP32 Pin | Description |
|------------------|------------|--------------|
| MQ-2 Gas Sensor  | A2 (GPIO 34) | Analog output from gas sensor |
| Buzzer           | GPIO 25     | Activates alarm when gas exceeds threshold |
| LED (Warning)    | GPIO 26     | Turns ON when gas detected |
| OLED Display (SSD1306) | SDA → 21 <br> SCL → 22 | I²C communication pins |

---

## 🌡️ Sensor Thresholds
| Parameter | Default Value | Description |
|------------|----------------|-------------|
| Gas Threshold | `300` | When gas sensor value exceeds this, alarm triggers |

---

## 💻 Required Libraries
Install these libraries in Arduino IDE before uploading the code:
1. `Adafruit SSD1306`
2. `Adafruit GFX Library`
3. `Wire` (Built-in)
4. `DHT` (if you use DHT11 or DHT22)

Go to **Sketch → Include Library → Manage Libraries** and install them.

---

## 🪛 Power & Components
| Component | Voltage | Notes |
|------------|----------|-------|
| MQ-2 Sensor | 5V | Needs preheating for accurate reading |
| OLED Display | 3.3V | Compatible with ESP32 |
| Buzzer | 3.3V | Connect through GPIO pin |
| LED | 3.3V | Use a 220Ω resistor |

---

## 🔧 Assembly Notes
- Make sure MQ-2 analog output is connected to an **ADC pin** (e.g., 34, 35, 36).  
- Calibrate the **gasThreshold** based on room environment (open serial monitor and note values).  
- Connect **GND** of all components to ESP32 **GND**.

---

## ✅ Testing
1. Upload the `gas_detector.ino` sketch.  
2. Open Serial Monitor (115200 baud).  
3. Check readings.  
4. When gas level > 300 → LED + Buzzer + OLED Warning.

---
****
