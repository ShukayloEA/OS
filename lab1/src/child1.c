#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <ctype.h>
#include "utils.h"

char to_lower(char symbol) {
    if (symbol >= 'A' && symbol <= 'Z') {
        symbol = symbol - 'A' + 'a';
    }

    return symbol;
}

int main(void) {
    char* input;

    int strLength = 0;

    while ((input = ReadString(stdin)) != NULL) {
        strLength = strlen(input);
        for (int i = 0; i < strLength; i++) {
            input[i] = to_lower(input[i]);
        }
	write(1, input, strlen(input));

    free(input);
    }

    fclose(stdout);

    return 0;
}
