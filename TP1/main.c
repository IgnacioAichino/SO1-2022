#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "functionsFS.h"
#include "dinamic.h"


int main(int argc, char *argv[]){

    //File pointer
    FILE* fp;
    size_t bytes_read= 0;

    int option= 0;

    do{
        printf("\nMenu: \n"
                "[1] /proc/cpuinfo \n"
                "[2] /proc/meminfo \n"
                "[3] /proc/version \n"
                "[4] Exit \n");
        
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\n--------CPU--------\n");
                getCPU(fp, bytes_read);
                break;

            case 2:
                printf("-------MEMORY-------\n");
                getMemory(fp, bytes_read);
                break;
       
            case 3:
                printf("\n-----SO VERSION------\n");
                getVersion(fp, bytes_read);
                break;
            
            case 4:
                exit(0);             
            
            default:
                printf("\n OPCION INCORRECTA \n");
                break;
        }
    }while(option != 1 || option !=2 || option !=3 || option != 4);

    return 0;

}