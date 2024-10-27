#include <stdio.h>
#include <stdlib.h>

struct graph {
    int V;
    int A;
    int **adj;
};

typedef struct graph Graph;

void inicializar(Graph *g, int vertices);
void destroi(Graph *g);
void adicionaAresta(Graph *g, unsigned i, unsigned j);
void DFS(Graph *g, int *ciclico, unsigned d[], unsigned t[], unsigned v[]);
void DFSPrivate(Graph *g, int vis[], unsigned i, int caminho[], int *ciclico, unsigned d[], unsigned t[], unsigned v[]);
void swap(unsigned v[], unsigned a,unsigned b);
void bubbleSort(unsigned v[], unsigned v1[], unsigned v2[], unsigned n);


unsigned tempo = 0;


int main() {

    int Vertices;

    scanf("%d", &Vertices);

    Graph G;

    inicializar(&G, Vertices);

    int i, j;

    i = j = 0;

    while(1) {
        

        scanf("%d,%d", &i, &j);

        if(i == 0 && j == 0) {
            break;
        }

        

        adicionaAresta(&G, i - 1, j - 1);
    }

    int ciclico = 0;

    unsigned *descoberta = (unsigned*)malloc(sizeof(unsigned) * Vertices); //vetor p/ tempo de descoberta
    unsigned *termino = (unsigned*)malloc(sizeof(unsigned) * Vertices);  //vetor p/ tempo de termino
    unsigned *indice = (unsigned*)malloc(sizeof(unsigned) * Vertices); //vetor para salvar os indices dos vertices

    for(i = 0; i < Vertices; i++) {
        indice[i] = i ;
        descoberta[i] = 0; 
        termino[i] = -1;
    }


    DFS(&G, &ciclico, descoberta, termino, indice);

    bubbleSort(descoberta, termino, indice, Vertices); //ordenando os vetores por ordem de descoberta

    for(i = 0; i < Vertices; i++) {
        printf("%d ", indice[i] + 1);
        printf("[%d,%d]\n", descoberta[i], termino[i]);
      
    }

    printf("aciclico: ");

    if(ciclico == 1) {
        printf("nao\n");
    }
    else {
        printf("sim\n");
    }

    free(descoberta);
    free(termino);
    free(indice);
    destroi(&G);

    return 0;
}

void inicializar(Graph *g, int vertices) {
    g->A = 0;
    g->V = vertices;
    g->adj = (int**)malloc(sizeof(int*) * vertices);

    for(unsigned i = 0; i < vertices; i++) {
        g->adj[i] = (int*)malloc(sizeof(int)*vertices);
        for(unsigned u = 0; u < vertices; u++) {
            g->adj[i][u] = 0;
        }
    }
}

void destroi(Graph *g) {
    for(unsigned i = 0; i < g->V; i++) {
        free(g->adj[i]);
    }

    free(g->adj);
}

void adicionaAresta(Graph *g, unsigned i, unsigned j) {
    if(g->adj[i][j] == 0) {
        g->adj[i][j] = 1;
        g->A++;
    }
}

void DFS(Graph *g, int *ciclico, unsigned d[], unsigned t[], unsigned v[]) {
    int *vis = (int*)malloc(sizeof(int) * g->V); //salva os vertices ja visitados
    int *caminho = (int*)malloc(sizeof(int) * g->V); //salva os vertices do caminho atual

    for(unsigned i = 0; i < g->V; i++) {
        vis[i] = 0;
        caminho[i] = 0;
    }

    for(unsigned i = 0; i < g->V; i++) {
        if(vis[i] == 0) {
            
            tempo++; //quando achamos alguem nao visitado, descobrimos ele, tempo aumenta e salva o valor da descoberta
            d[i] = tempo;
            v[i] = i;
            DFSPrivate(g, vis, i, caminho, ciclico, d, t, v);
            tempo++; //quando terminamos de explrar um vertice, aumentamos o tempo e definimos o tempo de termino
            t[i] = tempo;

        }
    }

    free(vis);
    free(caminho);
}

void DFSPrivate(Graph *g, int vis[], unsigned i, int caminho[], int *ciclico, unsigned d[], unsigned t[], unsigned v[]) {
    vis[i] = 1;
    caminho[i] = 1; //o vetor caminho salva aqueles que fazem parte do trajeto percorrido atualmente

    

    for(unsigned u = 0;u < g->V; u++) {
        if(g->adj[i][u] == 1) {
            if(vis[u] == 0) {
                tempo++;
                d[u] = tempo;
                v[u] = u;
                DFSPrivate(g, vis, u, caminho, ciclico, d, t, v);
                tempo++; //ao sair da recursao, nao ha mais arestas,logo a busca termina nesse vertice
                t[u] = tempo;
                caminho[u] = 0; //ao desempilar a recursao, o vertice nao faz mais parte do caminho atual, marcado como 0
            }
            else if(vis[u] == 1) {
                if(caminho[u] == 1) {
                    *ciclico = 1; //se fizer parte do caminho e ja foi visitado, entao Ã© ciclico
                }
            }
        }
    }

    
    caminho[i] = 0; //apos ver todas as arestas do vertice, ele Ã© retirado do caminho
}

void swap(unsigned v[], unsigned a,unsigned b) {
    unsigned aux = v[a];
    v[a] =  v[b];
    v[b] = aux;
}

void bubbleSort(unsigned v[],unsigned v1[], unsigned v2[], unsigned n) {
    if(n < 1) {
        return;
    }

    for(int i = 0; i < n - 1; i++) {
        if(v[i] > v[i + 1]) {
            swap(v, i, i + 1);
            swap(v1, i, i + 1);
            swap(v2, i, i + 1);
        }
    }

    bubbleSort(v, v1, v2, n - 1);
}
