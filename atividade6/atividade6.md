# Busca em profundidade

Este trabalho consiste em implementar uma busca em profundidade em um grafo orientado G, que produza a rotulação dos vértices por timestamps e determine se o grafo é ou não acíclico. O grafo deve ser representado por uma lista de adjacências.

A primeira linha da entrada indica o número de vértices em G(V,E). As linhas seguintes representam arestas orientadas (i,j) no formato i,j. Garantidamente 1 <= i,j <= |V|. O fim das arestas é representado por i=0 e j=0.

Para cada entrada seu programa deve imprimir todos os vértices em ordem crescente do tempo de descoberta, como nos dois exemplos abaixo. Uma vez que a DFS não impõe qualquer ordem para para percorrer os vértices ou a vizinhança de um vértice, qualquer ordem produzida por uma DFS válida será aceita. 

## Exemplo

### Entrada

9<br>
1,2<br>
1,6<br>
6,8<br>
7,8<br>
5,7<br>
5,8<br>
9,8<br>
3,1<br>
4,3<br>
6,4<br>
0,0<br>

### Saída

1 [1,12] <br>
6 [2,9]<br>
4 [3,6]<br>
3 [4,5]<br>
8 [7,8]<br>
2 [10,11]<br>
9 [13,14]<br>
5 [15,18]<br>
7 [16,17]<br>
aciclico: nao

## Outro exemplo

### Entrada

6<br>
5,2<br>
2,3<br>
1,6<br>
6,3<br>
1,4<br>
0,0<br>

### Saída

1 [1,8]<br>
4 [2,3]<br>
6 [4,7]<br>
3 [5,6]<br>
2 [9,10]<br>
5 [11,12]<br>
aciclico: sim<br>

