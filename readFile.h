#ifndef _READFILE_
#define _READFILE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"


#define N 1000

void printEstruturas();

void populaEstruturas(char*, char*, char*, int, int);

void trataLinha(char*);

void readFile(char*);


#endif