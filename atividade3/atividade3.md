# Percursos

Para fazer esta atividade, você deve:
- Implementar apenas os trechos faltantes de código, indicados por `// implementar`;
- Não alterar qualquer outra parte do código;
- Implementar a fila com alocação dinâmica e encadeamento simples, encapsulada e com o elemento um ponteiro para `void`.

## Problema
Neste problema, você deverá construir uma árvore binária de busca (ABB ou BST) com a sequência de números fornecida. Esta sequência não possui números repetidos. Por exemplo, a sequência de valores: `8 3 10 1 6 4 13 7 14` resulta na seguinte árvore binária de busca:

<img src="Sem%20t%C3%ADtulo.png" alt="arvore binaria">


Em seguida, você deve imprimir os percursos pré-ordem, em-ordem, pós-ordem e em-nível, conforme a especificação abaixo.

### Entrada
A entrada contém apenas um caso de teste. A primeira linha contém um inteiro N (1 ≤ N ≤ 500) que indica a quantidade de números que devem compor cada árvore e a segunda linha contém N inteiros distintos, separados por um espaço em branco.

### Saída
Após construir a árvore binária de busca com os elementos da entrada, você deverá imprimir cada percurso em uma linha, conforme o exemplo abaixo. Separe cada um dos elementos por um espaço em branco e termine cada linha com um `\n`.

### Exemplo

| Entrada | Saída |
| ------- | ----- |
| 9       | Pr.: 8 3 1 6 4 7 10 14 13 |
| 8 3 10 1 6 4 13 7 14 | In.: 1 3 4 6 7 8 10 13 14 |
|         | Po.: 1 4 7 6 3 14 13 10 8 |
|         | N.: 8 3 10 1 6 13 4 7 14 |


