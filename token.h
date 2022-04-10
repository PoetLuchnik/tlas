#ifndef TOKEN_INCLUDED
#define TOKEN_INCLUDED

#include<stdlib.h>

enum {
	TLAS_NULL = -1,
	TLAS_ID = -2,
	TLAS_LABEL_DEF = -3,
	TLAS_BYTE = -4,
	TLAS_AT_BYTE = -5,
	TLAS_STRING = -6,
};

typedef struct {
	int type;
	char* begin;
	size_t length;
} Token;

typedef struct {
	Token* data;
	size_t length;
	size_t size;
} TokenList;

int TokenList_init(TokenList* tl);
int TokenList_push(TokenList* tl, Token t);
Token TokenList_at(TokenList* tl, size_t i);
void TokenList_free(TokenList* tl);

#endif
