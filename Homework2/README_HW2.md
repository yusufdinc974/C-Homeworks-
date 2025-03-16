# 📌 CSE102 – Computer Programming  
## 📝 Homework #2

### 🖥️ **Topics Covered:** Functions and Selection

- **📅 Due Date:** 29/03/2023  
- **📁 Submission Format:**  
  - A student with number **20180000001** should submit a zip file named **20180000001.zip**.
  - The zip file must include the C program file and **screenshots of the valid outputs**.

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

## 🚀 **Part 1: Leap Year Problem [30pts]**
🔹 **Task:**  
- A **leap year** has **366 days** (instead of 365).
- It occurs **every four years** to sync the calendar with Earth's orbit.
- Examples of leap years: **2020, 2016, 2012, 2008, 2004**.

🔹 **Implementation:**
- Prompt the user to enter a year.
- Use an **if statement** to check if it's a **leap year**.
- Print whether the year is a leap year or not.

---

## ➕ **Part 2: Enhanced Calculator [40pts]**
🔹 **Task:**  
- Prompt the user to **enter two numbers** and an **operator** (`+`, `-`, `*`, `/`, `!`, `^`, `%`).
- Before entering numbers, the user must **choose the output format**:
  - `"S"` → **Scientific Format**
  - `"I"` → **Integer Format**

### 📌 **Scientific Format ("S")**
- User enters **two additional integers**:  
  - `m`: Total digits of the result  
  - `n`: Digits after the decimal point (**Warn if `n > m`**).
- Expected output examples:
  ```
  m=8, n=4, Result: 12340000
  Expected Output: 0000.1234e8 (1234×10⁴)
  ```
  ```
  m=7, n=1, Result: 7.35
  Expected Output: 000073.5e-1 (73.5×10⁻¹)
  ```

### 📌 **Integer Format ("I")**
- The result is **displayed as an integer**.

🔹 **Operations Supported:**
- `!` → **Factorial** (e.g., `5! = 120`)
- `^` → **Exponential** (e.g., `3^2 = 9`)
- `%` → **Modulo** (e.g., `7%3 = 1`)

🔹 **Implementation:**
- Use a **switch statement** to determine the operation.
- Print the result in the chosen format.
- If the user enters an **invalid operator**, print an **error message**.

---

## 🎓 **Part 3: Grade Calculator [30pts]**
🔹 **Task:**  
- Prompt the user to enter:
  - **Three exam grades** (out of 100)
  - **Two assignment grades** (out of 100)
- Calculate the **Final Grade** using the formula:
  ```
  Final Grade = (Exam1 + Exam2 + Exam3) / 3 * 0.6 + (Assignment1 + Assignment2) / 2 * 0.4
  ```
- **Check if the student passed:**
  - If `Final Grade ≥ 60` → **"Passed"**
  - If `Final Grade < 60` → **"Failed"**

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

✅ **Makefile Requirement:**  
- **Mandatory!** (-50 points if missing).

✅ **Questions?**  
📧 Email: [barisozcan@gtu.edu.tr](mailto:barisozcan@gtu.edu.tr)  
💬 Ask in the **MS Teams homework channel**.

---

🚀 **Good luck!** Happy coding! 🎯  
