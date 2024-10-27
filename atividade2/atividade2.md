# Menor Ancestral Comum (LCA)

O Menor Ancestral Comum (LCA, do inglês *Lowest Common Ancestor*) de dois vértices `A` e `B` em uma árvore `T` é o menor nó de `T` (em profundidade) que possui os nós `A` e `B` como seus descendentes. Define-se que o nó `A` é descendente dele próprio. (Então, caso `A` seja filho de `B` em `T`, `B` é o LCA de `A` e `B`). [Fonte: Wikipedia]

Inicialmente, a floresta consiste de `N` árvores enraizadas, cada uma com exatamente um nó (rotulados de `1` a `N`).
Considere as seguintes operações:

- `link A B`: adiciona uma aresta do nó `B` para o `A`, fazendo com que `A` seja filho de `B` na árvore de `B`. Inicialmente, `A` é um nó raiz, e `A` e `B` estão em diferentes árvores.
- `cut A`: remove a aresta que liga o nó pai de `A` com `A`. Inicialmente, `A` não é um nó raiz.
- `lca A B`: imprime o Menor Ancestral Comum de `A` e `B`. Nesse caso, `A` e `B` estão na mesma árvore.

Veja o exemplo de estrutura abaixo:
    
                  1
                /
              2
            /
          3
        /  \
      4     5


O resultado da operação `lca 4 5` é `3`.

## Problema

Neste problema, você deve calcular o Menor Ancestral Comum entre dois nós `A` e `B`. Considere que `A` e `B` sempre fazem parte da mesma árvore, ou seja, existe um Ancestral Comum entre eles.

### Especificação de Entrada e Saída

#### Entrada

A primeira linha da entrada contém dois inteiros, `N` e `M`, onde:
- `N` é o número de árvores da floresta inicial.
- `M` é o número de operações (1 ≤ N, M ≤ 1000).

Em seguida, há `M` linhas, cada uma com uma operação.

#### Saída

Para cada operação `lca A B`, você deve imprimir o Menor Ancestral Comum entre os nós `A` e `B`.

### Exemplo de Entrada

5 9 <br>
lca 1 1<br>
link 1 2<br>
link 3 2<br>
link 4 3<br>
lca 1 4<br>
lca 3 4<br>
cut 4<br>
link 5 3<br>
lca 1 5<br>

### Exemplo de Saída

1
2
3
2
