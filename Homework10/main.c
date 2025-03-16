#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct book{

    char ISBN_number[15];
    char title[40];
    char author[30];
    char publication_year[5];
    char reserved_status[1];
    struct book* next;

}book;

typedef struct student{
    
    char name[30];
    char ID[6];
    char borrowed_books[20][40];
    struct student* next;

}student;

void students_borrowed_book_list(char *ID, student* iter_student);
book* addBook(book* iter_book, FILE *book_file, char* isbn, char* title, char* author, char* publicationYear, int method);
void deleteBook(book* root_book, FILE *book_file, char* isbn);
void searchBooks(book* root_book, int searchChoice, char* searchValue);
void updateBook(book* root_book, FILE* book_file, char* isbn, char* feature, char* value);
void borrow_and_return(book* root_book, char* isbn, int choice);

int main(){

    int i=1, a=0, choice, method;
    char buffer = 'a';
    char student_id[6];
    char isbn_number[15], title[40], author[30], public_year[5], search[40], feature[20], value[40];

    book * root_book;
    book * iter_book;
    
    student * root_student;
    student * iter_student;
    
    root_book = (book *)malloc(sizeof(book));
    iter_book = root_book;
    iter_book->next = NULL;
    
    root_student = (student *)malloc(sizeof(student));
    iter_student = root_student;
    iter_student->next = NULL;

    /* Opening student.txt */
    FILE *student_file;
    student_file = fopen("student.txt","r");

    /* Opening book.txt*/
    FILE *book_file;
    book_file = fopen("book.txt","r");

    int j;

    // Getting students information from txt and inserting into linked list 
    
    char str[110];
    char * token;

    while(feof(student_file) == 0){    
        
        fgets(str, 110, student_file);
        str[strlen(str) - 1] = '\0'; // Remove the newline character from the string

        token = strtok(str, ",");
        strcpy(iter_student->name, token);

        token = strtok(NULL, ",");
        strcpy(iter_student->ID, token);

        a = 0;

        while (token != NULL) {
            
            token = strtok(NULL, ",");
            
            if (token != NULL) {
            
                strcpy(iter_student->borrowed_books[a], token);
            
            
                a++;
            
            }
        }

        iter_student->borrowed_books[a][0] = '\0';

        iter_student->next = (student *)malloc(sizeof(student));
        iter_student = iter_student->next;
        iter_student->next = NULL;

    }
          

    i = 1;

    // Getting books information from txt and inserting into linked list 
    while(feof(book_file) == 0){    
        
        fgets(str, 110, book_file);
        str[strlen(str) - 1] = '\0'; // Remove the newline character from the string

        token = strtok(str, ",");
        strcpy(iter_book->ISBN_number, token);

        token = strtok(NULL, ",");
        strcpy(iter_book->title, token);

        token = strtok(NULL, ",");
        strcpy(iter_book->author, token);

        token = strtok(NULL, ",");
        strcpy(iter_book->publication_year, token);

        strcpy(iter_book->reserved_status, "N");

        iter_book->next = (book *)malloc(sizeof(book));
        iter_book = iter_book->next;
        iter_book->next = NULL;

    }
    
    fclose(student_file);
    fclose(book_file);


    printf("----------------------------------------\n");
    printf("1. Display Student's Borrowed Books List\n");
    printf("2. Add Book\n");
    printf("3. Delete Book\n");
    printf("4. Update Book\n");
    printf("5. Filter and Sort Books\n");
    printf("6. Reverse Book List\n");
    printf("7. Search Books\n");
    printf("8. Borrow and Return Books\n");
    printf("----------------------------------------\n");
    printf("Enter an option: ");
    scanf("%d",&choice);

    switch (choice){
    
    case 1:
        printf("Enter the student ID: ");
        scanf("%s",student_id);
        printf("\n");
        students_borrowed_book_list(student_id,root_student);
    break;
    
    case 2:

        
        printf("Please enter ISBN number: ");
        scanf("%s",isbn_number);
        //printf("\n");
        
        printf("Please enter Title: ");
        scanf(" %[^\n]",title);
        //printf("\n");

        printf("Please enter Author: ");
        scanf(" %[^\n]",author);
        //printf("\n");

        printf("Please enter Publication Year: ");
        scanf("%s",public_year);
        //printf("\n");

        printf("Please enter Method (0,1): ");
        scanf(" %d",&method);
        //printf("\n");

        root_book = addBook(root_book, book_file, isbn_number, title, author, public_year, method);
    
        printf("Succesfull..!\n");

    break;
    
    case 3:
    printf("Enter the ISBN of the book you want to delete: ");
    scanf("%s",isbn_number);
    deleteBook(root_book,book_file,isbn_number);
    break;

    case 4:
    printf("Enter the ISBN of the book you want to update: ");
    scanf("%s",isbn_number);
    printf("enter the feature you want to update (title, author, or publication year): ");
    scanf(" %[^\n]",feature);
    printf("Enter the value you wanted to change with: ");
    scanf(" %[^\n]",value);
    updateBook(root_book,book_file,isbn_number,feature,value);
    break;

    case 7:
    printf("Please enter the search type (s. 0 for searching by ISBN number, 1 for searching by author, 2 for searching by title): ");
    scanf("%d",&choice);
    printf("Please enter search: ");
    scanf(" %[^\n]",search);
    searchBooks(root_book,choice,search);
    break;

    case 8:
    printf("Enter the ISBN of the book you want to borrow or return: ");
    scanf("%s",isbn_number);
    printf("If you want to borrow enter 1, if you want to return enter 0: ");
    scanf("%d",&choice);
    borrow_and_return(root_book,isbn_number,choice);
    break;
    }

}


void students_borrowed_book_list(char *ID, student* iter_student){

    int i=0;
   
    while(strcmp(iter_student->ID,ID) != 0){

        iter_student = iter_student->next;

    }

    while(iter_student->borrowed_books[i][0] != '\0'){
 
        printf("%s\n",iter_student->borrowed_books[i]);
        i++;

    }

}

book* addBook(book* root_book, FILE *book_file, char* isbn, char* title, char* author, char* publicationYear, int method){

    book *iter_book;

    iter_book = root_book;
    
    if(method == 0){

        book *temp = iter_book;
       
        while(iter_book->next != NULL){

            iter_book = iter_book->next;

        }

        iter_book->next = (book *)malloc(sizeof(book));

        iter_book = iter_book->next;

        strcpy(iter_book->ISBN_number,isbn);
        strcpy(iter_book->title,title);
        strcpy(iter_book->author,author);
        strcpy(iter_book->publication_year,publicationYear);
        strcpy(iter_book->reserved_status, "N");

        book_file = fopen("book.txt","a");
        fseek(book_file,SEEK_END,0);

        fprintf(book_file,"\n%s,%s,%s,%s",iter_book->ISBN_number,iter_book->title,iter_book->author,iter_book->publication_year);

        return temp;

    }

    else if(method == 1){

        book *temp = (book *)malloc(sizeof(book));
        temp->next = root_book;
        
        strcpy(temp->ISBN_number,isbn);
        strcpy(temp->title,title);
        strcpy(temp->author,author);
        strcpy(temp->publication_year,publicationYear);
        strcpy(iter_book->reserved_status, "N");


        book_file = fopen("book.txt","w");

        iter_book = temp;

        while(iter_book->next != NULL){
        
            if(iter_book->next != NULL){    
                
                fprintf(book_file,"%s,%s,%s,%s\n",iter_book->ISBN_number,iter_book->title,iter_book->author,iter_book->publication_year);
            
            }

            iter_book = iter_book->next;

        }

        return temp;

    }

}

void deleteBook(book* root_book, FILE *book_file, char* isbn){
    
    book* iter_book;
    
    iter_book = root_book;

    // Deleting from linked list 
    while(strcmp(iter_book->next->ISBN_number, isbn) != 0){

        iter_book = iter_book->next;

    }

    iter_book->next = iter_book->next->next;
    
    
    // Deleting from txt file 
    book_file = fopen("book.txt","w");

    iter_book = root_book;

    while(iter_book->next != NULL){
        
        fprintf(book_file,"%s,%s,%s,%s\n",iter_book->ISBN_number,iter_book->title,iter_book->author,iter_book->publication_year);
        iter_book = iter_book->next;

    }

    printf("Succesful!!\n");
    
    fclose(book_file);

}

void searchBooks(book* root_book, int searchChoice, char* searchValue){

    book *iter_book;
    iter_book = root_book;

    switch (searchChoice){
    
    case 0:

        while(strcmp(searchValue, iter_book->ISBN_number) != 0){

            iter_book = iter_book->next;

            if(iter_book->next == NULL){

                printf("book does not exist\n");
                exit(0);

            }

        }

        printf("%s %s %s %s %s\n",iter_book->ISBN_number,iter_book->title,iter_book->author,iter_book->publication_year,iter_book->reserved_status);

    break;
    
    case 1: 

        while(strcmp(searchValue, iter_book->author) != 0){

            iter_book = iter_book->next;

            if(iter_book->next == NULL){

                printf("book does not exist\n");
                exit(0);

            }

        }

        printf("%s %s %s %s %s\n",iter_book->ISBN_number,iter_book->title,iter_book->author,iter_book->publication_year,iter_book->reserved_status);
    break;

    case 2: 

        while(strcmp(searchValue, iter_book->title) != 0){

            iter_book = iter_book->next;

            if(iter_book->next == NULL){

                printf("book does not exist\n");
                exit(0);

            }

        }

        printf("%s %s %s %s %s\n",iter_book->ISBN_number,iter_book->title,iter_book->author,iter_book->publication_year,iter_book->reserved_status);

    break;

    }



}

void updateBook(book* root_book, FILE* book_file, char* isbn, char* feature, char* value){

    book* iter_book;
    iter_book = root_book;

    book_file = fopen("book.txt","w");
    
    while(strcmp(isbn, iter_book->ISBN_number) != 0){

        iter_book = iter_book->next;

        if(iter_book->next == NULL){

            printf("book does not exist\n");
            exit(0);

        }

    }
    
    if(strcmp(feature,"title") == 0){

        strcpy(iter_book->title,value);

    }

    else if(strcmp(feature,"author") == 0){

        strcpy(iter_book->author,value);
       
    }

    else if(strcmp(feature,"publication year") == 0){

        strcpy(iter_book->publication_year,value);
       
    }

    iter_book = root_book;

    while(iter_book->next != NULL){
        
        fprintf(book_file,"%s,%s,%s,%s\n",iter_book->ISBN_number,iter_book->title,iter_book->author,iter_book->publication_year);
        iter_book = iter_book->next;

    }
    

    fclose(book_file);

}

void borrow_and_return(book* root_book, char* isbn, int choice){

    book* iter_book = root_book;
    
    while(strcmp(isbn, iter_book->ISBN_number) != 0){

        iter_book = iter_book->next;

        if(iter_book->next == NULL){

            printf("book does not exist\n");
            exit(0);

        }

    }
    
    if(choice == 0){
        
        strcpy(iter_book->reserved_status,"N");

    }

    else if(choice == 1){
        
        strcpy(iter_book->reserved_status,"Y");

    }

    printf("%s %s %s %s %s\n",iter_book->ISBN_number,iter_book->title,iter_book->author,iter_book->publication_year,iter_book->reserved_status);

}