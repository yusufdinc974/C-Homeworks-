# 📌 CSE102 – Computer Programming  
 ## 📝 Homework #10
 
 ### 🖥️ **Topics Covered:** Linked Lists, File Handling, Library Management System
 
 ---
 
 ## 📌 **Homework Description**  
 
 You will develop a **C program** that simulates a **Library Book Management System** using **linked lists**.  
 The system should support:
 ✅ **Adding, deleting, updating books**.  
 ✅ **Filtering, sorting, and searching books**.  
 ✅ **Borrowing and returning books**.  
 ✅ **Persisting data using text files**.  
 
 ---
 
 ## 📂 **Data Structures**
 ### 📌 **Structs Used**
 1. **`Book`** (Represents a book in the system)
    ```c
    struct Book {
        char isbn[20];
        char title[100];
        char author[100];
        int publicationYear;
        int isBorrowed; // 0 = available, 1 = borrowed
        struct Book *next;
    };
    ```
 2. **`Student`** (Represents a student in the system)
    ```c
    struct Student {
        char name[100];
        int studentID;
        struct Book *borrowedBooks;
        struct Student *next;
    };
    ```
 
 ---
 
 ## 🚀 **Library Management Functions**
 ### **🔹 Student's Borrowed Books List [10 pts]**
 - **Displays books borrowed by a student**.
 - Searches for the student **by ID**.
 
 ### **🔹 Add Book [10 pts]**
 - Adds a new book using **FIFO or LIFO**.
 - Function:
   ```c
   void addBook(char* isbn, char* title, char* author, int publicationYear, int method);
   ```
   - `method = 0` → FIFO  
   - `method = 1` → LIFO  
 
 ### **🔹 Delete Book [10 pts]**
 - Removes a book **by ISBN**.
 - Function:
   ```c
   void deleteBook(char* isbn);
   ```
 
 ### **🔹 Update Book [10 pts]**
 - Updates **title, author, or publication year** (ISBN cannot be updated).
 - Function:
   ```c
   void updateBook(char* isbn, char* feature, char* value);
   ```
 
 ### **🔹 Filter & Sort Books [20 pts]**
 - Filters by **author** or **publication year**.
 - Sorts by **title, author, or publication year**.
 - Function:
   ```c
   void filterAndSortBooks(int filterChoice, char* filter, int sortChoice);
   ```
   - `filterChoice = 0` → Filter by **author**  
   - `filterChoice = 1` → Filter by **publication year**  
   - `sortChoice = 0` → Sort by **title**  
   - `sortChoice = 1` → Sort by **author**  
   - `sortChoice = 2` → Sort by **publication year**  
 
 ### **🔹 Reverse Book List [10 pts]**
 - Reverses the order of books **by ISBN**.
 - Function:
   ```c
   void reverseBookList();
   ```
 
 ### **🔹 Search Books [10 pts]**
 - Searches **by ISBN, author, or title**.
 - Function:
   ```c
   void searchBooks(int searchChoice, char* searchValue);
   ```
   - `searchChoice = 0` → Search by **ISBN**  
   - `searchChoice = 1` → Search by **Author**  
   - `searchChoice = 2` → Search by **Title**  
 
 ### **🔹 Borrow & Return Books [20 pts]**
 - Allows students to **borrow and return books**.
 - Functions:
   ```c
   void borrowBook(char* isbn);
   void returnBook(char* isbn);
   ```
 
 ---
 
 ## ⚠️ **Important Rules**
 ✅ **Use linked lists for all operations** (0 pts if other data structures are used).  
 ✅ **Persist data in a text file** (update file after every operation).  
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
