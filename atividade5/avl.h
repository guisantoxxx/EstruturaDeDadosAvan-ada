#ifndef AVL_H
#define AVL_H

struct node_ {
	int data;
	char bal; // na verdade precisamos de 2-bits
	struct node_ *dir, *esq;
};

typedef struct node_ node;

typedef struct {
	node* raiz;
} avl;


// funÃ§Ãµes pÃºblicas

void inicializar( avl* arvore ); // inicializa uma Ã¡rvore jÃ¡ alocada pelo usuÃ¡rio
void destruir( avl* arvore ); // desaloca toda memÃ³ria alocada pelas funÃ§Ãµes pÃºblicas

void inserir( avl* arvore, int data ); // insere data na Ã¡rvore, sem repetiÃ§Ã£o

int teto( avl* arvore, int dado, int *teto_dado ); // Se o teto existir, retorna 1 e em teto_dado o teto de dado. Caso contrÃ¡rio, retorna 0 (falso).
int piso( avl* arvore, int dado, int *piso_dado ); // Se o piso existir, retorna 1 e em piso_dado o piso de dado. Caso contrÃ¡rio, retorna 0 (falso).

#endif
