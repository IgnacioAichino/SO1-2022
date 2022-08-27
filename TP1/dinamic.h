#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void getVersion(FILE* fp, size_t bytes_read){

    bytes_read= 1024;
    char* word= malloc(sizeof(char) * bytes_read);

    if(word == NULL){
        printf("Fail malloc");
        exit(0);
    }

    fp= fopen("/proc/version", "r");
    if(fp == NULL){
        printf("No se pudo abrir el archivo");
        exit(0);
    }


    /*while(fgets(word, bytes_read, fp) != NULL) 
    {
        //printf("%s\n", word);
    }*/

    if(fgets(word, bytes_read, fp) == NULL){
        printf("Fail fgets\n");
        exit(0);
    }
    
    fclose(fp);

    for(size_t i=0; i<strlen(word); i++){
        printf("%c", toupper(word[i]));
    }
    
    free(word);

}