#include <stdio.h>
#include "realization.h"

int main () {
    int command;
    while (printf("Please enter your command: ") && (scanf("%d", &command)) != EOF) {
        switch (command) {
            case 1: {
                float A, deltaX;
		        if (scanf("%f %f", &A, &deltaX) == 2) {
		            printf("%.5f\n", Derivative(A, deltaX));
		        }
		        break;
            }
            case 2: {
                float A, B;
                if (scanf("%f %f", &A, &B) == 2) {
		            printf("%.5f\n", Square(A, B));
		        }
		        break;
            }
            default:{
		        printf("Wrong answer\n");
                break;
            }
        }
    }
    return 0;
}
