#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct lista {
 	int info;
 	Lista *prox;
};

struct pilha{
	Lista *prim;
};

Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	if(p==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
 	}
 	p->prim = NULL;
 	return p;
}

/*Função que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = p->prim;
	p->prim = l;
}

/*Testa se uma pilha é vazia.*/
int pilha_vazia(Pilha *p){
	return p->prim==NULL;
 }

/*Função que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p){
	int a;
	Lista *l;
	if(pilha_vazia(p)){
		printf("Pilha Vazia!!!\n");
		exit(1); 
	}
	l = p->prim;
	a = l->info;
	p->prim = l->prox;
	free(l);
	return a;
}

/*Função que imprime os elementos de uma pilha.*/
void pilha_imprime(Pilha *p){
	Lista *lAux = p->prim;
	while(lAux!=NULL){
 		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

/*Libera o espaço alocado para uma pilha.*/
void pilha_libera(Pilha *p){
	Lista* l = p->prim;
	Lista* lAux;
	while(l!=NULL){
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(p);
}

//~~~~~~~~~~~~QUESTÃO 02~~~~~~~~~~~~~~~~
//LETRA A)
Pilha* inverte_pilha(Pilha* p){
	Pilha* p1 = pilha_cria();
	while(!pilha_vazia(p)){
		pilha_push(p1, p->prim->info);
		p->prim = p->prim->prox;
	}
	return p1;
}

//LETRA B)
Pilha* empilha_elem_comuns(Lista* l1, Lista* l2){
	Pilha* p = pilha_cria();
	Lista* l3 = lst_cria();
	if(lst_igual_rec(l1,l2)){
		while(!lst_vazia(l1)){
			l3 = lst_insere_ordenado(l3, l1->info);
			l1 = l1->prox;
		}
	}else{
		Lista* lAux = l1;
		while(lAux != NULL){
			Lista* lBusca = lst_busca(l2, lAux->info);
			if(lBusca != NULL){
				l3 = lst_insere_ordenado(l3, lAux->info);
			}
			lAux = lAux->prox;
		}
		while(l3 != NULL){
			pilha_push(p, l3->info);
			l3 = l3->prox;
		}
	}
	return p;	
}
