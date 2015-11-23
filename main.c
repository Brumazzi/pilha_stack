/*
*
* Autor: Daniel B. Brumazzi
*
*/

#include <stdio.h>
#include "stack.h"

int main(int argc, char **argv){
	stack *s = NULL; // cria uma pilha vazia;

	int *inteiro;
	char *texto;

	stack_push(5, &s); // empilha um inteiro
	stack_push("Menssagem de texto", &s); // empilha um texto

	printf("%s\n",stack_get(s));	// escreve o topo
	stack_pop(&s);			// desempilha o topo
	printf("%i\n",stack_get(s));	// escreve o topo
	stack_pop(&s);			// desempilha o topo

	if(!s) // condição se a pilha estiver vazia
		puts("Pilha vazia!");

	return 0;
}
