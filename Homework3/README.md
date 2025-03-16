# 📌 CSE102 – Computer Programming  
## 📝 Homework #3

### 🖥️ **Topics Covered:** Functions, Selection, and Loops

- **📅 Due Date:** 05/04/2023  
- **📁 Submission Format:**  
  - A student with number **20180000001** should submit a zip file named **20180000001.zip**.
  - The zip file must include the C program file and **screenshots of the valid outputs**.

---

## 📌 **Homework Description**  

You will write a **C program** that contains a `main` function and **several additional functions**.  
This homework provides hands-on experience with:
✅ **Variables, Input/Output, Selections, Loops, and Functions.**

🔹 **Objective:**  
- Develop a **2D puzzle game** where a character must reach a door to escape.
- The game ends when the character reaches the door.
- The **character and door locations are random** for each game.

---

## 🚀 **Part 1: Drawing the Room [30 pts]**
🔹 **Task:**  
- The **room size** is variable (user input).
- **Room size constraints:** `5 ≤ N ≤ 10`
- Each `(x, y)` coordinate represents a location.
- The **character's location** is marked with `'C'`.
- The **door location** is marked with `'D'`.

---

## 🎮 **Part 2: Gameplay [30 pts]**
🔹 **Task:**  
- The character moves **one space** per turn.
- **Allowed Moves:**
  - `'a'` → Left
  - `'d'` → Right
  - `'w'` → Up
  - `'s'` → Down
- **Diagonal moves are NOT allowed.**
- After each move:
  - **Print the updated room.**
  - If the character moves into a wall, **show a warning**.
  - If the character reaches the door, **end the game**.
- **Game Over Output:**  
  - Print a **message** and the **total number of moves made**.

---

## 🔍 **Part 3: Game Status Check [10 pts]**
🔹 **Task:**  
- Implement a function that:
  - **Checks if the game is over.**
  - Returns `1` if **character reaches the door**.
  - Returns `0` otherwise.

---

## 🕹 **Part 4: The Game System [30 pts]**
🔹 **Task:**  
- The game starts **automatically**.
- Display a **menu** with options:
  - `1 → New Game`
  - `2 → Help`
  - `3 → Exit`
- **New Game:**
  - Starts a new game with **random character & door locations**.
- **Help:**
  - Displays game instructions and then **returns to menu**.
- **Exit:**
  - Prints a **goodbye message** and terminates the program.

---

## ⚠️ **Important Rules**
✅ **NO ARRAYS ALLOWED** (0 points if used).  
✅ **Use `if-else` and `switch-case` correctly.**  
✅ **Attach screenshots of gameplay.**  
✅ **Prepare a Makefile (-50 points if missing).**  

---

## 📌 **General Rules & Guidelines**
✅ **Function Naming:** No function prototypes are given. You must name them appropriately.  
✅ **Environment & Compiler:**  
- The program **must** be developed on the given OS version.  
- Use **GCC compiler**. Other OS/compiler issues **won’t be tolerated**.  

✅ **Grading Criteria:**  
- **Any non-working part = 0 points**, even if it's partially correct.  

✅ **Submission Guidelines:**  
- Submit a **zip file** containing:
  - The **C program file**.
  - A **PDF file** with screenshots of valid outputs.

✅ **Questions?**  
📧 Email: [b.koca@gtu.edu.tr](mailto:b.koca@gtu.edu.tr)  
💬 Ask in the **MS Teams homework channel**.

---

🚀 **Good luck!** Happy coding! 🎯  
