// OS_lab_1_Shukaylo.c
//var 14

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "parent.h"
#include "utils.h"

void Parent(const char *pathToChild1, const char *pathToChild2, FILE* stream, FILE* out)
{
    int pid1, pid2;
    int pipe1[2], pipe2[2], pipe3[2];
    
    CreatePipe(pipe1);
    CreatePipe(pipe2);
    CreatePipe(pipe3);

    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid1 == 0) {
      /*child1*/
      close(pipe1[1]);
      close(pipe3[0]);
      close(pipe2[0]);
      close(pipe2[1]);
      dup2(pipe1[0], 0);
      dup2(pipe3[1], 1);

      char* argv1[2];
      argv1[0] = "child1";
      argv1[1] = NULL;

      execv(pathToChild1, argv1);
      perror("execv");
      exit(EXIT_FAILURE);
    }
    pid2 = fork();
    if (pid2 == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    }
    else if (pid2 == 0) {
      /*child2*/
      close(pipe3[1]);
      close(pipe2[0]);
      close(pipe1[0]);
      close(pipe1[1]);
      dup2(pipe3[0], 0);
      dup2(pipe2[1], 1);

      char* argv2[2];
      argv2[0] = "child2";
      argv2[1] = NULL;

      execv(pathToChild2, argv2);
      perror("execv");
      exit(EXIT_FAILURE);
    }
   
    char* input = NULL;
    char* output = NULL;
    
    size_t inputSize = 256;
    size_t outputSize = 256;
    
    close(pipe1[0]);
    close(pipe3[0]);
    close(pipe3[1]);
    close(pipe2[1]);
    FILE* outChild2 = fdopen(pipe2[0], "r");
    if (!outChild2) {
        printf("Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    while (getline(&input, &inputSize, stream) != -1) {
        write(pipe1[1], input, strlen(input));
        getline(&output, &outputSize, outChild2);
        fprintf(out, "%s", output);
	    free(input);
	    input = NULL;
        free(output);
	    output = NULL;
    }
    
    close(pipe1[1]);
    close(pipe2[0]);
    fclose(outChild2);
    
    wait(&pid1);
    wait(&pid2);
}
