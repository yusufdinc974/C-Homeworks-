#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
 void* data;
 struct Node* next;
} Node;

typedef struct {
 char type[20];
 int ivals[1];
 double svals[1];
} Asset1;

typedef struct {
 char type[20];
 double svals[2];
 int ivals[2];
}Asset2;

typedef struct {
 char type[20];
 char string1[50];
 char string2[50];
}Asset3;

typedef struct {
 char type[20];
 double value1;
 float value2;
 double value3;
}Asset4;

void fillLinkedList(struct Node** head);
void serializeLinkedList(struct Node* head);
void deserializeLinkedList(struct Node** head);

int main(){

    Node* head = NULL;
    Node* newhead = NULL;

    srand(time(NULL));
    

    fillLinkedList(&head);

    serializeLinkedList(head);

    deserializeLinkedList(&newhead);


    printf("----------FillLinkedList----------\n");

    while(head != NULL){

        if(strcmp(((Asset1*)head->data)->type,"typeone") == 0){   
            
            printf("type: %s\t",((Asset1*)head->data)->type);
            printf("ivals: %d\t",((Asset1*)head->data)->ivals[0]);
            printf("svals: %.2lf\n",((Asset1*)head->data)->svals[0]);

            head = head->next;

        }

        else if(strcmp(((Asset1*)head->data)->type,"typetwo") == 0){   
            
            printf("type: %s\t",((Asset2*)head->data)->type);
            printf("ivals[0]: %d\t",((Asset2*)head->data)->ivals[0]);
            printf("ivals[1]: %d\t",((Asset2*)head->data)->ivals[1]);
            printf("svals[0]: %.2lf\t",((Asset2*)head->data)->svals[0]);
            printf("svals[1]: %.2lf\n",((Asset2*)head->data)->svals[1]);
            head = head->next;

        }

        else if(strcmp(((Asset1*)head->data)->type,"typethree") == 0){   
            
            printf("type: %s\t",((Asset3*)head->data)->type);
            printf("string1: %s\t",((Asset3*)head->data)->string1);
            printf("string2: %s\n",((Asset3*)head->data)->string2);
            head = head->next;

        }

        else if(strcmp(((Asset1*)head->data)->type,"typefour") == 0){   
            
            printf("type: %s\t",((Asset4*)head->data)->type);
            printf("value1: %.2lf\t",((Asset4*)head->data)->value1);
            printf("value2: %.2f\t",((Asset4*)head->data)->value2);
            printf("value3: %.2lf\n",((Asset4*)head->data)->value3);
            head = head->next;

        }

    }

    printf("\n\n");
    printf("----------deserializeLinkedList----------\n");

    while(newhead != NULL){

        if(strcmp(((Asset1*)newhead->data)->type,"typeone") == 0){   
            
            printf("type: %s\t",((Asset1*)newhead->data)->type);
            printf("ivals: %d\t",((Asset1*)newhead->data)->ivals[0]);
            printf("svals: %.2lf\n",((Asset1*)newhead->data)->svals[0]);

            newhead = newhead->next;

        }

        else if(strcmp(((Asset1*)newhead->data)->type,"typetwo") == 0){   
            
            printf("type: %s\t",((Asset2*)newhead->data)->type);
            printf("ivals[0]: %d\t",((Asset2*)newhead->data)->ivals[0]);
            printf("ivals[1]: %d\t",((Asset2*)newhead->data)->ivals[1]);
            printf("svals[0]: %.2lf\t",((Asset2*)newhead->data)->svals[0]);
            printf("svals[1]: %.2lf\n",((Asset2*)newhead->data)->svals[1]);
            newhead = newhead->next;

        }

        else if(strcmp(((Asset1*)newhead->data)->type,"typethree") == 0){   
            
            printf("type: %s\t",((Asset3*)newhead->data)->type);
            printf("string1: %s\t",((Asset3*)newhead->data)->string1);
            printf("string2: %s\n",((Asset3*)newhead->data)->string2);
            newhead = newhead->next;

        }

        else if(strcmp(((Asset1*)newhead->data)->type,"typefour") == 0){   
            
            printf("type: %s\t",((Asset4*)newhead->data)->type);
            printf("value1: %.2lf\t",((Asset4*)newhead->data)->value1);
            printf("value2: %.2f\t",((Asset4*)newhead->data)->value2);
            printf("value3: %.2lf\n",((Asset4*)newhead->data)->value3);
            newhead = newhead->next;

        }

    }



}

void fillLinkedList(struct Node** head) {
    int assetnumber, assettype;
    int i;
    Node* tempnode;
    Node* temphead;
    Asset1* tempasset1;
    Asset2* tempasset2;
    Asset3* tempasset3;
    Asset4* tempasset4;

    assetnumber = (rand() % 11) + 10;

    temphead = (*head);

    for(i = 0; i< assetnumber; i++){

        assettype = (rand() % 4) + 1;

        switch (assettype) {
            case 1:
  
                    tempnode = (Node*)malloc(sizeof(Node));
                    tempasset1 = (Asset1*)malloc(sizeof(Asset1));

                    tempasset1->ivals[0] = rand() % 101;
                    tempasset1->svals[0] = rand() % 101;
                    strcpy(tempasset1->type, "typeone");

                    tempnode->data = tempasset1;
                    tempnode->next = NULL;
                    

                    if (temphead == NULL) {
                        temphead = tempnode;
                        (*head) = temphead;
                    } else {
                        temphead->next = tempnode;
                        temphead = tempnode;
                    }
                
                break;

            case 2:
     
                
                    tempnode = (Node*)malloc(sizeof(Node));
                    tempasset2 = (Asset2*)malloc(sizeof(Asset2));

                    tempasset2->ivals[0] = rand() % 101;
                    tempasset2->ivals[1] = rand() % 101;
                    while(tempasset2->ivals[0] == tempasset2->ivals[1]){
                        tempasset2->ivals[1] = rand() % 101;
                    }
                    
                    tempasset2->svals[0] = rand() % 101;
                    tempasset2->svals[1] = rand() % 101;
                    while(tempasset2->svals[0] == tempasset2->svals[1]){
                        tempasset2->ivals[1] = rand() % 101;
                    }
                    strcpy(tempasset2->type, "typetwo");

                    tempnode->data = tempasset2;
                    tempnode->next = NULL;
                

                    if (temphead == NULL) {
                        temphead = tempnode;
                        (*head) = temphead;
                    } else {
                        temphead->next = tempnode;
                        temphead = tempnode;
                    }
                
                break;

            case 3:

                
                    tempnode = (Node*)malloc(sizeof(Node));
                    tempasset3 = (Asset3*)malloc(sizeof(Asset3));

                    strcpy(tempasset3->string1,"random1");
                    strcpy(tempasset3->string2,"random2");
                    strcpy(tempasset3->type, "typethree");

                    tempnode->data = tempasset3;
                    tempnode->next = NULL;
                    

                    if (temphead == NULL) {
                        temphead = tempnode;
                        (*head) = temphead;
                    } else {
                        temphead->next = tempnode;
                        temphead = tempnode;
                    }
                
                break;

            case 4:
                
                
                    tempnode = (Node*)malloc(sizeof(Node));
                    tempasset4 = (Asset4*)malloc(sizeof(Asset4));

                    tempasset4->value1 = rand() % 101;
                    tempasset4->value2 = rand() % 101;
                    tempasset4->value3 = rand() % 101;
                    strcpy(tempasset4->type, "typefour");

                    tempnode->data = tempasset4;
                    tempnode->next = NULL;
                    

                    if (temphead == NULL) {
                        temphead = tempnode;
                        (*head) = temphead;
                    } else {
                        temphead->next = tempnode;
                        temphead = tempnode;
                    }
                
                break;

            default:
                printf("That number of asset doesn't exist\n");
                break;
        }

    }
}

void serializeLinkedList(struct Node* head) {
    Node* temp = head;

    FILE* ptr = fopen("linkedlist.bin", "wb");
    if (ptr == NULL) {
        printf("Failed to open the file.\n");
        return;  // or take appropriate actions
    }

    while (temp != NULL) {
        if (strcmp(((Asset1*)temp->data)->type, "typeone") == 0) {
            fwrite(temp->data, sizeof(Asset1), 1, ptr);
        } else if (strcmp(((Asset2*)temp->data)->type, "typetwo") == 0) {
            fwrite(temp->data, sizeof(Asset2), 1, ptr);
        } else if (strcmp(((Asset3*)temp->data)->type, "typethree") == 0) {
            fwrite(temp->data, sizeof(Asset3), 1, ptr);
        } else if (strcmp(((Asset4*)temp->data)->type, "typefour") == 0) {
            fwrite(temp->data, sizeof(Asset4), 1, ptr);
        } else {
            printf("Unknown asset type.\n");
            fclose(ptr);
            return;  // or take appropriate actions
        }
        temp = temp->next;
    }

    fclose(ptr);
    printf("Writing is over.\n");
}

void deserializeLinkedList(struct Node** head) {
    FILE* file = fopen("linkedlist.bin", "rb");
    
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    *head = (Node*)malloc(sizeof(Node));
    Node* current = *head;

    char type[20];
    
    
    while(1){

        fread(type, sizeof(char), sizeof(type), file);

        if(strcmp(type,"typeone") == 0){

                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->data = malloc(sizeof(Asset1)); 
                newNode->next = NULL;

                size_t elements_read = fread(newNode->data, sizeof(Asset1), 1, file);

                if (elements_read != 1) {
                    // No more elements to read or an error occurred
                    free(newNode->data);
                    free(newNode);
                    break;
                }

                if (*head == NULL) {
                    *head = newNode;
                    current = newNode;
                } else {
                    current->next = newNode;
                    current = current->next;
                }
            

        }

        else if(strcmp(type,"typetwo") == 0){

        
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->data = malloc(sizeof(Asset2)); // Allocate memory for the largest data type (Asset4)
                newNode->next = NULL;

                size_t elements_read = fread(newNode->data, sizeof(Asset2), 1, file);
            
                if (elements_read != 1) {
                    // No more elements to read or an error occurred
                    free(newNode->data);
                    free(newNode);
                    break;
                }

                if (*head == NULL) {
                    *head = newNode;
                    current = newNode;
                } else {
                    current->next = newNode;
                    current = current->next;
                }
            
        }

        else if(strcmp(type,"typethree") == 0){
        
            
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->data = malloc(sizeof(Asset3)); // Allocate memory for the largest data type (Asset4)
                newNode->next = NULL;

                size_t elements_read = fread(newNode->data, sizeof(Asset3), 1, file);
            
                if (elements_read != 1) {
                    // No more elements to read or an error occurred
                    free(newNode->data);
                    free(newNode);
                    break;
                }

                if (*head == NULL) {
                    *head = newNode;
                    current = newNode;
                } else {
                    current->next = newNode;
                    current = current->next;
                }
        

        }

        else if(strcmp(type,"typefour") == 0){

            
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->data = malloc(sizeof(Asset4)); // Allocate memory for the largest data type (Asset4)
                newNode->next = NULL;

                size_t elements_read = fread(newNode->data, sizeof(Asset4), 1, file);
            
                if (elements_read != 1) {
                    // No more elements to read or an error occurred
                    free(newNode->data);
                    free(newNode);
                    break;
                }

                if (*head == NULL) {
                    *head = newNode;
                    current = newNode;
                } else {
                    current->next = newNode;
                    current = current->next;
                }
            

        }

        else{

            printf("NO TYPE\n");
            break;

        }

    }

}
