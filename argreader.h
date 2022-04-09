#ifndef ARGREADER_INCLUDED
#define ARGREADER_INCLUDED

#include<stdlib.h>
#include<stdio.h>

typedef struct {
	const char* self;
	const char* input;
	const char* output;
} tlas_args_t;

typedef enum {
	FCHAR_INPUT = 'i',
	FCHAR_OUTPUT = 'o',
} fchar_t;

void readargs(int n, char** v, tlas_args_t* args);

#endif