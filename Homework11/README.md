# 📌 CSE102 – Computer Programming  
## 📝 Homework #11

### 🖥️ **Topics Covered:** Structs, File Handling, Family Tree Management

---

## 📌 **Homework Description**  

You will develop a **C program** that **creates and manages Family Trees** using **structs**.  
The system will support:
✅ **Adding, removing, and loading family trees from files**.  
✅ **Printing family details and finding relatives**.  
✅ **Updating the tree in a corresponding text file**.  

---

## 📂 **Data Structures**
### 📌 **Struct Used**
```c
struct Person {
    char name[100];
    int age;
    struct Person* mother;
    struct Person* father;
    struct Person* next; // For linked list traversal
};
```
- **Each person (node) contains**:
  - `name` → Unique name identifier.
  - `age` → Age of the person.
  - `mother` & `father` → Pointers to parents.
  - `next` → Pointer to the next person in the tree.

---

## 🚀 **Family Tree System Implementation**
### **🔹 Part 1: Creating & Managing Family Trees [40 pts]**
✅ **Add & Remove Family Trees**  
- Each family tree is stored in a text file (`familyX.txt`).  
- Functionality:
  - **Add a tree** → User inputs a name, creating a new text file.
  - **Remove a tree** → User deletes a selected family tree file.

✅ **Add & Remove People**  
- Adding a person:
  - **Input Name & Age**.
  - **Specify parents** (must exist in tree).
  - **If root (first ancestor), parents are NULL**.
- Removing a person:
  - **Warn if they have children** (deleting removes all descendants).

✅ **Update Tree File on Every Change**  

---

### **🔹 Part 2: Loading & Querying Family Trees [60 pts]**
✅ **Load Family Tree from File**  
- Select a `.txt` file and load family members into memory.

✅ **Modify Family Tree**  
- Users can **add or remove people** after loading the tree.

✅ **Print Nuclear Family**  
- Displays **Father, Mother, Spouse, and Children**.

✅ **Find Relatives**  
- User inputs a name and chooses a relation type:
  - **Siblings**
  - **Parents**
  - **Grandparents**
  - **Cousins**
  - **Spouse**
- **Output relatives based on relationship type.**

✅ **Save Updates to File**  
- Any modifications **overwrite the original tree file**.

📌 **Each person’s name must be unique to avoid conflicts.**

---

## ⚠️ **Important Rules**
✅ **Use structs and pointers to manage the tree.**  
✅ **Persist data in text files (update after every change).**  
✅ **Prepare a Makefile (-50 pts if missing).**  
✅ **Ensure GCC compatibility.**  
✅ **Attach screenshots of outputs.**  

---

## 📌 **Submission Guidelines**
- Submit a **zip file** containing:
  - The **C program file**.
  - A **PDF file** with screenshots of valid outputs.

---

🚀 **Good luck!** Happy coding! 🎯  
