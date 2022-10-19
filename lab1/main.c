#include "parent.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char fileOutName[256];
    fscanf(stdin, "%s\n", fileOutName);

    FILE* out = fopen(fileOutName, "w");
    if (!out) {
        printf("Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    Parent(getenv("PATH_TO_CHILD1"), getenv("PATH_TO_CHILD2"), stdin, out);

    fclose(out);

    return 0;
}
