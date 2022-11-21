/* ============================================================================
Proposed Exercise: Develop the design of a program to encrypt text files, that moves the characters typed 3 positions forward. Example:

Original message: Curso de C
Encrypted message: Fxuvr#gh#F

Develop a software to remove the encryption and generate a new file with the original message. Example:

Encrypted message: Fxuvr#gh#F
Encryption removed: Curso de C

    Start : 17/11
    End: 
    Autor: Eng. André Biasuz
    Date:  November 2022

 KNOWN INTERATIONS TO FOLLOW AFTER STABLE BUILD:
- 
============================================================================ */

/* --- Libraries  --- */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ========================================================================= */
/* --- Constants and Macros --- */
// define how many levels the stack will have

/* ========================================================================= */
/* --- Global variables --- */

/* ========================================================================= */
/* --- Prototypes --- */
FILE *open_file(char* filename, char* mode);
void file_write(char *file_name);
FILE *crypto_3_ASCII(char* input_file_name, char* output_file_name);
//void file_destroy_contents(char *file_name);
/* ========================================================================= */
/* --- Main routine --- */

int main(int argc, char *argv[])
{    
  //char string_to_file[256];
  
  char file1_name[30] = "crypto.txt";
  char file2_name[30] = "decoded.txt";    

  FILE *input = open_file(file1_name,"a");
  FILE *output = open_file(file2_name, "a");  

    
  file_write("crypto.txt");
  file_write("decoded.txt");
  crypto_3_ASCII("crypto.txt", "decoded.txt");
}

/* ========================================================================= */
/* --- Functions' development --- */
FILE *open_file(char* filename, char* mode)
{
    FILE *f;
    f = fopen(filename, mode);
    if(!f)
    {
        perror(filename);
        exit(0);
    }

   // fclose(f);
}

void file_write(char *file_name) {
    
    char content[256];
    FILE *f1 = fopen(file_name, "a");
    
    fgets(content, sizeof(content), stdin);
      
    fprintf(f1 , "%s", content);

    //fclose(f1);
}

/*void file_destroy_contents(char *file_name){

    char *result = malloc(strlen(file_name) + strlen("folder//") + 1);
    strcat(result, "folder//");
    strcat(result, file_name);
    printf("%s", result);
    fopen(result, "w");
}*/

FILE *crypto_3_ASCII(char* input_file_name, char* output_file_name) {
    FILE *input,*output;
    
    input = open_file(input_file_name,"r");
    output = open_file(output_file_name, "a");

    int ch; // char to get the value and also serve as EOF tag

    while((ch = fgetc(input)) != EOF) {
        fputc (ch, output);
    }

    //fclose(input);
    //fclose(output);    
}

/* ========================================================================= */
/* --- End of Program --- */
