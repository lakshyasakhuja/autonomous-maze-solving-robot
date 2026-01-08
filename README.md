# Autonomous Maze-Solving Robot

This repository contains my **ELEC1601 (Introduction to Electrical Engineering)** project from the **University of Sydney (Semester 1)**.

This project involved designing, building, and programming an **autonomous robot car** capable of navigating a **physical maze** using **infrared sensors, servo motors, and embedded C++ (Arduino)**. The robot competed in a timed maze-solving challenge and achieved a **best completion time of 46.726 seconds**, placing **2nd overall in the cohort**.

---

## 📘 Project Overview

At a high level, this project focuses on building a **fully autonomous robotic system** that can perceive its environment, make decisions in real time, and navigate a constrained physical space without human input.

The robot uses **infrared sensing** to detect maze walls and obstacles, and **servo-controlled wheels** to adjust direction, speed, and orientation dynamically. All decisions are made onboard using embedded control logic written in C++.

The project was completed across multiple stages of increasing complexity and culminated in a **competitive, time-based maze challenge**.

---

## 🌍 Project Motivation & Challenge

The primary challenge of this project was to integrate **hardware and software** into a single reliable system operating under real-world constraints.

Key challenges included:

* Interpreting noisy sensor data in real time
* Making correct movement decisions without global maze knowledge
* Handling dead ends and tight corners
* Balancing speed with stability and accuracy
* Optimising performance for competitive timing

The project mirrors real autonomous systems, where decisions must be made **locally and continuously**, without external computation or correction.

---

## ⚙️ System Design & Hardware

The robot platform consists of:

* An **Arduino-based control board**
* Three **infrared emitters and receivers** (left, middle, right)
* Two **continuous-rotation servo motors**
* Indicator LEDs for sensor feedback
* A custom-built **physical maze environment**

The IR sensors continuously detect proximity to walls, enabling the robot to determine whether to move forward, adjust course, turn, or stop.

---

## 🧠 Software & Control Logic

The robot was programmed using **embedded C++ with the Arduino framework**.

Core software features include:

* Independent detection functions for left, middle, and right IR sensors
* Continuous sensor polling and real-time decision making
* Microsecond-level servo control for smooth motion
* Dedicated movement functions for:

  * Forward motion
  * Fine left/right adjustment
  * 90-degree turns
  * Emergency stopping
  * Rotational recovery behaviour

The control logic evaluates combinations of sensor inputs to determine the safest and most efficient movement at every moment.

---

## 🧪 Development Stages & Performance

The project was completed in **three stages**:

### Essentials

* Basic wall detection
* Forward movement and obstacle avoidance

### Extension

* Improved turning accuracy
* Speed control and trajectory correction

### Advanced (Competition Stage)

* Fully autonomous maze navigation
* Optimised control logic for speed and reliability
* Timed performance against the full cohort

**Final Result:**

* **Best time:** 46.726 seconds
* **Ranking:** 2nd place overall
* **Mode:** Fully autonomous (no human input)

---

## 🧠 Key Learnings

* Designing autonomous systems under physical constraints
* Translating sensor input into real-time control logic
* Embedded systems programming and debugging
* Servo motor calibration and motion control
* Hardware-software integration and iterative testing
* Performance optimisation in real-time environments

---

## 🛠 Tools & Technologies

* **Arduino**
* **Embedded C++**
* **Infrared sensors**
* **Servo motors**
* **Control logic & real-time systems**
* **Physical prototyping**

---

## 📝 Significance

This project represents my **first large-scale hardware + software integration project**.

It strengthened my understanding of:

* Autonomous robotics
* Embedded programming
* Control systems
* Real-time decision making

Placing **2nd overall** validated both the **design decisions** and the **robustness of the control algorithm**, and sparked a strong interest in robotics and intelligent systems.

---

## 🎓 Course Information

* **University:** The University of Sydney
* **Unit:** ELEC1601 – Introduction to Electrical Engineering
* **Assessment Type:** Autonomous Robotics Project
* **Semester:** Semester 1
