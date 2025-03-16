#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char name[20];
    char age;
    struct node* father;
    struct node* mother;
    struct node** children;
} node;

void menu();
void submenu1();
void add_node(node** root_father, node** root_mother, char* name, int age, char* father_name, char* mother_name, int* children_size);
void load_family(const char* file_name, node** root_grandfather, node** root_grandmother);

int main(){
    menu();
    int children_size = 0;
    node* root_Father =(node*)malloc(sizeof(node));
    node* root_mother =(node*)malloc(sizeof(node));
}

void menu(){
    
    int choice;
    char filename[20];
    node* root_grandfather;
    node* root_grandmother;

    printf("\n*************************\n");
    printf("Family Tree System Menu:\n");
    printf("1- Add Family Tree\n");
    printf("2- Remove Family Tree\n");
    printf("3- Load Family Tree\n");
    printf("4- Exit\n");
    printf("*************************\n");
    printf(">");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            submenu1();
            break;
        case 2:
            break;
        case 3:
            printf("Enter the file name: ");
            scanf("%s",filename);
            load_family(filename,&root_grandfather,&root_grandmother);
            break;
        case 4:
            exit(0);
            break;
    }
}

void submenu1(){
    int choice, age, second_choice, children_size = 0;
    char *name, *father_name, *mother_name;

    node* root_father;
    node* root_mother;

    printf("1-Add node\n");
    printf("2-Save Family Tree\n");
    printf("3-Exit\n");

    printf(">");
    scanf("%d",&second_choice);

    switch(second_choice){
        case 1:
            name = (char*)malloc(20 * sizeof(char));
            father_name = (char*)malloc(20 * sizeof(char));
            mother_name = (char*)malloc(20 * sizeof(char));

            printf("Enter the name of the person: ");
            scanf("%s",name);
            
            printf("Enter the age of the person: ");
            scanf("%d",&age);

            printf("Enter the name of the mother: ");
            scanf("%s",mother_name);

            printf("Enter the name of the father: ");
            scanf("%s",father_name);
            
            add_node(&root_father, &root_mother ,name,age,father_name,mother_name, &children_size);
            printf("%s\n",root_father->children[0]->name);
            submenu1();

            free(name);
            free(father_name);
            free(mother_name);
            break;
        case 2:
            break;
        case 3:
            exit(0);
            break;
    }
}

void add_node(node** root_father, node** root_mother, char* name, int age, char* father_name, char* mother_name, int* children_size){
    node* iter_father = *root_father;
    node* iter_mother = *root_mother;
    node* newchild = (node*)malloc(sizeof(node));
    int i;

    if(strcmp(iter_father->name,father_name) == 0 && strcmp(iter_mother->name,mother_name) == 0){
        for(i=0; i<*children_size; i++){
            if(strcmp(iter_father->children[i]->name,name) == 0){
                printf("This person already exists\n");
                break;
            }
        }
        newchild->age = age;
        newchild->father = *root_father;
        newchild->mother = *root_mother;
        strcpy(newchild->name,name);

        (*children_size)++;
        iter_father->children = (node**)realloc(iter_father->children,(*children_size)*sizeof(node*));
        iter_father->children[(*children_size)-1] = newchild;
        *root_father = iter_father;
        *root_mother = iter_mother;
    }
}

void load_family(const char* file_name, node** root_grandfather, node** root_grandmother){

    char line[100], token, name[5][20];
    int kidsizesave, i=1;
    int kidsize = 0;

    FILE* family;
    family = fopen("%s",file_name,"r");

    if(*root_grandfather == NULL && *root_grandmother == NULL){

        *root_grandfather = (node*)malloc(sizeof(node));
        *root_grandmother = (node*)malloc(sizeof(node));

    }

    node* grandfather = *root_grandfather;
    node* grandmother = *root_grandmother;

    grandfather->father = NULL;
    grandfather->mother = NULL;

    grandmother->father = NULL;
    grandmother->mother = NULL;

    while(feof(family) == 0){    
        
        fgets(line, 100, family);
        line[strlen(line) - 1] = '\0'; // Remove the newline character from the string

        token = strtok(line, ",");
        strcpy(grandfather->name, token);

        token = strtok(NULL, ",");
        strcpy(grandfather->age, token);

        kidsize = 0;

        while (token != NULL) {
            
            token = strtok(NULL, ",");
            
            if (token != NULL) {
            
                if(kidsize == 0){
                    
                    kidsize++;
                    grandfather->children = (node**)malloc(grandfather->children,(kidsize)*sizeof(node*));

                }
                
                grandfather->children = (node**)realloc(grandfather->children,(kidsize)*sizeof(node*));
                strcpy(grandfather->children[kidsize-1]->name,token);
                kidsize++;
                kidsizesave = kidsize;
            
            }

            grandfather = grandfather->children[kidsize-(kidsizesave-i)];
            i++;

        }

        

    }



}
