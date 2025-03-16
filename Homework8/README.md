# 📌 CSE102 – Computer Programming  
## 📝 Homework #8

### 🖥️ **Topics Covered:** Structs, File Handling, Recursion, 8-Puzzle Game

---

## 📌 **Homework Description**  

You will develop a **C program** that simulates the **8-Puzzle Game** using a **struct-based board representation**.  
The program will:
✅ **Generate and manipulate a random 8-puzzle board.**  
✅ **Allow the user to play manually or let the PC solve the puzzle.**  
✅ **Keep track of the best score.**  
✅ **Save puzzle states to a text file after each move.**  

---

## 🎮 **Game Modes**
When the program starts, a **menu** is displayed with **four options**:
```
1. Play game as a user  
2. Finish the game with PC  
3. Show the best score  
4. Exit  
```

### **🔹 Option 1: Play Game as a User**
- The program **generates a random 8-puzzle board**.
- The **initial state** is saved to a **text file**.
- The user **enters a number and direction** to move (e.g., `"2-R"` moves 2 **right**).
- Each move updates the **puzzle board** and saves it to the **text file**.
- The program **checks for illegal moves** and warns the user.
- Once solved:
  - **Display a congratulatory message**.
  - **Show total moves & score** (`Score = 1000 - (10 × moves)`).
  - **If it's the best score, update `best_score.txt`.**
- The program **returns to the main menu**.

---

### **🔹 Option 2: Finish Game with PC**
- The PC **solves the puzzle automatically**.
- Implement a **recursive function** `auto_finish()`:
  - The function makes **random legal moves**.
  - After each move, **update & save the puzzle board**.
- When solved:
  - **Display total number of moves**.
  - **Return to the main menu**.

---

### **🔹 Option 3: Show the Best Score**
- Read and **display the best score** from `best_score.txt`.

---

### **🔹 Option 4: Exit**
- **Terminate the program gracefully**.

---

## 📌 **Files Used**
- `game_state.txt` → Stores **puzzle board states**.
- `best_score.txt` → Stores **the best score**.

---

## ⚠️ **Important Rules**
✅ **Function Naming:** No function prototypes are given.  
✅ **Use `structs` for representing the puzzle board.**  
✅ **Use recursion for the PC auto-solver.**  
✅ **Attach screenshots of the outputs.**  
✅ **Prepare a Makefile (-50 points if missing).**  

---

## 📌 **Submission Guidelines**
- Submit a **zip file** containing:
  - The **C program file**.
  - A **PDF file** with screenshots of valid outputs.

---

🚀 **Good luck!** Happy coding! 🎯  
