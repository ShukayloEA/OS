// OS_lab_2_Shukaylo.c
//var 2

#include <stdio.h> 
#include <stdlib.h>
#include "lab2.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        perror("few arguments\n");
        return 1;
    }
    int* arr = NULL;
    
    int numberThreads = atoi(argv[1]);
    int size = atoi(argv[2]);
    
    arr = (int*)malloc(sizeof(int) * size);
    
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    Sort(numberThreads, size, arr, stdout);

    return 0;
}
