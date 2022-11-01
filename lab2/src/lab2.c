#define _TIMESPEC_DEFINED

#include "lab2.h" 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
//#include <time.h> 


void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int low, int high, int *arr)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickSort(int low, int high, int *arr)
{
    if (low < high) {
        int pi = Partition(low, high, arr);

        QuickSort(low, pi - 1, arr);
        QuickSort(pi + 1, high, arr);
    }
}

void* QuickSortThread(void* arg)
{
    tsk* Tsk;
    Tsk = (tsk*)arg;
    int mid = (Tsk->left + Tsk->right) / 2;

    if (Tsk->left < Tsk->right) {
        QuickSort(Tsk->left, mid, Tsk->arr);
        QuickSort(mid + 1, Tsk->right, Tsk->arr);
        QuickSort(Tsk->left, Tsk->right, Tsk->arr);
    }

    return NULL;
}

void Sort(int numberThreads, int size, int *arr, FILE *out) {
    //clock_t start_time, end_time;
    //float timer = 0.0;
    //start_time = clock();

    tsk* arrThread = NULL;

    pthread_t* threads = (pthread_t*)malloc((numberThreads) * sizeof(pthread_t));
    tsk* tsklist = (tsk*)malloc((numberThreads) * sizeof(tsk));

    if (numberThreads > size) {
        numberThreads = size;
    }

    int length = size / numberThreads;
    int low = 0;

    for (int i = 0; i < numberThreads; i++, low += length) {
        arrThread = &tsklist[i];
        arrThread->number = i;
        arrThread->left = low;
        arrThread->right = low + length - 1;
        arrThread->arr = arr;

        if (i == (numberThreads - 1)) {
            arrThread->right = size - 1;
        }
    }

    for (int i = 0; i < numberThreads; i++) {
        arrThread = &tsklist[i];
        pthread_create(&threads[i], NULL, QuickSortThread, arrThread);
        pthread_join(threads[i], NULL);
    }
    
    QuickSort(0, size - 1, arr);

//    end_time = clock();
//    timer = end_time - start_time;

    free(threads);
    free(tsklist);

 //   printf("Sorted array: \n");

    for (int i = 0; i < size; i++) {
        fprintf(out, "%d ", arr[i]);
    }

//    printf("\n");

//    printf("\nTime: %f\n", timer / CLOCKS_PER_SEC);
}