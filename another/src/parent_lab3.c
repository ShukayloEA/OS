#include <fcntl.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../include/shrmem.h"
#include "../include/parent.h"

void Parent(FILE* stream, FILE* out)
{
	size_t map_size = 4096;
	char *in = (char *)calloc(map_size, sizeof(char));
	char c;
//	printf("Poops\n");
//	bool work = true;
	int i = 0;
	while ((c = (char)getc(stream)) != EOF) {//} && work) {
//	if ('1' == c){
//		printf("ooops\n");
//		work = false;
//	}
		in[i] = c;
		i++;
//	in = (char *)realloc(in, (++map_size + 1) * sizeof(char));
	}
	
	in[i] = '\0';
	map_size = i;
  //read string stream
	int fd = shm_open(BackingFile, O_RDWR | O_CREAT, AccessPerms);
	if (fd == -1) {
		perror("OPEN");
		exit(EXIT_FAILURE);
	}

	//Создаем семафор для потомка 1 и лочим его
	sem_t *semptrToC1 = sem_open(SemaphoreNameToC1, O_CREAT, AccessPerms, 1);
	if (semptrToC1 == SEM_FAILED) {
		perror("SEM_OPEN");
		exit(EXIT_FAILURE);
	}
//	printf("Sem ToC1 Open 1\n");
//	sem_unlink (SemaphoreNameToC1);

	//Создаем семафор ОТ потомка 2
	sem_t *semptrToP = sem_open(SemaphoreNameToP, O_CREAT, AccessPerms, 1);
//		sem_t *semptrToP = sem_open(SemaphoreNameToP, 0);
	if (semptrToP == SEM_FAILED) {
		perror("SEM_OPEN");
		exit(EXIT_FAILURE);
	}
//	printf("Sem ToP Open 1\n");


	ftruncate(fd, (off_t)map_size);
	caddr_t memptr = (caddr_t)mmap(NULL, map_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (memptr == MAP_FAILED) {
		perror("MMAP");
		exit(EXIT_FAILURE);
	}

	//Создаем потомка
	int pid1;
	pid1 = fork();
	if (pid1 == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid1 == 0) {
		munmap(memptr, map_size);
		close(fd);
//		sem_close(semptr);
	//printf("before 1 execl\n");
//		char* argv1[2] = {"child1_another", NULL};
//      	argv1[0] = "child1_another";
//      	argv1[1] = NULL;

		execl(getenv("PATH_TO_C1"), "child1_another", NULL);
		perror("execv");
    	exit(EXIT_FAILURE);
	}

	//Копируем данные в разделяемую память
//	printf("p mmap\n");
	memcpy(memptr, in, map_size);

	free(in);

	//Освобождаем семафор
	sem_post(semptrToC1);
//	printf("Sem ToC1 POST\n");

	//Ждем потомка 2
	sem_wait(semptrToP);	
//	printf("Final!!!\n");

	close(fd);

	fd = shm_open(BackingFile, O_RDWR, AccessPerms);
	if (fd < 0) {
		perror("SHM_OPEN");
		exit(EXIT_FAILURE);
	}
	struct stat statbuf;
	fstat(fd, &statbuf);
	map_size = statbuf.st_size;
	memptr = mmap(NULL, map_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (memptr == MAP_FAILED) {
		perror("MMAP");
		exit(EXIT_FAILURE);
	}

	//Читаем от него данные
	fwrite(memptr, sizeof(char), map_size, out);
//	sem_post(semptrToP);


	sem_close(semptrToP);
}