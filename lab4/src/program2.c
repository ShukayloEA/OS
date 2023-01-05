#include <stdio.h>
#include <dlfcn.h>
#include "realization.h"

#pragma GCC diagnostic ignored "-Wpedantic"


int main () {
    void* handle = NULL; 
    const char* libArray[] = {"libd1.so", "libd2.so"};
    int currentLib = 0;

    if (!(handle  = dlopen(libArray[currentLib], RTLD_LAZY))){
        printf("dlopen error\n");
        return -1;
    }
    
    Der der = (Der)dlsym(handle, "Derivative"); 
    Sq sq = (Sq)dlsym(handle, "Square");

    int command;
    while (printf("Please enter your command:\n0 for changing the contract\n1 for calculating the exponent\n2 for calculating the square\n") && (scanf("%d", &command)) != EOF) {
        switch (command) {
            case 0: {
                dlclose(handle); 
                currentLib = (currentLib+ 1) % 2;
                if (!(handle = dlopen(libArray[currentLib], RTLD_LAZY))) {
                    printf("dlopen error\n");
                    return -1;
                }
                            
                der = (Der)dlsym(handle, "Derivative"); 
                sq = (Sq)dlsym(handle, "Square");
                
                printf("Changed\n");

		        break;
            }
            case 1: {
                float A, deltaX;
		        if (scanf("%f %f", &A, &deltaX) == 2) {
		            printf("%.5f\n", (*der)(A, deltaX));
		        }
		        break;
            }
            case 2: {
                float A, B;
                if (scanf("%f %f", &A, &B) == 2) {
		            printf("%.5f\n", (*sq)(A, B));
		        }
		        break;
            }
            default:{
		        printf("Wrong answer\n");
                break;
            }
        }
    }
    dlclose(handle);
    return 0;
}
