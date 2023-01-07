#ifndef SRC__SHRMEM_H_
#define SRC__SHRMEM_H_

#include <fcntl.h>

const char *BackingFile = "os_lab4.back";
const char *SemaphoreNameToC1 = "os_lab4.semaphoreToC1";
const char *SemaphoreNameToC2 = "os_lab4.semaphoreToC2";
const char *SemaphoreNameToP = "os_lab4.semaphoreToP";
unsigned AccessPerms = S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH;

#endif
