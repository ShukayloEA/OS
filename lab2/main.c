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

    //printf("Number elements: \n");
    //scanf("%d", &size);
    //numberThreads = 10;
    arr = (int*)malloc(sizeof(int) * size);
    //printf("Array of integers: \n");

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        //arr[i] = rand() % 1000;
        //printf("%d ", arr[i]);
    }
    //printf("\n");

    Sort(numberThreads, size, arr, stdout);

    return 0;
}
