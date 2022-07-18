#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

struct lista {
 	int info;
 	Lista *prox;
};

/* Cria uma lista vazia.*/
Lista* lst_cria(){
 	return NULL;
}

/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l){
 	return (l==NULL);
}

/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista *l, int info){
 	Lista* ln = (Lista*)malloc(sizeof(Lista));
 	ln->info = info;
 	ln->prox = l;
 	return ln;
}

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info){
 	Lista* lAux = l;
 	while(lAux!=NULL){
 		if(lAux->info == info){
			return lAux;
		}
 		lAux = lAux->prox;
 	}
 	return NULL;
}

/* Imprime uma lista.*/
void lst_imprime(Lista *l){
 	Lista* lAux = l;
 	while(lAux!=NULL){
 		printf("Info = %d\n",lAux->info);
 		lAux = lAux->prox;
 	}
}

Lista* lst_remove(Lista *l, int info){
	if(l!=NULL){
 		Lista* lAux = l->prox;
 		if(l->info==info){
 			free(l);
 			return lAux;
 		}
 		else{
 			Lista* lAnt = l;
 			while(lAux!=NULL ){
 				if(lAux->info == info){
 					lAnt->prox = lAux->prox;
 					free(lAux);
 					break;
				}else{
 					lAnt = lAux;
 					lAux = lAux->prox;
 				}
 			} 
 		} 
	}
	return l;
}

/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l){
 	Lista* lProx;
 	while(l!=NULL){
 		lProx = l->prox;
 		free(l);
 		l = lProx;
 	}
}

// COM RECURSIVIDADE
Lista* lst_insere_ordenado(Lista *l, int info){
	Lista *lNew = (Lista*)malloc(sizeof(Lista));
	lNew->info = info;
	if(l==NULL){
 		lNew->prox = NULL;
 		return lNew;
	}else if(l->info>=info){
 		lNew->prox = l;
 		return lNew;
	}else{
 		Lista *lAnt = l;
 		Lista *lProx = l->prox; 
 		while(lProx!=NULL&&lProx->info<info)
 		{ lAnt = lProx;
 			lProx = lProx->prox;
 		}
 		lAnt->prox = lNew;
 		lNew->prox = lProx;
 		return l;
	}
}

void lst_imprime_rec(Lista* l){
	if(lst_vazia(l)){
		return;
	}
	else{
		printf("info: %d\n",l->info);
		lst_imprime_rec(l->prox);
	}
}

void lst_imprime_invertida_rec(Lista* l){
	if(lst_vazia(l)){
		return;
	}else{
		lst_imprime_invertida_rec(l->prox);
		printf("info: %d\n",l->info);
 	}
 }
 
Lista* lst_remove_rec(Lista *l, int info){
	if(!lst_vazia(l)){
		if(l->info==info){
			Lista* lAux = l;
 			l = l->prox;
			free(lAux);
 		}
 		else{
			l->prox = lst_remove_rec(l->prox,info);
		}
	}
	return l; 
}

void lst_libera_rec(Lista *l){
 	if(!lst_vazia(l)){
		lst_libera_rec(l->prox);
		free(l);
 	}
}

int lst_igual_rec(Lista *l1,Lista *l2){
	if(lst_vazia(l1) && lst_vazia(l2)){
		return 1;
	}else if (lst_vazia(l1) || lst_vazia(l2)){
		return 0;
	}else{
		return (l1->info==l2->info && lst_igual_rec(l1->prox,l2->prox));
 	}
}

//~~~~~~~~~~~~~~~~QUESTÃO 01~~~~~~~~~~~~~~~~~~~~~~

//LETRA A)
int menores(Lista* l, int n){
	int contador; 
	if(lst_vazia(l)){
		contador = 0;
	}else{
		while(l!=NULL){ 
 			if(l->info<n){
 				contador++;
			}
			l = l->prox;
 		}
	}
	return contador;
}

//LETRA B)
int soma(Lista* l){
	int somatorio;
	if(lst_vazia(l)){
		return 0;
	}else{
		somatorio = l->info + soma(l->prox);
		return somatorio;
	}
}

//LETRA C)
int num_ndivp(Lista* l, int n){
	int num_ndiv=0;
	if(lst_vazia(l)){	
		return 0;
	}else{
		while(l!=NULL){
			int num_div=0, i;
			for(i=1;i<=l->info;i++){
				if((l->info%i)==0){
					num_div++;
				}
			}
			if(num_div==n){
				num_ndiv++;
			}
			l = l->prox;
		}
		return num_ndiv;
	}
}

//LETRA D)
Lista* lst_conc(Lista* l1, Lista* l2){
	Lista* l3 = lst_cria();
	Lista* l4 = lst_cria();
	if(lst_vazia(l1) || lst_vazia(l2)){
		if(lst_vazia(l1)){
			while(!lst_vazia(l2)){
				l3 = lst_insere(l3,l2->info);
				l2 = l2->prox;
			}
		}else{
			while(!lst_vazia(l1)){
				l3 = lst_insere(l3,l1->info);
				l1 = l1->prox;
			}	
		}		
	}else{
		while(!lst_vazia(l1)){
			l3 = lst_insere(l3,l1->info);
			l1 = l1->prox;
		}
		while(!lst_vazia(l2)){
			l3 = lst_insere(l3,l2->info);
			l2 = l2->prox;
		}
	}
	while(!lst_vazia(l3)){
		l4 = lst_insere(l4,l3->info);
		l3 = l3->prox;
	}
	return l4;
}

//LETRA E)
Lista* lst_diferenca(Lista* l1, Lista* l2){
	if(lst_igual_rec(l1,l2)){
		lst_libera(l1);
		return NULL;
	}else{
		Lista* LProx = l1;
		while(LProx != NULL){
			Lista* LAux1 = lst_busca(l2, LProx->info);
			if(LAux1!=NULL){
				l1 = lst_remove_rec(l1, LProx->info);
				LProx = l1;
			}else{
				LProx = LProx->prox;
			}	
		}
		return l1;
	}
}
