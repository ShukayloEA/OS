#include "parent.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Parent(getenv("PATH_TO_CHILD1"), getenv("PATH_TO_CHILD2"), stdin);
    return 0;
}
