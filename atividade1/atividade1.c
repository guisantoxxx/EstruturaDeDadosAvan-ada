
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct coordenadas {
        long int linha, coluna, dados;
    } Coordenadas;

    typedef struct csr {
        long int A;
        long int C;
    } CSR;


    typedef struct procura {
        long int linha,coluna;
    } Procura;

    void ordenar(Coordenadas c[], long int qtd);//funcao de ordenacao das coordenadas
    int busca(long int linha, long int coluna, CSR c[], long int R[], long int maior_linha, long int maior_coluna); //funcao de busca no CSR

    int main() {

        long int k, i;
        long int maior_linha, maior_coluna;

        scanf("%ld", &k);

        Coordenadas *c = (Coordenadas*)malloc(k * sizeof(Coordenadas)); //primeira alocacao
        CSR *C = (CSR*)malloc(k * (sizeof(CSR)));  //segunda alocacao
        Procura *p = (Procura*)malloc(100000 * sizeof(Procura));//terceira alocacao

        for(i = 0; i < k; i++) {                                          //leitura das coordenadas e dados
            scanf("%ld %ld %ld", &c[i].linha, &c[i].coluna, &c[i].dados);
        }

        ordenar(c, k);

        maior_linha = c[k - 1].linha;
        maior_coluna = 0;

        for(i = 0; i < k; i++) {
            if(maior_coluna < c[i].coluna) {
                maior_coluna = c[i].coluna;
            }
        }

        long int *R = (long int*)malloc((maior_linha + 2) * sizeof(long int)); //quarta alocacao (do R)

        R[0] = 0;
        int flag = 0;
        long int cont = 0;

        for(i = 0; i < k; i++) {
            C[i].A = c[i].dados; //atribui os dados de A e C
            C[i].C = c[i].coluna; 
        }

        

        for(long int j = 1, i = 0; j < c[k - 1].linha + 2; i++) {  //atribui os valores de R
    
            if(flag == 1) {
                long int valor = c[i].linha - c[i - 1].linha; //e calculado a qtd de linhas puladas, e o cont e atribuido a todas elas

                while(valor != 1) {
                    valor--;
                    R[j] = cont;
                    j++;
                }
                flag = 0;
            }
            
            if(c[i + 1].linha - c[i].linha != 0) {
                cont++;
                R[j] = cont;
                j++;
                
                if(c[i + 1].linha - c[i].linha > 1) {
                    flag = 1; //caso uma linha seja pulada, flag = 1
                }      
            }
            else {
                cont++;
            }
        }

        for(flag = 0, i = 0; flag == 0; i++) {
            scanf("%ld %ld", &p[i].linha, &p[i].coluna);  //leitura das coordenadas a serem procuradas

            if(p[i].coluna == -1) {
                flag =  1;
            }
        }

        
        for(i = 0; p[i].coluna != -1; i++) {
            printf("(%ld,%ld) = %d\n", p[i].linha, p[i].coluna, busca(p[i].linha, p[i].coluna, C, R,maior_linha, maior_coluna));
        }

        free(C);
        free(c);  //desalocacao dos vetores
        free(p);
        free(R);

        return(0);
    }

    void ordenar(Coordenadas c[], long int qtd) { //algoritmo para ordenar as coordenas por linha e depois por coluna
        int i, j;
        int aux;

        for(i = 0; i < qtd - 1; i++) {
            for(j = 0; j < qtd - 1 - i; j++) {
                if(c[j].linha > c[j + 1].linha) {
                    aux = c[j].linha;
                    c[j].linha = c[j + 1].linha;
                    c[j + 1].linha = aux;

                    aux = c[j].coluna;
                    c[j].coluna = c[j + 1].coluna;
                    c[j + 1].coluna = aux;

                    aux = c[j].dados;
                    c[j].dados = c[j + 1].dados;
                    c[j + 1].dados = aux;
                }

                else if(c[j].linha == c[j + 1].linha) {
                    if(c[j].coluna > c[j + 1].coluna) {
                        aux = c[j].linha;
                        c[j].linha = c[j + 1].linha;
                        c[j + 1].linha = aux;

                        aux = c[j].coluna;
                        c[j].coluna = c[j + 1].coluna;
                        c[j + 1].coluna = aux;

                        aux = c[j].dados;
                        c[j].dados = c[j + 1].dados;
                        c[j + 1].dados = aux;
                    }
                }
            }
        }
    }

    

    int busca(long int linha, long int coluna, CSR c[], long int R[], long int maior_linha, long int maior_coluna) { //algoritmo de busca das coordenadas na matriz esparsa
        
        if(linha > maior_linha || coluna > maior_coluna) {
            return 0;
        }

        int comeco = R[linha]; //comeco na linha da procura
        int fim = R[linha + 1]; //fim na proxima linha

       

        for(int i = comeco; i < fim; i++) {
            if(c[i].C == coluna) { //caso a coluna seja correspondente, o numero fpi encontrado,visto que esta sempre na mesma linha
                return c[i].A; //retorna o valor encontrado
            }
        }
        return 0;
    }

