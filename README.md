# 🌀 Wavering Arc: A Multispecies Boundary Visualization Device

This repository contains the design files and code for **Wavering Arc**, a speculative interaction prototype exploring emotional tension and boundary negotiation between humans and cockroaches. The device transforms physiological and behavioral data into spatial motion, embodying the concept of *floating boundaries* in a multispecies context.

---

## 📁 Repository Contents

- `Wavering Arc.3mf`  
  → 3D model of the Wavering Arc, ready for 3D printing.

- `human_cockroach.ino`  
  → Arduino sketch to collect sensor data (IR sensors + heart rate) and control stepper motor movement.

- `human_cockroach_processing.pde`  
  → Processing sketch for optional real-time visualization of data from both species.

---

## 🧠 Concept Summary

**Wavering Arc** consists of two main components:

- **Archway Part**  
  A physical tunnel equipped with infrared sensors that measure the cockroach's speed. The structure is shaped based on ethological principles including **thigmotaxis** (wall-following), **negative phototaxis** (light avoidance), and **velocity as arousal**.

- **Wavering Part**  
  A flexible arc actuated by a stepper motor, translating both cockroach velocity and human heart rate into visible oscillation. The more tension or arousal detected, the more intense the movement.

The design seeks to materialize the *affective ambiguity* of interspecies encounters through an unstable, shared spatial structure.

---

## 🛠 Hardware Requirements

- Arduino Uno (or compatible)
- 2 × Infrared sensors (e.g. IR distance sensors)
- 1 × Pulse sensor (or external heart rate input)
- 1 × Stepper motor (28BYJ-48 or similar) + ULN2003 driver board
- Breadboard, wires, power supply

---

## ⚙️ How to Use

### 1. 3D Print the Structure  
Use the `.3mf` file in slicing software (e.g., PrusaSlicer or Cura) to print both the arch and rotating surface.

### 2. Upload Arduino Code  
Open `human_cockroach.ino` in Arduino IDE and upload.  
Connect IR sensors and heart rate sensor to analog pins as configured.

### 3. (Optional) Launch Processing Visualization  
Run `human_cockroach_processing.pde` in Processing to visualize sensor data and observe motor states in real time.

---

## 🧪 Research Background

This project originates from a design research inquiry into **abjected species** and the ethics of co-designing with the non-charismatic other. Drawing on:
- Animal behavior science
- Autoethnography
- Animal Writing as a non-anthropocentric observation method

It attempts to foreground the **emotional, spatial, and physiological negotiation** that occurs when two species inhabit the same disturbed boundary.

---

## 📜 License

MIT License.  
Use freely for research, education, or experimental design work. Attribution appreciated.

---

## 📷 Preview

![Prototype](images/Pic1.png)

---

