#include "include/parent.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *fileOutName = "out.txt";
//    fscanf(stdin, "%s", fileOutName);

    FILE* out = fopen(fileOutName, "wb");
    if (!out) {
        printf("Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    Parent(stdin, out);

    fclose(out);

    return 0;
}
