#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"

struct lista{
	int info;
	Lista *prox;
};

struct fila{
	Lista *ini;
	Lista *fim;
};

Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

void fila_insere(Fila *f, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = NULL;
	if(!fila_vazia(f)){
		f->fim->prox = l;
	}else{
		f->ini = l;
	} 
	f->fim = l;
}

int fila_vazia(Fila *f){
	return f->ini==NULL;
}

int fila_remove(Fila *f){
	Lista *l; int a;
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->ini->info;
	l = f->ini;
	f->ini = f->ini->prox;
	free(l);
	if(fila_vazia(f)){
		f->fim = NULL;
	}
	return a;
}

/*Fun��o que imprime os elementos de uma fila.*/
void fila_imprime(Fila *f){
	Lista *lAux = f->ini;
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

/*Libera o espa�o alocado para uma fila.*/
void fila_libera(Fila *f){
	Lista* l = f->ini;
	Lista* lAux;
	while(l!=NULL){
		lAux = l->prox;
		free(l);
		l = lAux; 
	}
	free(f);
}

// ~~~~~~~ Quest�o 03 (Lista) ~~~~~~~~

// Letra A)
int qtd_primos(Fila* f){
	if(fila_vazia(f)){
		return 0;
	}else{
		Lista* l = f->ini;
		int cont_prim = 0;
		while(l!=NULL){
			int cont_div=0, i;
			for(i=1;i<=l->info;i++){
				if((l->info%i)==0){
					cont_div++;
				}
			}
			if(cont_div==2){
				cont_prim++;
			}
			l = l->prox;
		}
 		return cont_prim;
	}
}

// Letra B)
Fila* inverte_fila(Fila* f){
	Fila* f1 = fila_cria();
	if(!fila_vazia(f)){
		Lista* lAux = f->ini;
		Lista* l = lst_cria();
		Lista* lFim = lst_cria();
		
		while(!lst_vazia(lAux)){
			l = lst_insere(l, lAux->info);
			lFim = lAux;
			lAux = lAux->prox;
		}
		
		f1->ini = l;
		f1->fim = lFim;
	}
	return f1;
}





