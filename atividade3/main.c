#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node_ {
	int data;
	struct node_ *dir, *esq;
} node;

node* inserir( node* p, int dados ) {
    if(!p) {
		node *n = (node*) malloc(sizeof(node));
		n->data = dados;
		n->dir = n->esq = 0;
		return n;
	}
	else if(p->data > dados) {
		p->esq = inserir(p->esq, dados);
	}
	else if(p->data < dados) {
		p->dir = inserir(p->dir, dados);
	}

	return p; //restaurar o endereÃ§o da raiz
}

void destruir( node *p ) {
    if(p) {
        destruir(p->esq);

        destruir(p->dir);

        free(p);
    }

    return;
}

void pos_order( node *p, void (*process)(int dado) ) {
    if(p) {
		pos_order(p->esq, process);

		pos_order(p->dir, process);

		process(p->data);
	}

	return;
	
}

void pre_order( node *p, void (*process)(int dado) ) {
    if(p) {
		process(p->data);

		pre_order(p->esq, process);

		pre_order(p->dir, process);
	}

	return;
}

void in_order( node *p, void (*process)(int dado) ) {
    if(p) {
		in_order(p->esq, process);

		process(p->data);

		in_order(p->dir, process);
	}

	return;
	
}

void in_level( node *p, void (*process)(int dado) ) {
	queue q;
    initialize(&q);
	
	push(&q, p); //comeca pela raiz

	while(!empty(&q)) {  //adiciona os filhos do primeiro da fila,depois o printa e o remove
		
        node *n = front(&q);  
        
        if(n->esq != 0) {
			push(&q, n->esq);
		}
		
		if(n->dir != 0) {
			push(&q, n->dir);
		}
		
		process(n->data);
		pop(&q);    

	}

}

void print(int dado) {
	printf(" %d", dado);
}

int main() {	

	int n,a;
	scanf("%d", &n);
	
	node* raiz = 0;
	
	for(int i=0;i<n; i++) {
		scanf("%d", &a);
		raiz = inserir(raiz,a);
	}

	
	printf("Pr.:");
	pre_order(raiz, print);
	printf("\n");
	printf("In.:");
	in_order(raiz, print);
	printf("\n");
	printf("Po.:");
	pos_order(raiz, print);
	printf("\n");
	printf("Ni.:");
	in_level(raiz, print);
	printf("\n");
	
	destruir(raiz);
  
	
	return 0;
}
