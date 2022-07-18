typedef struct lista Lista;

/* Cria uma lista vazia.*/
Lista* lst_cria(); 

/* Testa se uma lista � vazia.*/
int lst_vazia(Lista *l); 

/* Insere um elemento no in�cio da lista.*/
Lista* lst_insere(Lista *l, int info); 

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info); 

/* Imprime uma lista.*/
void lst_imprime(Lista *l); 

/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info); 

/* Libera o espa�o alocado por uma lista.*/
void lst_libera(Lista *l);

/* Insere um elemento na lista de forma ordemada.*/
Lista* lst_insere_ordenado(Lista *l, int info);

/* Imprime uma lista (usando recursividade).*/
void lst_imprime_rec(Lista* l);

/* Imprime invertido uma lista (usando recursividade).*/
void lst_imprime_invertida_rec(Lista* l);

/* Remove um elemento de uma lista (usando recursividade).*/
Lista* lst_remove_rec(Lista *l, int info);

/* Libera o espa�o alocado por uma lista (usando recursividade).*/
void lst_libera_rec(Lista *l);

/* Verifica se uma lista � igual a outra (usando recursividade)*/
int lst_igual_rec(Lista *l1,Lista *l2);


//~~~~~~~~~~ Fun��es do Trabalho ~~~~~~~~~~~~~~~~~~
// QUEST�O 01

// Letra A
int menores(Lista* l, int n);

// Letra B
int soma(Lista* l);

// Letra C
int num_ndivp(Lista* l, int n);

// Letra D
Lista* lst_conc(Lista* l1, Lista* l2);

// letra E
Lista* lst_diferenca(Lista* l1, Lista* l2);

