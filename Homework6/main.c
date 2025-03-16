#include <stdio.h>

#define MAX_WORD_COUNT 100
#define MAX_WORD_SIZE 12

int read_dict(const char * file_name, char dict[][MAX_WORD_SIZE]);
int read_text(const char * text_file, const char * ignore_file, char words[][MAX_WORD_SIZE]);
double dissimilarity(char * w1, char * w2, char dict[][MAX_WORD_SIZE], float threshold, int * a);

int main(int argc, char *argv[]){

    char input[150000][MAX_WORD_SIZE];
    int b;

    FILE *story;

    story = fopen("input.txt","r");

    b = read_dict("dictionary.txt",input);

    printf("%d\n",b);




}

int read_text(const char * text_file, const char * ignore_file, char words[][MAX_WORD_SIZE]){

    FILE *story;

    int wordcounter = 1, a = 0, b = 0, i, c = 0;
    char input;

    story = fopen(text_file,"r");

    while(feof(story) == 0){

        fscanf(story,"%c",&input);
        
        if(((input > 64) && (input < 91)) || ((input > 96) && (input < 123)) || (input == ' ') ){

            if(input == ' '){

                words[wordcounter][a+1] = '\0'; 

                for(i = 0; i<c; i++){


                    if(words[wordcounter] == "book"){

                        wordcounter--;

                    }

                }

                wordcounter++;
                a = 0;

            }

            else{

                words[wordcounter][a] = input;

            }

        }

    }


    return wordcounter;

}

int read_dict(const char * file_name, char dict[][MAX_WORD_SIZE]){

    FILE *dictionary;

    dictionary = fopen(file_name,"r");

    int wordcounter = 0;
    char buffer[100000];

    fscanf(dictionary,"%[^\n]",buffer);

    while(feof(dictionary) == 0){

        fscanf(dictionary,"%s",&dict[wordcounter]);

        fscanf(dictionary,"%[^\n]",buffer);

        wordcounter++;


    }

    return wordcounter;

}
