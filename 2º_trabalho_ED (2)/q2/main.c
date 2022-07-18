#include <stdio.h>
#include <stdlib.h>


int main() {
	/*
	Obs.:
		mod_vetor corresponde a como o vetor será preenchido, podendo assumir:
		'C' -----> crescente
		'D' -----> decrescente
		'A' -----> aleatório
		
		mod_ord corresponde ao metódo de ordenação, podendo assumir:
		'B' -----> bolha
		'R' -----> rapida
		'I' -----> InsertionSort
		'H' -----> HeapSort
	*/
	
	//BubbleSort (vetor crescente)
	printf("\n Metodo BubbleSort:::::\n");
	printf("\n\nVetor crescente:::::");
	ordenacao(1000, 'C', 'B');
	ordenacao(10000, 'C', 'B');
	ordenacao(100000, 'C', 'B');
	ordenacao(1000000, 'C', 'B');
	
	//BubbleSort (vetor decrescente)
	printf("\n\nVetor decrescente:::::");
	ordenacao(1000, 'D', 'B');
	ordenacao(10000,  'D', 'B');
	ordenacao(100000,  'D', 'B');
	ordenacao(1000000,  'D', 'B');
	
	//BubbleSort (vetor aleatorio)
	printf("\n\nVetor aleatorio:::::");
	ordenacao(1000,  'A', 'B');
	ordenacao(10000,  'A', 'B');
	ordenacao(100000,  'A', 'B');
	ordenacao(1000000,  'A', 'B');
	
	
	//QuickSort (vetor crescente)
	printf("\n\n Metodo QuickSort:::::\n");
	printf("\n\nVetor crescente:::::");
	ordenacao(1000,  'C', 'R');
	ordenacao(10000,  'C', 'R');
	//ordenacao(100000,  'C', 'R');
	//ordenacao(1000000,  'C', 'R');

	//QuickSort (vetor decrescente)
	printf("\n\nVetor decrescente:::::");
	ordenacao(1000,  'D', 'R');
	ordenacao(10000,  'D', 'R');
	//ordenacao(100000,  'D', 'R');
	//ordenacao(1000000,  'D', 'R');
	
	//QuickSort (vetor aleatorio)
	printf("\n\nVetor aleatorio:::::");
	ordenacao(1000,  'A', 'R');
	ordenacao(10000,  'A', 'R');
	ordenacao(100000,  'A', 'R');
	ordenacao(1000000,  'A', 'R');
	
	
	//insertionSort (vetor crescente)
	printf("\n\n Metodo InsertSort:::::\n");
	printf("\n\nVetor crescente:::::");
	ordenacao(1000,  'C', 'I');
	ordenacao(10000,  'C', 'I');
	ordenacao(100000,  'C', 'I');
	ordenacao(1000000,  'C', 'I');
	
	//insertionSort (vetor decrescente)
	printf("\n\nVetor decrescente:::::");
	ordenacao(1000,  'D', 'I');
	ordenacao(10000,  'D', 'I');
	ordenacao(100000,  'D', 'I');
	ordenacao(1000000,  'D', 'I');
	
	//insertionSort (vetor aleatorio)
	printf("\n\nVetor aleatorio:::::");
	ordenacao(1000,  'A', 'I');
	ordenacao(10000,  'A', 'I');
	ordenacao(100000,  'A', 'I');
	ordenacao(1000000,  'A', 'I');

	//Heapsort (vetor crescente)
	printf("\n\n Metodo HeapSort:::::\n");
	printf("\n\nVetor crescente:::::");
	ordenacao(1000,  'C', 'H');
	ordenacao(10000,  'C', 'H');
	ordenacao(100000,  'C', 'H');
	ordenacao(1000000,  'C', 'H');
	
	//Heapsort (vetor decrescente)
	printf("\n\nVetor decrescente:::::");
	ordenacao(1000,  'D', 'H');
	ordenacao(10000,  'D', 'H');
	ordenacao(100000,  'D', 'H');
	ordenacao(1000000,  'D', 'H');
	
	//Heapsort (vetor aleatorio)
	printf("\n\nVetor aleatorio:::::");
	ordenacao(1000,  'A', 'H');
	ordenacao(10000,  'A', 'H');
	ordenacao(100000,  'A', 'H');
	ordenacao(1000000,  'A', 'H');
	
	
	return 0;
}
