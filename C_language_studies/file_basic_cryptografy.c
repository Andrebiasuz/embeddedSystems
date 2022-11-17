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
FILE *file_create(const char *name);
void file_write(FILE *file_name);
void file_destroy_contents(char *file_name);
/* ========================================================================= */
/* --- Main routine --- */

int main(int argc, char *argv[])
{    
  //char string_to_file[256];
  
  char file1_name[30] = "gtro.txt";
    
  FILE *crypto1 = file_create(file1_name);
  file_write(crypto1);
  file_destroy_contents(file1_name);
}

/* ========================================================================= */
/* --- Functions' development --- */
 FILE *file_create(const char *name) {

     
    FILE *p1 = fopen(name, "a+");

    if (p1 == NULL) {
        puts("Error creating file");
        system("pause");
        exit(0);
    } 

     puts("File created successfully");
     //fclose(p1);
     return p1;
 }

void file_write(FILE *file_name) {
    char content[256];

    fgets(content, sizeof(content), stdin);
    
   // fopen(file_name, "r+");

    fprintf(file_name, "%s", content);

    fclose(file_name);
}

void file_destroy_contents(char *file_name){

    char *result = malloc(strlen(file_name) + strlen("folder//") + 1);
    strcat(result, "folder//");
    strcat(result, file_name);
    printf("%s", result);
    fopen(result, "w");
    

}
/* ========================================================================= */
/* --- End of Program --- */
