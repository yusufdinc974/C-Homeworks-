# 📌 CSE102 – Computer Programming  
## 📝 Homework #5

### 🖥️ **Topics Covered:** Functions, Selection, Loops, Pointers, Enumerations

---

## 📌 **Homework Description**  

You will write a **C program** that contains a `main` function and **three additional functions**.  
The program will execute the functions in the following order:  
✅ `part1() → part2() → part3()`

Each function will:
- Receive **input** from the user.
- Print the **output** to the console.
- **Follow the exact output format** to avoid penalties.

---

## 🔤 **Part 1: Letter Frequency Problem [30 pts]**
🔹 **Task:**  
- Read a **text file** and **count the occurrences** of each letter (case-insensitive).
- Use **loops** and **pointers** for processing.
- Store the counts in an **array**.
- Implement a function to **handle letter case conversion**.
- Display the results in a **tabular format**.

---

## 🎨 **Part 2: Mixing Colors [30 pts]**
🔹 **Task:**  
- Define an **enumeration** `Color` with values:
  - **RED, GREEN, BLUE, YELLOW, ORANGE**.
- Implement a function `colorMixer` that:
  - Takes **two Color values** and a **function pointer**.
  - Returns a **new mixed Color** using **Euclidean distance**.

🔹 **Color Representations (as Vectors):**
```
RED     = [1, 0, 0]
GREEN   = [0, 1, 0]
BLUE    = [0, 0, 1]
YELLOW  = [0.5, 0.5, 0]
ORANGE  = [0.5, 0.4, 0.2]
```

🔹 **Mixing Formula:**
For two colors with vectors `[x1, x2, x3]` and `[y1, y2, y3]`,  
the resulting mixed color is calculated as:
```
[(x1+y1)/2, (x2+y2)/2, (x3+y3)/2]
```
Find the **closest color** based on **Euclidean distance**.

---

## ❌⭕ **Part 3: Tic-Tac-Toe [40 pts]**
🔹 **Task:**  
- Create a **two-player tic-tac-toe game**.
- Implement:
  ✅ **Game board display**  
  ✅ **User input validation**  
  ✅ **Turn-based gameplay**  
  ✅ **Winner check after each move**  
  ✅ **Game over check (Win, Lose, Draw)**  
- Allow players to **restart or exit** after each round.

---

## ⚠️ **Important Rules**
✅ **Function Naming:** No function prototypes are given.  
✅ **Use `if-else`, `switch-case`, and pointers correctly.**  
✅ **Develop on the specified OS version & compile using GCC.**  
✅ **Attach screenshots of the outputs.**  
✅ **Prepare a Makefile (-50 points if missing).**  

---

## 📌 **Submission Guidelines**
- Submit a **zip file** containing:
  - The **C program file**.
  - A **PDF file** with screenshots of valid outputs.

---

🚀 **Good luck!** Happy coding! 🎯  
