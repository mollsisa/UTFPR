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

void trocar (int *V, int a, int b) {
   int aux = V[a];
   V[a] = V[b];
   V[b] = aux;
}

void imprimir (int *V, int size) {
   int i;
   for (i = 0; i < size; i++) {
      printf("%d ", V[i]);
   }
   printf("\n");
}

void min_heapify (int *V, int size, int i) {
   int l = esquerda(i);
   int r = direita(i);
   int menor = i;

   if (l < size && V[l] < V[menor])
      menor = l;
   if (r < size && V[r] < V[menor])
      menor = r;
   if (menor != i) {
      trocar(V, i, menor);
      min_heapify(V, size, menor);
   }
}

void build_min_heap (int *V, int size) {
   for (int i = (size / 2) - 1; i >= 0; i--) {
      min_heapify(V, size, i);
   }
}

int heap_extract_min (int *V, int *size) {
   if (*size < 1) {
      fprintf(stderr, "Heap underflow\n");
      exit(EXIT_FAILURE);
   }
   int min = V[0];
   V[0] = V[*size - 1];
   (*size)--;
   min_heapify(V, *size, 0);
   return min;
}

void heap_decrease_key (int *V, int i, int chave, int size) {
    if(chave > V[i]){
      printf("Error: Key priority bigger than the actual key");
      return;
   }
   V[i] = chave;
   while (i > 0 && V[pai(i)] > V[i]) {
      trocar(V, i, pai(i));
      i = pai(i);
   }
}

void min_heap_insert (int *V, int chave, int *size) {
   if (*size >= 1000) { 
      printf("Error: Heap overflow\n");
      return;
   }
   V[*size] = chave;
   (*size)++;
   heap_decrease_key(V, *size - 1, chave, *size);
}

int main () {

   int size = 10;

   int v[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
   
   imprimir (v, size);

   build_min_heap (v, size);
   
   imprimir (v, size);
   
   heap_extract_min (v, &size);
   
   imprimir (v, size);
   
   //Modificando a última chave {16} para o valor {1}!
   heap_decrease_key (v, size-1, 1, size);
   
   imprimir (v, size);

   //Inserindo uma nova chave com valor {0}!
   min_heap_insert (v, 0, &size);
   
   imprimir (v, size);
   
   
   return 0;
}

