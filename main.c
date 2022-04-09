#include<stdlib.h>
#include<stdio.h>

#include"argreader.h"
#include"keywords.h"

int main(int n, char** v) {
	tlas_args_t a;
	
	readargs(n, v, &a);

	puts(tlas_kw[TLAS_KW_COMPARE]);

	return 0;
}