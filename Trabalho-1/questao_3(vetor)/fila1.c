#include <stdio.h>
#include <stdlib.h>
#include "fila1.h"
#define N 100

typedef struct fila{
	int n;
	int ini;
	int v[N];
}Fila;
 
 //Função Cria Fila
Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->n = 0;
	f->ini = 0;
	return f;
}

//Função Insere
void fila_insere(Fila *f, int info){
	int fim;
	if(f->n==N){
		printf("Capacidade da Fila Estourou!!!\n");
		exit(1); 
	}
	fim = (f->ini + f->n) % N;
	f->v[fim]= info;
	f->n++;
}

/*Testa se uma fila é vazia.*/
int fila_vazia(Fila *f){
 	return f->n==0;
}

/*Função que remove um elemento de uma fila.*/
int fila_remove(Fila *f){
	int a;
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->v[f->ini];
	f->ini = (f->ini+1)%N;
	f->n--;
	return a;
}

//Função Imprime
void fila_imprime(Fila *f){
	int i; int k;
	for(i = 0; i<f->n;i++){
		k = (f->ini+i) % N;
		printf("%d\n",f->v[k]);
	}
}

//Função Libera
void fila_libera(Fila *f){
 	free(f);
}

// ~~~~~~~~ Questão 03 (Vetor) ~~~~~~~~

// Letra A)
int qtd_primos(Fila* f){
	if(fila_vazia(f)){
		return 0;
	}else{
		int i, k, j;
		int cont_prim = 0;
		for(i = 0; i<f->n;i++){
 			k = (f->ini+i) % N;
 			int cont_div = 0;
 			for(j=1;j<=f->v[k];j++){
 				if(f->v[k]%j==0){
 					cont_div++;
				}	
			}
			if(cont_div==2){
				cont_prim++;
			}
 		}
 		return cont_prim;
	}
}

// Letra B)
Fila* inverte_fila(Fila* f){
	Fila* f1 = fila_cria();
	if(!fila_vazia(f)){
		int i, k;
		for(i = f->n-1; i>=0; i--){
 			k = (f->ini+i) % N;
 			fila_insere(f1, f->v[k]);
 		}
	}
	return f1;
}





