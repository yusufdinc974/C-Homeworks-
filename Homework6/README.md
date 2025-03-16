# 📌 CSE102 – Computer Programming  
## 📝 Homework #7

### 🖥️ **Topics Covered:** String Manipulation, File Handling, Histograms, Word Dissimilarity

- **📅 Due Date:** 10/05/2023  23:59  
- **📁 Submission Format:**  
  - A student with number **20180000001** should submit a zip file named **20180000001.zip**.
  - The zip file must include the C program file and **screenshots of the valid outputs**.

---

## 📌 **Homework Description**  

You will develop a **C program** that manipulates strings and processes text from files.  
The program will:
✅ **Read input text from a file.**  
✅ **Ignore specified words.**  
✅ **Compare words to a dictionary with vector-based representations.**  
✅ **Compute word frequency and dissimilarity.**  
✅ **Display a histogram of word occurrences.**  

---

## 📂 **Files Used**
- `input.txt` → Contains a long English text (e.g., a novel, article).  
- `ignore.txt` → Contains a set of words to ignore from `input.txt`.  
- `dictionary.txt` → Contains numeric vector representations for each word.

### 📌 **Dictionary File Format**
```
num_words=5, vector_size=3  
student -0.2 0.5 1.0  
course  -1.0 0.2 0.7  
car     -0.1 0.9 1.2  
bus     -0.2 0.8 1.1  
instructor -0.3 0.6 0.9  
```
- `num_words` → Total words in dictionary.  
- `vector_size` → Number of floating-point values per word.  
- Words are represented as **vectors** (e.g., `car = [-0.1, 0.9, 1.2]`).  

---

## 🚀 **Program Functionality**
### **🔹 User Input:**
- The user enters **one or more words**.
- **Single word case:**
  - If found → Print the **number of occurrences** in `input.txt`.
  - If **not found** → Find the **closest word** in `dictionary.txt` and print its frequency.
- **Multiple word case:**
  - Display a **histogram** showing the **word frequencies**.

### **🔹 Word Frequency & Histogram:**
- `*` → Exact word matches.
- `+` → Closest word matches.

📌 **Example Outputs:**
```
Enter word(s): car  
"car" appears in "input.txt" 2 times.  

Enter word(s): truck  
"truck" doesn’t appear in "input.txt" but "bus" appears 2 times.  

Enter word(s): car student bus  
"car"      **********  
"student"  *****  
"bus"      ++  
```
- If words exceed **20 occurrences**, apply **scaling** (e.g., `Scale: 2`).  

---

## 🔧 **Functions to Implement**
🔹 `int main(int argc, char *argv[])`  
  - Handles user input and calls the necessary functions.

🔹 `int read_dict(const char * file_name, char dict[][MAX_WORD_SIZE])`  
  - Reads `dictionary.txt` and stores words.
  - Returns the **number of words read**.

🔹 `int read_text(const char * text_file, const char * ignore_file, char words[][MAX_WORD_SIZE])`  
  - Reads `input.txt` and removes words from `ignore.txt`.

🔹 `double dissimilarity(char * w1, char * w2, char dict[][MAX_WORD_SIZE], float threshold, int *)`  
  - Computes **word dissimilarity** using **vector distance**.

🔹 `int histogram(const char words[][MAX_WORD_SIZE], const int occurrences[], const char hist[][MAX_WORD_SIZE+5+20])`  
  - Generates a **histogram** of word occurrences.

---

## ⚠️ **Important Rules**
✅ **Do NOT use any `string.h` functions (except `strcmp`).**  
✅ **Develop on the specified OS version & compile using GCC.**  
✅ **Attach screenshots of the outputs.**  
✅ **Prepare a Makefile (-50 points if missing).**  

---

## 📌 **Submission Guidelines**
- Submit a **zip file** containing:
  - The **C program file**.
  - A **PDF file** with screenshots of valid outputs.

✅ **Questions?**  
📧 Email: [zbilici@gtu.edu.tr](mailto:zbilici@gtu.edu.tr)  
💬 Ask in the **MS Teams homework channel**.

---

🚀 **Good luck!** Happy coding! 🎯  
