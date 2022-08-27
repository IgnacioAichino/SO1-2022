#include <string.h>
#include <stdlib.h>
#include <stdio.h>



void getCPU(FILE* fp, size_t bytes_read){

    char buffer[15000];
    char* match;
    char cpu_model[50];
    int cpu_cores, cpu_threads;

    fp= fopen("/proc/cpuinfo", "r");
    if(fp == NULL){
        printf("No se pudo abrir el archivo");
        exit(0);
    }

    //Read file
    bytes_read= fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);
    if(bytes_read == 0 || bytes_read == sizeof(buffer)){
        printf("No se pudo leer el file /proc/cpuinfo");
        exit(0);
    }

    //NULL terminate text
    buffer[bytes_read]= '\0';
    // printf("%s\n", buffer);

    //Locate the line with 'string'
    match= strstr(buffer, "model name");
    if(match == NULL){
        printf("No matcheo substring en /proc/cpuinfo");
        exit(0);
    }

    sscanf(match, "model name : %100[^\n]", cpu_model);
    printf("CPU model: %s\n", cpu_model);

    //find cores
    match= strstr(buffer, "cpu cores");
    if(match == NULL){
        printf("No matcheo substring en /proc/cpuinfo");
        exit(0);
    }

    sscanf(match, "cpu cores : %d", &cpu_cores);
    printf("CPU cores: %d\n", cpu_cores);

    //find threads
    match= strstr(buffer, "siblings");
    if(match == NULL){
        printf("No matcheo substring en /proc/cpuinfo");
        exit(0);
    }

    sscanf(match, "siblings : %d", &cpu_threads);
    printf("Threads: %d\n", cpu_threads);

}

void getMemory(FILE* fp, size_t bytes_read){

    char buffer[500];
    char* match;
    int total, available, free, swap;

    fp= fopen("/proc/meminfo", "r");    
    if(fp == NULL){
        printf("No se pudo abrir el file /proc/meminfo");
        exit(0);
    }

    //Read file
    bytes_read= fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);
    if(bytes_read == 0){
        printf("No se pudo leer el file /proc/meminfo");
        exit(0);
    }

    //NULL terminate text
    buffer[bytes_read]= '\0';
    // printf("%s\n", buffer);

    //Locate the line with 'string'
    match= strstr(buffer, "MemTotal");
    if(match == NULL){
        printf("No matcheo substring en /proc/meminfo");
        exit(0);
    }

    sscanf(match, "MemTotal: %d", &total);
    printf("Memory total: %d MB\n", total/1000);


    //Find avaible
    match= strstr(buffer, "MemAvailable");
    if(match == NULL){
        printf("No matcheo substring en /proc/meminfo");
        exit(0);
    }

    sscanf(match, "MemAvailable: %d", &available);
    printf("Memory available: %d MB\n", available/1000);
    
    //Find free
    match= strstr(buffer, "MemFree");
    if(match == NULL){
        printf("No matcheo substring en /proc/meminfo");
        exit(0);
    }

    sscanf(match, "MemFree: %d", &free);
    printf("Memory free: %d MB\n", free/1000);

    //Find swap
    match= strstr(buffer, "SwapCached");
    if(match == NULL){
        printf("No matcheo substring en /proc/meminfo");
        exit(0);
    }

    sscanf(match, "SwapCached: %d", &swap);
    printf("Swap in cache: %d MB\n", swap/1000);

}