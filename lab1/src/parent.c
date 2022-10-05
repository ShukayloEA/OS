// OS_lab_1_Shukaylo.c
//var 14

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "parent.h"
#include "utils.h"

void Parent(const char *pathToChild1, const char *pathToChild2, FILE* stream)
{
    int pid1, pid2;
    int pipe1[2], pipe2[2], pipe3[2];
    
    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);

    char fileOutName[256];
    fscanf(stream, "%s\n", fileOutName);

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

      char* argv1[1];
      argv1[0] = NULL;

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

      char* argv2[3];
      argv2[0] = "child2";
      argv2[1] = fileOutName;
      argv2[2] = NULL;

      execv(pathToChild2, argv2);
      perror("execv");
      exit(EXIT_FAILURE);
    }
   
    char* input = NULL;
    
    close(pipe1[0]);
    close(pipe3[0]);
    close(pipe3[1]);
    close(pipe2[1]);
    close(pipe2[0]);
    
    while ((input = ReadString(stream)) != NULL) {
        write(pipe1[1], input, strlen(input));
        free(input);
    }
    
    close(pipe1[1]);

    wait(&pid1);
    wait(&pid2);
}
