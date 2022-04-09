
#include"argreader.h"

const tlas_args_t default_args = {
	.self = "./tlas",
	.input = "./in.tlas",
	.output = "./out.bin",
};

void not_enough_args(size_t i, int n) {
	if (i < n) return;
	printf("expected argument by index %lu but got %i arguments\n", i, n);
	exit(1);
}

void readarg(int n, char** v, fchar_t fc, size_t* i, tlas_args_t* args) {
	switch (fc)
	{
	case FCHAR_INPUT:
		not_enough_args(*i, n);
		args->input = v[*i];
		++* i;
		break;
	case FCHAR_OUTPUT:
		not_enough_args(*i, n);
		args->output = v[*i];
		++* i;
		break;
	default: printf("unknown argument format: %c\n", fc);
		exit(1);
	}
}

void readargs(int n, char** v, tlas_args_t* args) {
	*args = default_args;
	if (n <= 0) return;
	args->self = v[0];
	if (n == 1) return;
	const char* format = v[1];
	size_t argi = 2;
	for (size_t i = 0; format[i]; i++) {
		readarg(n, v, format[i], &argi, args);
	}
}

