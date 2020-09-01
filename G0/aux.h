#ifndef AUX_H
#define AUX_H


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int fill(int *vetor, int size, int value);

int find(int *vetor, int size, int value);

#endif