#include"token.h"

int TokenList_init(TokenList* tl) {
	tl->length = 0;
	tl->size = sizeof(Token);
	tl->data = malloc(tl->size);
	return tl->data == 1;
}

int TokenList_realloc(TokenList* tl) {
	Token* new_data = realloc(tl->data, tl->size * 2);
	if (new_data == NULL) return 1;
	tl->data = new_data;
	tl->size *= 2;
	return 0;
}

int TokenList_push(TokenList* tl, Token t) {
	if (tl->length * sizeof(t) >= tl->size)
		if (TokenList_realloc(tl))
			return 1;
	tl->data[tl->length] = t;
	tl->length++;
	return 0;
}

Token TokenList_at(TokenList* tl, size_t i) {
	return tl->data[i];
}

void TokenList_free(TokenList* tl) {
	if (tl->data) free(tl->data);
}