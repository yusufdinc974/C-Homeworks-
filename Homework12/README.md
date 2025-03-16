# 📌 CSE102 – Computer Programming  
## 📝 Homework #12

### 🖥️ **Topics Covered:** Linked Lists, Dynamic Memory, File Serialization

- **📅 Due Date:** 27/06/2023  
- **📁 Submission Format:**  
  - A student with number **20220000001** should submit a zip file named **20220000001.zip**.
  - The zip file must include the C program file, **a YouTube video link**, and **screenshots of the valid outputs**.

---

## 📌 **Homework Description**  

You will develop a **C program** that:
✅ **Generates and fills a linked list with different types of assets.**  
✅ **Serializes the linked list and writes it to a binary file.**  
✅ **Deserializes the binary file and reconstructs the linked list.**  

🚨 **Important!**
- **Use a void pointer (`void* data`) to store different asset types.**
- **The order of assets must not be apparent in the binary file.**

---

## 📂 **Data Structures**
### 📌 **Structs Used**
1. **`Node`** (Represents each element in the linked list)
   ```c
   typedef struct Node {
       void* data;
       struct Node* next;
   } Node;
   ```
2. **Four different asset types**
   ```c
   typedef struct {
       char type[20];
       int ivals[1];
       double svals[1];
   } Asset1;

   typedef struct {
       char type[20];
       double svals[2];
       int ivals[2];
   } Asset2;

   typedef struct {
       char type[20];
       char string1[50];
       char string2[50];
   } Asset3;

   typedef struct {
       char type[20];
       double value1;
       float value2;
       double value3;
   } Asset4;
   ```

---

## 🚀 **Program Implementation**
### **🔹 Part 1: Generate and Fill Linked List [30 pts]**
✅ Implement **`fillLinkedList(struct Node** head)`**  
- Generates **10 to 20 random assets** (random count each call).  
- Stores assets **in a linked list** with `void* data`.  
- The list should **randomly contain any mix** of `Asset1`, `Asset2`, `Asset3`, and `Asset4`.  

---

### **🔹 Part 2: Serialize Linked List to Binary File [30 pts]**
✅ Implement **`serializeLinkedList(struct Node* head)`**  
- Saves the linked list to **`linkedlist.bin`**.  
- **Stores asset type** and its **data**.  
- **No ordering hints in the binary file!**  

---

### **🔹 Part 3: Deserialize Binary File & Reconstruct Linked List [40 pts]**
✅ Implement **`deserializeLinkedList(struct Node** head)`**  
- Reads **`linkedlist.bin`** and reconstructs the **linked list**.  
- **Detects asset types** from the file and allocates memory dynamically.  
- The new list should be **identical** to the original.  

---

## 📌 **Demo Video Requirement**
📽 **Record a YouTube demo (max 5 minutes) showcasing:**
- 🎲 **Random asset generation.**  
- 💾 **Binary file creation (`linkedlist.bin`).**  
- 🔄 **Deserialization & linked list reconstruction.**  

📌 **Submit the YouTube video link inside a text file (`video_link.txt`).**  

---

## ⚠️ **Important Rules**
✅ **Use `void* data` to store assets dynamically.**  
✅ **Ensure assets appear in a random order in the binary file.**  
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
