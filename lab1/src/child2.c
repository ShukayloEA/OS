#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "utils.h"

int main(void) {
    char* input = NULL;
  
    int length = 0;

    while ((input = ReadString(stdin)) != NULL) {
        length = strlen(input);
        int j = 0;
        for (int i = 0; i < length; ++i, ++j) {
            input[j] = input[i];

            if (input[i] == ' ') {
                while (input[i] == ' ') {
                    ++i;
                }
                --i;
            }
        }

        if (j != length) {
            input[j] = '\0';
        }

        write(1, input, j);
       
        free(input);
    }

    return 0;
}
