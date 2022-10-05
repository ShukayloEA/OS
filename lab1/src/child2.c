#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "utils.h"

int main(const int argc, const char* argv[]) {
    if (argc != 2) {
          printf("Necessary arguments were not provided\n");
          exit(EXIT_FAILURE);
    }
    
    FILE* out = fopen(argv[1], "w");
    if (!out) {
        printf("Failed to open file\n");
        exit(EXIT_FAILURE);
    }
    
    char* input = NULL;
  
    int count = 0;
    int length = 0;

    while ((input = ReadString(stdin)) != NULL) {
        length = strlen(input);
        printf("read the string\n");
        char* output = (char*)malloc(length);
        printf("create output %s\n", output);
        for (int i = 0, j = i; i < length; i++, j++) {
            if (input[i] == ' ') {
                count++;
            }
            else {
                count = 0;
            }

            if (count > 1) {
                j--;
            }
            output[j] = input[i];
	        if (i == length - 1 && i != j) {
                for(int k = 1; k < length - j; k++) {
                    output[k+j] = '\0';
                }
            }
        }
        
        fprintf(out, "%s", output);

        free(input);
        free(output);
    }

    fclose(out);
    
    return 0;
}
