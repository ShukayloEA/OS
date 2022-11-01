#ifndef OS_LABS_LAB2_H
#define OS_LABS_LAB2_H

#include <stdio.h>

typedef struct {
    int number;
    int left;
    int right;
    int* arr;
} tsk;

void Swap(int* a, int* b);
int Partition(int low, int high, int *arr);
void QuickSort(int low, int high, int *arr);
void* QuickSortThread(void* arg);
void Sort(int numberThreads, int size, int *arr, FILE *out);
#endif
