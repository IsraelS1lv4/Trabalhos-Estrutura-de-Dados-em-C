#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "arvb.h"


struct arvb{
	int info;
	ArvB *esq;
	ArvB *dir;
};

ArvB* arvb_cria_vazia(void){
 	return NULL;
}


int arvb_vazia(ArvB *a){
	return a==NULL;
}


void arvb_libera(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
	}
}


ArvB* arvb_busca(ArvB *a, int c){
	if(arvb_vazia(a))
		return NULL;
	else if(a->info < c)
		return arvb_busca(a->dir,c);
	else if(a->info > c)
		return arvb_busca(a->esq,c);
	else //(a->info == c)
		return a;
}

void arvb_imprime(ArvB *a){
	if(!arvb_vazia(a)){
 		arvb_imprime(a->esq);
 		printf("%d ",a->info);
 		arvb_imprime(a->dir);
 	}
}

ArvB* arvb_insere(ArvB *a, int c){
	if(arvb_vazia(a)){
		a = (ArvB*)malloc(sizeof(ArvB));
		a->info = c;
 		a->esq = NULL;
 		a->dir = NULL;
 	}else if(a->info > c)
 		a->esq = arvb_insere(a->esq,c);
 	else if (a->info < c)
 		a->dir = arvb_insere(a->dir,c);
 	else
 		printf("\nElemento Ja Pertence a Arvore\n");
 	return a;
}

ArvB* arvb_remove(ArvB *a, int c){
	if(!arvb_vazia(a)){
 		if(a->info > c)
 			a->esq = arvb_remove(a->esq,c);
 		else if (a->info < c)
 			a->dir = arvb_remove(a->dir,c);
 		else{
 			ArvB* t;
 			if (a->esq == NULL){
 				t = a; a = a->dir;
 				free(t);
 			}else if (a->dir == NULL){
 				t = a; a = a->esq;
 				free(t);
 			}else{
 				t = a->esq;
 				while(t->dir!=NULL)
 					t = t->dir;
 				a->info = t->info; t->info = c;
 				a->esq = arvb_remove(a->esq,c);
			}
 		}
	}
	return a;
}

int folhas_primo(ArvB* a){
	if(!arvb_vazia(a)){
		int num_folh_prim_esq, num_folh_prim_dir;
		if(arvb_vazia(a->dir) && arvb_vazia(a->esq)){
			int i = 1, cont = 0; 
			while(i <= a->info){
				if((a->info % i) == 0){
					cont++;
				}
				i++;
			}
			if(cont==2){
				return 1;
			}else{
				return 0;
			}	
		}else{
			num_folh_prim_esq = folhas_primo(a->esq);
			num_folh_prim_dir = folhas_primo(a->dir);
			return num_folh_prim_esq + num_folh_prim_dir;
		}
	}else{
		return 0;
	}
}

int subarvs_difnull(ArvB* a){
	if(!arvb_vazia(a)){
		if(arvb_vazia(a->dir) && arvb_vazia(a->esq)){
			return 0;
		}else if(!arvb_vazia(a->esq) && !arvb_vazia(a->dir)){
			int nos_camp_difnull_esq = subarvs_difnull(a->esq);
			int nos_camp_difnull_dir = subarvs_difnull(a->dir);
			return nos_camp_difnull_esq + nos_camp_difnull_dir + 1;
		}else{
			if(!arvb_vazia(a->esq)){
				int nos_camp_difnull_esq = subarvs_difnull(a->esq);
				return nos_camp_difnull_esq;
			}else{
				int nos_camp_difnull_dir = subarvs_difnull(a->dir);
				return nos_camp_difnull_dir;
			}
		}
	}else{
		return 0;
	}
}

int subarvs_ig_alt(ArvB* a){
	if(!arvb_vazia(a->esq) && !arvb_vazia(a->dir)){
		if(arvb_altura(a->esq)==arvb_altura(a->dir)){
			int quant_nos_subarv_esq = subarvs_ig_alt(a->esq);	
			int quant_nos_subarv_dir = subarvs_ig_alt(a->dir);
			return quant_nos_subarv_esq + quant_nos_subarv_dir + 1;
		}else{
			int quant_nos_subarv_esq = subarvs_ig_alt(a->esq);
			int quant_nos_subarv_dir = subarvs_ig_alt(a->dir);
			return quant_nos_subarv_esq + quant_nos_subarv_dir + 0;
		}
	}else{
		return 0;
	}
}

int arvb_altura(ArvB *a){ //função para calcular a altura da árvore
	if(arvb_vazia(a))
		return -1;
	else{
		int hSAE = arvb_altura(a->esq);
		int hSAD = arvb_altura(a->dir);
		if(hSAE > hSAD)
			return 1+hSAE;
		else
			return 1+hSAD;
	}
}

void inicializa(int n,ArvB **v){
	int i;
 	for(i=0;i<n;i++)
 		v[i] = NULL;
 }

void impressao_arv_niveis(ArvB* a){
	if(!arvb_vazia(a)){
		int n = pow(2,(arvb_altura(a)+1));     				//utiliza a fução altura para calcular a quantidade de elementos na arvore
		ArvB** vetor = (ArvB**)malloc(n*sizeof(ArvB*)); 	//vetor que armazenará, na ordem, o endereço de cada nó
		inicializa(n, vetor);                  				//utiliza a função inicializa para preencher o vetor de ponteiros com endereços "NULL"
		int quant_elem_nivel[n];			   				//vetor que armazenará a quantidade de elementos em cada nível, o indice do vetor indica corresponde ao nível
		int i = 0, nivel = 0, j = 0, num_print_nivel = 0, nivel_aux = 0, filhos_no = 0, max_filhos = 0;
		vetor[i] = a;
		quant_elem_nivel[nivel] = 1; 						//como o nível inicial é 0 e arvore não é vazia, logo no nível 0 terá 1 nó
		while(vetor[j] != NULL){			
			printf(" %d", vetor[j]->info);      
			num_print_nivel++;     							//contabilizar quantos nós já imprimiu no nível
			if(quant_elem_nivel[nivel_aux]==num_print_nivel){ //entra no if se já tiver impresso todos os nós no nível 
				printf(" <====== Nivel %d\n", nivel_aux);
				nivel_aux++;
				num_print_nivel = 0;
			}
			
			if(vetor[j]->esq!=NULL){
				filhos_no++; i++;
				vetor[i] = vetor[j]->esq;
			}
			if(vetor[j]->dir!=NULL){
				filhos_no++; i++;
				vetor[i] = vetor[j]->dir;
			}
			max_filhos += 2; 												//conta a quantidade máxima de filhos que o proximo nível pode ter
			if(max_filhos==pow(2,nivel+1)){								
				nivel++;
				quant_elem_nivel[nivel] = filhos_no;
				filhos_no = 0; max_filhos = 0;
			}			
			j++;
			if(vetor[j] == NULL && num_print_nivel != 0){   				//entra no if se tiver impresso o último nó da arvore, da esquerda pra direita no nível mais baixo 
				printf(" <====== Nivel %d\n", nivel_aux);
			}
		}
	}
}
