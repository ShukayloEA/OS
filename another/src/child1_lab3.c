#include <ctype.h>
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../include/shrmem.h"

char ToLower(char symbol) {
    if (symbol >= 'A' && symbol <= 'Z') {
        symbol = symbol - 'A' + 'a';
    }

    return symbol;
}

int main(void) {
//  printf("in 1 execl\n");
//  if (argc != 1 || argv == NULL){
//    printf("argc1\n");
    
//    return EXIT_FAILURE;
//  }

	int map_fd = shm_open(BackingFile, O_RDWR, AccessPerms);
	if (map_fd < 0) {
		perror("SHM_OPEN");
		exit(EXIT_FAILURE);
	}
  
	struct stat statbuf;
	fstat(map_fd, &statbuf);
	const size_t map_size = statbuf.st_size;
	char * memptr = (char *)mmap(NULL, map_size, PROT_READ | PROT_WRITE, MAP_SHARED, map_fd, 0);
	
	if (memptr == MAP_FAILED) {
    	perror("MMAP");
    	exit(EXIT_FAILURE);
	}

	//Открываем семафор от Парента
//	printf("c1 mmap\n");
	sem_t *semptrToC1 = sem_open(SemaphoreNameToC1, 0);
	if (semptrToC1 == SEM_FAILED) {
		perror("SEM_OPEN");
		exit(EXIT_FAILURE);
	}
//	printf("Sem ToC1 Open\n");

	sem_wait(semptrToC1);		
//	sem_t *semptrToC1 = sem_open(SemaphoreNameToC1, O_RDWR, AccessPerms, 2);
//	printf("c1 sem open\n");

	char *string = (char *)malloc(map_size * sizeof(char));
	//Освобождаем семафор Предка
	sem_post(semptrToC1);
	sem_close(semptrToC1);

	//Создаем семафор к потомку 2 и блокируем его
	sem_t *semptrToC2 = sem_open(SemaphoreNameToC2, O_CREAT, AccessPerms, 1);
	if (semptrToC2 == SEM_FAILED) {
		perror("SEM_OPEN");
		exit(EXIT_FAILURE);
	}
//	printf("Sem ToC2 Open 1\n");

	//Запускаем фторого потомка
//	printf("before fork\n");
	int pid2;
	pid2 = fork();
    if (pid2 == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    }
    else if (pid2 == 0) {
//		printf("before c2\n");
		munmap(memptr, map_size);
		close(map_fd);
//		sem_close(semptr);
		//printf("before 1 execl\n");
//		char* argv2[2];
//      	argv2[0] = "child2_another";
//      	argv2[1] = NULL;

		execl(getenv("PATH_TO_C2"), "child2_another", NULL);
		perror("execv");
    	exit(EXIT_FAILURE);
	}

	//Выполняем преобразование в памяти
//printf("1: map_size=%d\n", (int)map_size);
	size_t i;
	for (i = 0; i < map_size; ++i) {
    //преобразование
		string[i] = ToLower(memptr[i]);
	}
	memcpy(memptr, (void *)string, map_size);
	free(string);
	//close(map_fd);

	//Освобождаем семафор Потомка 2
	sem_post(semptrToC2);
//	printf("Sem ToC2 POST\n");

	return EXIT_SUCCESS;
}