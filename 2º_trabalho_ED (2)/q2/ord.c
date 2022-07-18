#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ord.h"



void BubbleSort(int n, int *v){
	int i,j,temp;
	for(i=n;i>0;i--){
		for(j=0;j<i;j++){
			if(v[j]>v[j+1]){
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
}

void QuickSort(int n, int *v){
	if(n>1){
		int x = v[0];
		int a =1; int b = n-1;
		while(1){
			while(a<n && v[a] <=x) a++;
			while(v[b]>x) b--;
			if(a<b){
				int temp = v[a];
				v[a] = v[b];
				v[b] = temp;
				a++;b--;
			}else{
				break;
			}	
		}
		v[0] = v[b];
		v[b] = x;
		QuickSort(b,v);
		QuickSort(n-a,&v[a]);
	}
}

void InsertionSort(int *v, int n){
	int j, i, chave;
	for(j=1;j<=n;j++){
		chave = v[j];
		i = j-1;
		while(i>-1 && v[i] > chave){
			v[1+i] = v[i];
			i--;
		}
		v[i+1] = chave;
	}
}


//MAX-HEAPIFY
void max_heapify(int *A, int i, int tam_heap){
	int l = (2*i)+1;
	int r = (2*i)+2;
	int maior;
	if(l <= tam_heap && A[l]>A[i]){
		maior = l;
	}else{
		maior = i;
	}
	if(r<=tam_heap && A[r]>A[maior]){
		maior = r;
	}
	if(maior != i){
		int troca = A[i];
		A[i] = A[maior];
		A[maior] = troca;
		max_heapify(A, maior, tam_heap);
	}
}

//BUILD-MAX-HEAP
void build_max_heap(int *A, int n){
	int tam_heap = n;
	int i;
	int b = n/2;
	for(i = b; i>=0; i--){
		max_heapify(A,i,tam_heap);
	} 
}

//HEAPSORT
void HeapSort(int *A, int n){
	build_max_heap(A, n);
	int tam_heap = n;
	int i;
	for(i=n; i>=1; i--){
		int troca = A[0];
		A[0] = A[i];
		A[i] = troca;
		tam_heap = tam_heap - 1;
		max_heapify(A, 0, tam_heap);
	}
}

void crescente(int n, int *v){
	int aux, num;
	num=0;
	for(aux=0;aux<=n;aux++){
		v[aux]=num;
		num++;
	}
}

void decrescente(int n, int *v){
	int aux, num;
	num=n;
	for(aux=0;aux<=n;aux++){
		v[aux]=num;
		num--;
	}
}

void aleatorio(int n, int *v){
	int aux, num;
	srand(time(NULL));
	for(aux=0;aux<=n;aux++){
		v[aux]=rand() % n;
	}
}

void imprimi(int n, int *v){
	int i;
	for(i=0; i<=n; i++){
		printf("%d ",v[i]);
	}
}

void ordenacao(int n, char mod_vetor, char mod_ord){
	n=n-1;
	int *v = malloc(n*sizeof(int)); 
	clock_t t;
	switch(mod_vetor){
		case 'C':
			crescente(n, v);
			break;
		case 'A':
			aleatorio(n, v);
			break;
		case 'D':
			decrescente(n, v);
			break;
	}

	switch(mod_ord){
		case 'B':
			t=clock();
			BubbleSort(n, v);
			t=clock()-t;
			printf("\nTempo total de execucao (tamanho = %d): %lf\n", n+1,((double)t)/((CLOCKS_PER_SEC/1000)));
			break;
		case 'R':
			t=clock();
			QuickSort(n+1, v);
			t=clock()-t;
			printf("\nTempo total de execucao (tamanho = %d): %lf\n", n+1,((double)t)/((CLOCKS_PER_SEC/1000)));
			break;
		case 'I':
			t=clock();
			InsertionSort(v, n);
			t=clock()-t;
			printf("\nTempo total de execucao (tamanho = %d): %lf\n", n+1,((double)t)/((CLOCKS_PER_SEC/1000)));
			break;
		case 'H':
			t=clock();
			HeapSort(v, n);
			t=clock()-t;
			printf("\nTempo total de execucao (tamanho = %d): %lf\n", n+1,((double)t)/((CLOCKS_PER_SEC/1000)));
			break;
	}
}
