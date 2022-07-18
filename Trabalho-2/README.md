<h2>2º Trabalho <br>
Curso: Engenharia da Computação <br>
Disciplina: Estruturas de Dados <br>
Universidade Federal do Ceará – UFC/Sobral </h2>
1. Implemente a TAD “arvb.h” (Árvore Binária de Busca) e acrescente as seguintes
funções:<br>
a) função que retorne a quantidade de folhas que possuem o campo info com número
primo. Essa função deve obedecer ao protótipo:
```int folhas_primo(ArvB* a);```

b) função que retorne a quantidade de nós que possuem campos dir e esq diferentes
de NULL. Essa função deve obedecer ao protótipo:

```int subarvs_difnull(ArvB* a);```

c) função que retorne a quantidade de nós cujas subárvores esquerda e direita tenham a
mesma altura. Essa função deve obedecer ao protótipo: 

```int subarvs_ig_alt(ArvB* a);```

d) função que imprima os elementos por níveis. Essa função deve obedecer ao
protótipo: 

```void impressao_arv_niveis(ArvB* a);```

Por exemplo, na árvore da figura abaixo, a impressão deve ser:
6 – nível 0
5, 8 – nível 1
7, 9 – nível 2

A seguir, execute o seguinte programa.
```
#include <stdio.h>
#include <stdlib.h>
#include “arvb.h”
int main(void){
 
 Arv* arvA = arvb_cria_vazia();
 arvA=arvb_insere(arvA,43);
 arvA=arvb_insere(arvA,51);
 arvA=arvb_insere(arvA,21);
 arvA=arvb_insere(arvA,4);
 arvA=arvb_insere(arvA,45);
 arvA=arvb_insere(arvA,29);
 arvA=arvb_insere(arvA,3);
 arvA=arvb_insere(arvA,23);
 arvA=arvb_remove(arvA,4);
 printf(''Nós subarvs dif null %d\n'',subarvs_difnull(arvA));
 printf(''Nós subarvs igual alt. %d\n'',subarvs_ig_alt(arvA));
 printf(''Folhas com val. primos %d\n'',folhas_primo(arvA)); 
 
 printf(''------\n'');
 impressao_arv_niveis(arvA);
 printf(''------\n'');
 arvb_libera(arvA);
 
 system(''PAUSE'');
 return 0;
}
```
2. Implemente os algoritmos BubbleSort, InsertionSort, QuickSort e HeapSort e
calcule o tempo de cada um para ordenar vetores de tamanho 10^3, 10^4, 10^5 e 10^6 com os
elementos dispostos de três formas: crescente, decrescente, e aleatória. Elabore um
pequeno relatório com os dados obtidos (no máximo, com três páginas – formato PDF).
Obs.: O tempo deve ser dado em milissegundos.

<strong>Obs.: Nota nesse trabalho: 9</strong>
