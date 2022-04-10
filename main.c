#include<stdlib.h>
#include<stdio.h>

#include"argreader.h"
#include"keywords.h"
#include"token.h"

int main(int n, char** v) {
	tlas_args_t a;
	readargs(n, v, &a);

	return 0;
}