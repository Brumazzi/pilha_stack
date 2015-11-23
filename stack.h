	#include <malloc.h> // biblioteca com função de alocação de memoria
/* 
 * A definição serve para não ter duplicação na inserção do codigo
 * O "#ifndef" e "#define" Podem ser substituidos por "#pragma once"
 */
#ifndef __STACK__ /* Verifica se existe a definição "__STACK__" */
	#define __STACK__ /* Cria a definição "__STACK__" */

	typedef struct _stack{ /* Criação da estrutura da pilha */
		void *data; /* Variavel de armazenamento na pilha */
		struct _stack *next; /* Proximo valor da pilha */
	}stack;

	extern int stack_push(void *data, stack **stk){ /* Essa função insere valores na pilha*/
		stack *_new = malloc(sizeof(stack)); // Aloca memoria necessaria da pilha na variavel _new
		if(!_new) // "!_new" é a mesma coisa que "_new == 0"
			return -1; // retorna -1 casso não tenha allocado o valor em variavel _new

		_new->data = data; // acrescenta o valor na pilha
		/* Este block irá fazer a troca dos valores (empilhagem) */
		_new->next = (*stk); /* o topo da pilha esta indo para a proxima posição */
		(*stk) = _new; /* (*stk) ou a pilha esta recebendo um novo topo */

		return 0;
	}

	extern int stack_pop(stack **stk){/* Essa função, retira os valores da pilha */
		if(!(*stk)) // caso a pilha esteja vazia "(*stk) == 0" retorna -1
			return -1;

		stack *_del = (*stk); // separa o topo da pilha para ser removido
		(*stk) = (*stk)->next; // desempilha o valor da pilha

		free(_del); // desaloca da memoria o antigo topo da pilha

		return 0;
	}

	extern void *stack_get(stack *stk){ /* retorna o topo da pilha */
		return stk->data;
	}

	extern unsigned int *stack_count(stack *stk){ /* conta quantos valores estão na pilha */
		unsigned int count = 0; // Contador
		stack *swap = stk; // variavel para se fazer a contagem

		while(swap){
			count++;
			swap = swap->next; // vai para a proxima posição da pilha
		}

		return count;
	}

#endif /* Fim da definição */
