#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _bst {
    struct _bst* l;
    struct _bst* r;
    char* str;
} bst;

bst* get(bst* root, char* str) {

    int flag = 0;

    while(root != NULL) {
        int cmp = strcmp(root->str, str);

        if(cmp > 0) {  //se a raiz for maior que o key, key vai para a direita
            root = root->l;
        }
        else if(cmp < 0) { //se a raiz for menor que o key, key vai para a esq
            root = root->r;
        }
        else { // se o root->key for igual a key, retorna root key
            flag = 1;
            break;
        }
    }

    if(flag == 1) {
        return root;
    }
    else {
        return NULL;
    }
}

bst* put(bst* root, char* str) {
    if(root) {
        int cmp = strcmp(root->str, str);
        if(cmp > 0)
            root->l = put(root->l,str);
        else if (cmp < 0)
            root->r = put(root->r,str);
        return root;
    } else {
        bst* novo = (bst*)malloc(sizeof(bst));
        novo->str = (char*)malloc(sizeof(char)*(strlen(str)+1));
        strcpy(novo->str,str);
        novo->l = novo->r = NULL;
        return novo;
    }
}

bst* max(bst* root) {
    if(root == NULL) {  //procura sempre descer para o elemento da direita, afim de encontrar o maior
        return NULL;
    }
    else if(root->r == NULL) {
        return root;
    } 
    else {
        return max(root->r);
    }
}

bst* min(bst* root) { //procura sempre descer para oelemento da esquerda, afim de encontrar o menor
if(root == NULL) {
        return NULL;
    }
    else if(root->l == NULL) {
        return root;
    }
    else {
        return min(root->l);
    }
}

bst* rem(bst* root, char* str) {

    if(root == NULL) {
        return root;
    }

    int cmp = strcmp(root->str, str);

    if(cmp > 0) {
        root->l = rem(root->l, str); 
    }
    else if(cmp < 0) {
        root->r = rem(root->r, str);
    }
    else {
        if(root->l == NULL) {
            bst* aux = root->r;
            free(root->str);
            free(root);
            return aux;
        }
        else if(root->r == NULL) {
            bst* aux = root->l;
            free(root->str);
            free(root);
            return aux;
        }
        else {
            bst* sucessor = min(root->r); //acha o minimo da subarvore da direita para trocar              
            free(root->str);
            root->str = (char*)malloc( (strlen(sucessor->str) + 1) * sizeof(char));  //realoco a string da raiz para poder caber a do sucessor
            strcpy(root->str, sucessor->str);
            root->r = rem(root->r, sucessor->str);
        }
    }

    return root;
}

void del(bst* root) {
    if(root) {
        del(root->l);
        del(root->r);
        free(root->str);
        free(root);
    }
}

int main() {

    char comando[2], palavra[255];

    bst* raiz = NULL;

    while(scanf("%s", comando) != EOF) {
        scanf("%s", palavra);
        if( comando[0] == 'P' ) 
            raiz = put(raiz,palavra);
        else if( comando[0] == 'R' ) 
            raiz = rem(raiz,palavra);
        else if( comando[0] == 'G' ) {
            bst* result = get(raiz,palavra);
            if( result )
                printf("%s encontrada\n", result->str);
            else
                printf("%s nao foi encontrada\n", palavra);
        }
    }

    del(raiz);

    return 0;
}
