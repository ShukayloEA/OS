#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../include/shrmem.h"


int main(void) {
 
// 	printf("in 2 execl\n");

	int map_fd = shm_open(BackingFile, O_RDWR, AccessPerms);
	if (map_fd < 0) {
		perror("SHM_OPEN");
		exit(EXIT_FAILURE);
	}
//	printf("shm\n");
	struct stat statbuf;
	fstat(map_fd, &statbuf);
	const size_t map_size = statbuf.st_size;
	char * memptr = mmap(NULL, map_size, PROT_READ | PROT_WRITE, MAP_SHARED, map_fd, 0);
	if (memptr == MAP_FAILED) {
		perror("MMAP");
		exit(EXIT_FAILURE);
	}

	//Открываем семафор от Потомка1
//	printf("c2 mmap\n");
	sem_t *semptrToC2 = sem_open(SemaphoreNameToC2, 0);
	if (semptrToC2 == SEM_FAILED) {
		perror("SEM_OPEN");
		exit(EXIT_FAILURE);
	}
//	printf("Sem ToC2 Open\n");
	sem_wait(semptrToC2);
//	printf("Sem ToC2 wait\n");

	//Открываем семафор к предку и освобождаем его
//	printf("Open ToP\n");
	sem_t *semptrToP = sem_open(SemaphoreNameToP, 0);
	if (semptrToP == SEM_FAILED) {
		perror("SEM_OPEN");
		exit(EXIT_FAILURE);
	}

	//Читаем и преобразовываем данные в памяти
	char *out = (char *)malloc(map_size*sizeof(char));
//printf("map_size=%d\n", (int)map_size);
	memcpy(out, memptr, map_size);
	
	int size = map_size;
//	FILE *f1 = fopen("1.txt", "wb");
//	fwrite(out, sizeof(char), size, f1);
//	fclose(f1);

	int i = 0;
	while (i+1 < size) {
		if (out[i] == ' ') {
    	  int j = i + 1;
	      while (out[j] == ' ') {
    	    j++;
      	  }
	      if (j != i+1) {
    	    //Пора чистить
        	int k = j - i - 1;
        	while (j <= size) {
          		out[j-k] = out[j];
          		j++;
        	}
        	size -= k;
      	  }
    	}
    	i++;
  	}

//	FILE *f2 = fopen("2.txt", "wb");
//	fwrite(out, sizeof(char), size, f2);
//	fclose(f2);
	
//	size_t m_size = 0;

	int res = ftruncate(map_fd, (off_t)size);
	//memset(memptr, '\0', m_size);
	memcpy(memptr, out, size);
	free(out);

//	printf("Free to P\n");
	sem_post(semptrToP);
//	printf("Close to C2\n");
	sem_close(semptrToC2);

	return EXIT_SUCCESS;
}
