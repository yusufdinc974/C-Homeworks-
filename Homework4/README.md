# 📌 CSE102 – Computer Programming  
## 📝 Homework #4

### 🖥️ **Topics Covered:** Functions, Selection, Loops, File Handling

---

## 📌 **Part 1: Restaurant Ordering System [60 pts]**
🔹 **Task:**  
- Create a **menu system** for ordering dishes.
- **Calculate total prices, apply discounts, and VAT.**
- **Save all data to a text file**.

### 📌 **Menu Requirements**
- The menu should contain **at least 10 items**.
- Prices should include **pennies**.
- **Read & display the menu from a file (without using strings).**

### 📌 **Program Stages**
1️⃣ **Display the menu.**  
2️⃣ **User selects a dish and quantity.**  
3️⃣ **Total price is calculated, including VAT (18%).**  
4️⃣ **Discounts applied:**
   - **Students get a 12.5% discount.**
   - **Orders over 150 TL receive an additional 10% discount.**
5️⃣ **Receipt is saved in a text file.**
6️⃣ **Print the receipt in the console.**
7️⃣ **Exit the menu when user enters `0`.**
8️⃣ **Validate all user inputs!**

🔹 **Receipt Format Example:**  
```
20180000001         27.03.2023/13:30  
------------------------------------  
 Product       Price (TL)  
-----------------------------------  
 2* Lahmacun    43.00  
 Kola          15.00  
 Sütlaç        32.50  
 Total:        90.50  
 Student discount:   -11.31  
-----------------------------------  
 Price:        79.19  
 Price + VAT:  93.44  
```

---

## ✂ **Part 2: Rock-Paper-Scissors Game [40 pts]**
🔹 **Task:**  
- User chooses: **Rock (1), Paper (2), Scissors (3)**.
- The **computer makes a random choice**.
- Compare results:
  - **Win, Lose, or Tie**.
- Ask the user if they want to play again (`Y/N`).
- **Repeat the game in a loop.**

🔹 **Example Output:**  
```
Please make a choice!  
1: Rock, 2: Paper, 3: Scissors  
1  

You chose Rock. I chose Rock. It's a tie!  
Do you want to play again? (Y/N): Y  

Please make a choice!  
1: Rock, 2: Paper, 3: Scissors  
3  

You chose Scissors. I chose Paper. You won!  
Do you want to play again? (Y/N): N  
```

---

## ⚠️ **Important Rules**
✅ **NO ARRAYS ALLOWED** (-50 points if used).  
✅ **Use `if-else` and `switch-case` correctly.**  
✅ **Attach screenshots of the outputs.**  
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


---

🚀 **Good luck!** Happy coding! 🎯  
