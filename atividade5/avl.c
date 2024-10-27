#include <stdlib.h>
#include "avl.h"

void inicializar( avl* arvore ) {
	arvore->raiz = 0;
}

void destruir_privado( node *p ) {  // Percurso pos ordem, para desalocar todas as subarvores, e sÃ³ depois a raiz
    if(p) {
        destruir_privado(p->esq);

        destruir_privado(p->dir);

        free(p);
    }

}

void destruir( avl* arvore ) {
    destruir_privado(arvore->raiz);
}

node* rotEE( node* A ) { 
       node* B = A->esq;
       A->esq = B->dir;
       B->dir = A;
       A->bal = B->bal = 0;
       return B;
}

node* rotDD( node* A ) {
	    node* B  = A->dir;
        A->dir = B->esq;
        B->esq = A;
        A->bal = B->bal = 0;
        return B;
}

node* rotED( node* A ) {
	    node* B = A->esq;
        node *C = B->dir;
        B->dir = C->esq;
        C->esq = B;
        A->esq = C->dir;
        C->dir = A;
        
        if(C->bal == -1) {
            A->bal = 1;
            B->bal = 0;
            C->bal = 0;
        }
        else if(C->bal == 1) {
            A->bal = 0;
            B->bal = -1;
            C->bal = 0;
        }
        else {
            A->bal = B->bal = 0;
        }

        return C;
}

node* rotDE( node* A ) {
	    node *B = A->dir;
        node *C = B->esq;
        B->esq = C->dir;
        C->dir = B;
        A->dir = C->esq;
        C->esq = A;

        if(C->bal == -1) {
            A->bal = 0;
            B->bal = 1;
            C->bal = 0;
        }
        else if(C->bal == 1) {
            A->bal = 1;
            B->bal = 0;
            C->bal = 0;
        }
        else {
            A->bal = B->bal = 0;
        }

        return C;
}

node* inserir_privado( node* p, int data, int *mudouAltura) {

   
	
	if(!p) {
		node* novo = (node*)malloc(sizeof(node));
		novo->data = data;
		novo->bal = 0;
		novo->dir = novo->esq = 0;
		*mudouAltura = 1;
		return novo;
	}

    

    if(p->data > data) {
        p->esq = inserir_privado(p->esq, data, mudouAltura);

        if(*mudouAltura) {
            if(p->bal == 1) {
                p->bal = 0;
                *mudouAltura = 0;
            }
            else if(p->bal == 0) {
                p->bal = -1;
                *mudouAltura = 1;
            }
            else {
                if(p->esq->bal == -1) {
                    p = rotEE(p);
                    *mudouAltura = 0;
                }
                else if(p->esq->bal == 1) {
                    p = rotED(p);
                    *mudouAltura = 0;
                }
            }
        }
    }
    else if(p->data < data) {
        p->dir = inserir_privado(p->dir, data, mudouAltura);

        if(*mudouAltura) {
            if(p->bal == -1) {
                p->bal = 0;
                *mudouAltura = 0;
            }
            else if(p->bal == 0) {
                p->bal = 1;
                *mudouAltura = 1;
            }
            else {
                if(p->dir->bal == 1) {
                    p = rotDD(p);
                    *mudouAltura = 0;
                }
                else if(p->dir->bal == -1) {
                    p = rotDE(p);
                    *mudouAltura = 0;
                }
            }
        }
        
    }
	return p;
} 



void inserir( avl* arvore, int data) {
	
	int mudouAltura = 0;
	
	arvore->raiz = inserir_privado( arvore->raiz, data, &mudouAltura );
	
}
    
node* teto_privado(node* p, int dado) {
    node* teto;

    teto = NULL;

    while(p) {
        if(p->data == dado) {
            teto = p;
            return teto;
        }
        else if(p->data < dado) {
            p = p->dir;
        }
        else {
            teto = p; //se o dado for menos, o p->data Ã© um valor valido para teto
            p = p->esq;
        }
    }

    return teto;
}

node* piso_privado(node* p, int dado) {
   node* teto = NULL;

   while(p) {
        if(p->data == dado) {
            teto = p;
            return teto;
        }
        else if(p->data > dado) {
            p = p->esq;
        }
        else {
            teto = p;
            p = p->dir;
        }
   }

   return teto;
}


int teto( avl* arvore, int dado, int *teto_dado ) {
    node* c = teto_privado(arvore->raiz, dado);
    if(c) {
        *teto_dado = c->data;
        return 1;
    }
    return 0;
}

int piso( avl* arvore, int dado, int *piso_dado ) {
    node* f = piso_privado(arvore->raiz, dado);
    if(f) {
        *piso_dado = f->data;
        return 1;
    }
    return 0;
}
