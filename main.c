#include<stdlib.h>
#include<stdio.h>

#include"argreader.h"

int main(int n, char** v) {
	tlas_args_t a;
	
	readargs(n, v, &a);

	return 0;
}