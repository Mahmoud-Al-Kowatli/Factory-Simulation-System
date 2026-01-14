# 🏭 Factory Simulation System - ASPU Project 2026

## 📝 Overview |  
This project is a comprehensive simulation of a multi-line factory production system, developed for the **Algorithms and Data Structures** course at **Al-Sham Private University (ASPU)**. It manages order flow, inventory, and production scheduling using advanced data structures to handle real-world constraints and emergencies.


---
## 🚀 Key Features (Latest Updates)
* **🐧 Cross-Platform Support:** Fully compatible with both **Windows** and **Linux (Arch)** environments using preprocessor directives.
* **📦 Integrated Logistics:** Real-time transition from the Production Floor to the **Shipping Queue** based on priority.
* **🚨 Smart Emergency Recovery:** Advanced line breakdown handling that redistributes orders to the least-congested lines.
* **⏱️ Precision Tracking:** Every `ProductUnit` maintains a timestamped history of events using standard C++ time libraries.

---

## 🏗️ System Architecture & Data Structures
The system is divided into four main subsystems, each optimized for performance:

### 1. Orders Management 
* **Structures:** `std::list` & `std::unordered_map`.
* **Logic:** Optimized for $O(1)$ lookup and $O(1)$ insertion of Urgent/VIP orders into the pending list.

### 2. Production Floor 
* **Structures:** `std::vector<std::priority_queue<Order>>`.
* **Logic:** Multi-line processing where each line operates as a **Max-Heap**, ensuring critical orders are never delayed.

### 3. Warehouse & Inventory 
* **Structures:** `std::deque` & `std::map`.
* **Logic:** Uses a Double-Ended Queue for raw material flow and a map for fast auditing of inventory levels.

### 4. Shipping & Logistics 
* **Structures:** `std::priority_queue`.
* **Logic:** A dedicated global queue that receives finished products and organizes them for dispatch based on client priority.



---


---

## 🛠️ Build & Run (Linux/Arch)
Since the system is now cross-platform, you can compile it easily using `g++`:


cd FactoryManager


g++ -std=c++17 -o FactoryApp *.cpp


./FactoryApp

## Run in terminal:
cd ~/Desktop/University/Projects/Factory-Simulation-System/FactoryManager

g++ -std=c++17 -o FactoryApp *.cpp && ./FactoryApp


---

## 🚨 Emergency Handling |  
One of the core features is the **Line Breakdown Recovery**:
* When a line fails, the system automatically redistributes its `priority_queue` to other active lines while maintaining the priority order of all units.
---

---

## 🚨 Emergency Logic

The system features a Greedy Load Balancer for breakdowns:

Detects line failure.

Extracts all pending orders.

Scans active lines to find the one with the minimum load.

Moves overflow to the Emergency Line if standard lines exceed capacity.

---

## 📁 Project Structure

* **`/FactoryManager`**: Core source code (`.cpp`, `.h`).

* **`.vscode/`**: Environment configurations for Arch Linux & Windows.

* **`docs/`**: Engineering report and UML diagrams.

---
## 🧐 Class Diagram |

<img width="1778" height="1097" alt="107" src="https://github.com/user-attachments/assets/cdd5e82f-17c4-4ba9-a4ea-7a525017c26a" />

---

---

## 🛠️ Technical Implementation Details

* **Conditional Compilation:** Used `#ifdef _WIN32` to ensure the system is portable across different OS environments.

* **Input Validation:** Implemented a robust `checkIfNumber` system with `try-catch` blocks to prevent runtime crashes from invalid user inputs.

* **Resource Management:** Optimized the consumption of materials using `WarehouseManager` before starting any production line.

---

## 👥 Team | 
* **Mahmoud Al-Kowatli** (Project Lead & Linux Integration)
* **GhaithSalloum1**
* **HussamAdinAlKayyal**
* **MajedAnka** 




