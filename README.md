# 🧵 Multithreading in Custom C++ Game Engine

A multithreaded architecture implementation within a basic C++ game engine to improve performance by separating major engine systems like rendering, physics, and logic updates. This project demonstrates core concepts of **parallelism** and **synchronization** critical for high-performance game loops.

---

## 🚀 Objective

To simulate a simple game engine with multiple subsystems (rendering, physics, input) running in **parallel threads**, improving **CPU utilization** and reducing **frame time bottlenecks**.

---

## 🧠 Features

- 🧵 **Threaded Subsystems**: Rendering, physics, and game logic each run on separate threads.
- ⏱️ **Thread Synchronization**: Uses mutexes and condition variables to prevent race conditions.
- 🔁 **Main Loop Coordination**: Threads are coordinated per frame to maintain consistency.
- 📊 **Performance Logging**: Track execution times per system for optimization.

---

## 🛠️ Tech Stack

- **C++17**
- Standard Library Multithreading (`std::thread`, `std::mutex`, `std::condition_variable`)
- Minimal custom engine framework
- Frame timer utilities

---

## 📁 Project Structure

```plaintext
/MultithreadedEngine/
│
├── main.cpp              # Entry point and main loop
├── Renderer.cpp/.h       # Simulated rendering system
├── Physics.cpp/.h        # Physics update simulation
├── GameLogic.cpp/.h      # Game rules and state
├── ThreadManager.hpp     # Manages thread lifecycle and synchronization
├── Timer.hpp             # Utility to measure performance per frame
