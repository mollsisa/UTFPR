#include <stdio.h>
#include <stdlib.h>

int pai (int i) {
   return (i - 1)/2;
}

int esquerda (int i) {
   return (i * 2) + 1;
}

int direita (int i) {
   return (i * 2) + 2;
}

void trocar (int V[], int a, int b) {
   int aux = V[a];
   V[a] = V[b];
   V[b] = aux;
}

void imprimir (int V[], int size) {
   int i;
   for (i = 0; i < size; i++) {
      printf("%d ", V[i]);
   }
   printf("\n");
}

void max_heapify (int V[], int size, int i) {
   int e = esquerda (i);
   int d = direita (i);
   int maior;
   if ( (e < size) && (V[e] > V[i]) ) {
      maior = e;
   }
   else {
      maior = i;
   }
   if ( (d < size) && (V[d] > V[maior]) ) {
      maior = d;
   }
   if (maior != i) {
      trocar (V, i, maior);
      max_heapify (V, size, maior);
   }
}

void heap_maximum (int V[]){
   return V[0];
}

int heap_extract_max (int V[], int size){
   if(size < 1)
      printf("Error: Heap underflow");
      return;
   int max = V[0];
   V[0] = V[size - 1];
   size = size - 1;
   max_heapify(V, size, 0);
   return max;
}

void heap_increase_key(int V[], int i, int chave){
   if(chave < V[i]){
      printf("Error: Key priority smaller than the actual key");
      return;
   }
   V[i] = chave;
   while(i > 0 && V[pai(i)] < V[i]){
      int tmp = V[i];
      V[i] = V[pai(i)];
      V[pai(i)] = tmp;
      i = pai(i);
   }
}

void max_hep_insert(int V[], int size, int chave){
   size = size + 1;
   V[size - 1] = -20;
   heap_increase_key(V, size-1, chave);
}

void heap_decrease_key (int V[], int i, int chave, int size) {
   if(chave > V[i]){
      printf("Error: Key priority bigger than the actual key");
      return;
   }
   V[i] = chave;
   max_heapify(V, size, i);
}

int main () {

   int size = 12;

   int v[] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};

   imprimir (v, size);

   // heap_increase_key(v, 2, 17);
   // printf ("After increase-key: \n");
   // imprimir (v, size);

   /*Modificando a chave da posição 0 para o valor 1!*/   
   heap_decrease_key (v, 0, 1, size);   
   printf ("After decrease-key: \n");
   imprimir (v, size);

   return 0;
}

