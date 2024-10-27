#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int data;
    unsigned nfilho;
    struct node *filhos[100000];
    struct node *pai;
} node;

void inicializa(struct node *raiz, int data);
void link(struct node *A, struct node *B);
void cut(struct node *A);
int lca(struct node *A, struct node *B, int N);

int main() {

    int N, M;
    char op[20];

    scanf("%d %d", &N, &M);

    struct node *raiz = (struct node*) malloc(N * sizeof(struct node));

    int i,j;

    for(j = 1, i = 0; i < N; i++, j++) {
        inicializa(&raiz[i], j);  //laco para criar todos os nós das arvores
    }

    int A, B;

    for(int i = 0; i < M; i++) {
        scanf("%s", op);

        if(strcmp(op, "link") == 0) {
            scanf("%d %d", &A, &B);
            A--;
            B--; //diminuicao em 1 para acertar os indices
            link(&raiz[A], &raiz[B]);
        }
        else if(strcmp(op, "cut") == 0) {
            scanf("%d", &A);
            A--;
            cut(&raiz[A]);
        }
        else {
            scanf("%d %d", &A, &B); 
            A--;
            B--;
            int ancestral = lca(&raiz[A], &raiz[B], N);
            printf("%d\n", ancestral);
        }
    }
        free(raiz);

    return 0;
}

void inicializa(struct node *raiz, int data) {

    raiz->data = data;
    raiz->nfilho = 0;
    raiz->pai = NULL;

}

void link(struct node *A, struct node *B) {
    
    A->pai = B;
    B->filhos[B->nfilho] = A;
    B->nfilho++;   //para linkar, coloca o B como pai de A e aumenta o n de filhos em 1

}

void cut(struct node *A) {
    
    A->pai->nfilho--;
    A->pai->filhos[A->pai->nfilho] = NULL; //para cortar define o filho do pai de A como NULL e diminui o numero de filhos
    A->pai = NULL;
}

int lca(struct node *A, struct node *B, int N) {
    
    int *v1 = (int*) malloc(N * sizeof(int));
    int *v2 = (int*) malloc(N * sizeof(int)); //cria vetores para armazenar todos os ancestrais, podendo ser no maximo tamanho N

    int qtd1, qtd2;
    qtd1 = qtd2 = 0;
    int i;

    struct node *n1 = A;
    struct node *n2 = B;

    for(i = 0; n1 != NULL; i++) {
        v1[i] = n1->data;
        n1 = n1->pai;   //armazena os ancestrais de A ,incluindo A, em um vetor v1
        qtd1++;
    }

    for(i = 0; n2 != NULL; i++) {
        v2[i] = n2->data;  //armazena os ancestrais de B,incluindo B, em um vetor v2
        n2 = n2->pai;
        qtd2++;
    }

    for(i = 0; i < qtd1; i++) {
        for(int j = 0;j < qtd2; j++) {
            if(v1[i] == v2[j]) {   //compara ambos os vetores e retorna o primeiro elemento em comum, menor ancestral em comum
                int ancestral = v1[i];
                free(v2);
                free(v1);
                return ancestral;
            }
        }
    }
  
    return 0;
}
