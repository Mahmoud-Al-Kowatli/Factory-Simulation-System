# 🏭 Factory Simulation System - ASPU Project 2026

## 📝 Overview |  
This project is a comprehensive simulation of a multi-line factory production system, developed for the **Algorithms and Data Structures** course at **Al-Sham Private University (ASPU)**. It manages order flow, inventory, and production scheduling using advanced data structures to handle real-world constraints and emergencies.


---

## 🏗️ System Architecture |  
The system is divided into four main subsystems, each optimized for performance:

### 1. Orders Management 
* **Data Structures:** `std::list` & `std::unordered_map`.
* **Logic:** Orders are stored in a list for flexible insertion (VIP/Urgent orders). The hash map provides $O(1)$ access for instant searching and status updates.

### 2. Production Floor 
* **Data Structures:** `std::vector<std::priority_queue<Order>>`.
* **Logic:** Multiple production lines are managed. Each line uses a **Priority Queue** to ensure high-priority orders (e.g., medical or urgent requests) are processed first.

### 3. Warehouse & Inventory 
* **Data Structures:** `std::deque` & `std::map`.
* **Logic:** Raw materials are managed using a Double-Ended Queue for efficient $O(1)$ supply flow. Inventory counts are tracked for fast auditing.

### 4. Tracking & History 
* **Data Structures:** `std::vector<Event>` within each `ProductUnit`.
* **Logic:** Every unit produced carries its own history, recording every stage, delay, or line breakdown it encountered.

---

## 🚨 Emergency Handling |  
One of the core features is the **Line Breakdown Recovery**:
* When a line fails, the system automatically redistributes its `priority_queue` to other active lines while maintaining the priority order of all units.

---

## 📁 Project Structure | 
* `/src`: Source code files (.cpp, .h).
* `/docs`: Engineering report, UML diagrams, and documentation.
* `/data`: Initial seed data for the factory state.

---
## 🧐 **Class Diagram**

<img width="1778" height="1097" alt="105" src="https://github.com/user-attachments/assets/98d5d882-77d0-4de7-8d3b-f467c41d4ffa" />

---

## 👥 Team | فريق العمل
* **Mahmoud Al-Kowatli** (Project Lead)
* **GhaithSalloum1**
* **HussamAdinAlKayyal**
* [Team Member 4]




