# 📌 CSE102 – Computer Programming  
## 📝 Homework #9

### 🖥️ **Topics Covered:** Dynamic Arrays, Structs, Snake Game Implementation

- **📅 Due Date:** 05/06/2023  
- **📁 Submission Format:**  
  - A student with number **20220000001** should submit a zip file named **20220000001.zip**.
  - The zip file must include the C program file, **a YouTube video link**, and **screenshots of the valid outputs**.

---

## 📌 **Homework Description**  

You will develop a **C program** that simulates the **Snake Game** using **dynamic arrays**.  
The game takes place on a **10 × 10 × m 3D board**, where the snake moves and interacts with:
✅ **Baits** to grow longer.  
✅ **Obstacles** that may end the game.  
✅ **Walls** that can cause a collision.  

🚨 **Game Ends When:**
1️⃣ The snake **hits its own body**.  
2️⃣ The snake **collides with a wall**.  
3️⃣ The snake **encounters an obstacle taller than itself**.  

---

## 📂 **Game Components**
### 📌 **Structs Used**
1. **`Point`** (Represents each block of the snake)
   ```c
   struct Point {
       int row;
       int col;
   };
   ```
2. **`Block`** (Represents board cells)
   ```c
   struct Block {
       char type; // 'o' = Obstacle, 'b' = Bait, 'e' = Empty
       int value; // Height of obstacle (0 for empty & bait)
   };
   ```

---

## 🚀 **Game Implementation**
### **🔹 Part 1: Initialize the Board [30 pts]**
- Implement **`init_board()`** to:
  ✅ Create a **3D dynamic array of Blocks**.  
  ✅ Set **all cells to empty** (`'e'`).  
  ✅ **Randomly place** 1 **bait** (`'b'`) and 1 **obstacle** (`'o'`).  
  ✅ **Avoid placing obstacles in the starting position (top-left).**  

---

### **🔹 Part 2: Draw the Board [20 pts]**
- Implement **`draw_board()`** to print the board:
  ✅ Use `-` and `|` for borders.  
  ✅ Represent cells as follows:  
    - 🟩 Empty → **Nothing**  
    - 🐍 Snake's **Body** → `'X'`  
    - 🐍 Snake's **Head** → `'O'`  
    - 🍎 Bait → `'.'`  
    - 🧱 Obstacle → **Number of blocks stacked**  

📌 **Example Board:**
```
------------
|O   .   X |
|    3     |
------------
```

---

### **🔹 Part 3: Gameplay [40 pts]**
🚀 Implement **`play()`, `move()`, `check_status()`, and `update()`** to handle:
1️⃣ **`play()`**  
   - Initializes the **snake** (length = `1`) at **(0,0)**.  
   - Prompts **user input (`w` `a` `s` `d`) for movement**.  
   - Calls **`check_status()`** after every move.  
   - If the game is not over → Calls **`update()`**.

2️⃣ **`move()`**  
   - Reads **user input** and moves the snake **accordingly**.  
   - Ignores moves that would make the snake turn into itself.  

3️⃣ **`check_status()`**  
   - **Returns `1` (Game Over) if:**  
     ✅ Snake hits its **own body**.  
     ✅ Snake **collides with a wall**.  
     ✅ Snake encounters an **obstacle taller than itself**.  

4️⃣ **`update()`**  
   - Updates **snake position**.  
   - **Increases snake length** if it eats a bait.  
   - **Handles obstacles:**  
     - Snake **destroys** obstacles shorter than itself.  
     - Adds **new obstacles** every **5 moves** (max 3 at a time).  

---

### **🔹 Part 4: Main Function [10 pts]**
- Implement **`main()`** to:
  ✅ Call `init_board()`.  
  ✅ Start the game with `play()`.  
  ✅ **No menu required** – game starts immediately.  

---

## 📌 **Demo Video Requirement**
📽 **Record a 5-minute max YouTube demo showcasing:**
- 🟢 **Eating bait & growing.**  
- 🔴 **Colliding with walls & ending the game.**  
- 🟠 **Encountering obstacles & destroying them (if possible).**  
- 🛑 **Hitting its own body & losing.**  

📌 **Submit the YouTube video link inside a text file (`video_link.txt`).**  

---

## ⚠️ **Important Rules**
✅ **ONLY use dynamic arrays** (0 pts if other arrays are used).  
✅ **Prepare a Makefile (-50 pts if missing).**  
✅ **Ensure GCC compatibility.**  
✅ **Attach screenshots of outputs.**  

---

## 📌 **Submission Guidelines**
- Submit a **zip file** containing:
  - The **C program file**.
  - **A text file with the YouTube demo link**.
  - A **PDF file** with screenshots of valid outputs.

✅ **Questions?**  
📧 Email: [b.koca@gtu.edu.tr](mailto:b.koca@gtu.edu.tr)  
💬 Ask in the **MS Teams homework channel**.

---

🚀 **Good luck!** Happy coding! 🎯  
