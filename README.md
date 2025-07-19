# 🐍 Snake Game – C with ncurses

This is a modular and interactive version of the classic **Snake** game developed in **C** using the **ncurses** library.

> 🧠 This project was part of an academic assignment during my early undergraduate studies. It helped me understand low-level concepts such as pointers, linked lists, terminal graphics, and multi-file architecture in C.

---

## 🎮 Game Features

- ✅ Classic Snake gameplay with grid-based movement
- 🧪 Developed with a fully modular C architecture
- 🍎 Multiple types of apples:
  - Normal apples (increase score and length)
  - Bonus apples (orange) – increase score & speed for a short time
  - Poisoned apples (black) – cause instant death
- ⏸️ Pause/resume using **Enter** key
- 🎯 Score system and collision logic
- 🔄 Real-time gameplay via **ncurses**
- 📦 Makefile for easy build & compilation

---

## 🧱 Project Structure

The codebase is structured into multiple C files, each with its corresponding header file for better separation of logic.

- `main.c` → Contains the main game loop and initialization
- `monde.c/.h` → Functions to initialize the world, track score, grid size, etc.
- `serpent.c/.h` → Defines the snake structure, movement logic
- `pomme.c/.h` → Generates and places apples on the grid
- `case.c/.h` → Grid cell logic (coordinates, collisions)
- `graphique.c/.h` → Drawing the game using ncurses
- `Makefile` → Script to compile everything with `make`


---

## 🧠 Key Concepts Implemented

- ✅ **Singly linked lists** for representing the snake and apple lists
- ✅ **Dynamic memory management**
- ✅ **Modular C architecture** using `.c/.h` separation
- ✅ **Collision detection** and grid logic
- ✅ **Random generation** for apple placement using `rand()`
- ✅ **Custom Makefile** to build the entire project

---

## ▶️ How to Compile & Run

### 🧰 Requirements

- GCC compiler
- `ncurses` library (Linux/macOS)

### 🔧 Build with Makefile

```bash
make         # Builds all modules
make prog    # Compiles and links the game executable
```

## 🎮 Controls

| Key      | Action                         |
|----------|--------------------------------|
| Q/Z/S/D  | Move snake (left/up/down/right)|
| Enter    | Pause / Resume the game        |
| CTRL+C   | Quit the game (terminal kill)  |
