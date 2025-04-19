#include "arvore.h"

Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

//========= Exercício 2 - pré-ordem ====
void pre_ordem(Arvore* a){
   if(a != NULL){
      printf("%c ", a->info);
      pre_ordem(a->esq);
      pre_ordem(a->dir);
   }
}

//========= Exercício 2 - in-ordem ====
void in_ordem(Arvore* a){
   if(a != NULL)
   {
      in_ordem(a->esq);
      printf("%c ", a->info);
      in_ordem(a->dir); 
   }
}

//========= Exercício 2 - pós-ordem ====
void pos_ordem(Arvore* a){
   if(a != NULL)
   {
      pos_ordem(a->esq);
      pos_ordem(a->dir);
      printf("%c ", a->info); 
   }
}

//========= Exercício 3 - pertence ====
int pertence(Arvore* a, char c){
   if(a != NULL){
      return 0;
   }
   if(a->info == c){
      return 1;
   }
   else{
      return pertence(a->esq, c) || pertence(a->dir, c);
   }
}

//========= Exercício 4 - conta nós ====
int conta_nos (Arvore *a){
   if(a != NULL){
      return 1 + conta_nos(a->esq) + conta_nos(a->dir);
   }
}

//========= Exercício 5 - calcula altura ====
int calcula_altura_arvore (Arvore *a);


//========= Exercício 6 - conta folhas ====
int conta_folha = 0;
int conta_nos_folha (Arvore *a){
   if(a != NULL){
      if(a->dir == NULL && a->esq == NULL){
        conta_folha++;
      }
      else{
         conta_nos_folha(a->esq);
         conta_nos_folha(a->dir);
      }
   }
   return conta_folha;
}

int main (int argc, char *argv[]) {
   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );	

   printf("Pre Ordem: ");
   pre_ordem(a);
   printf("\nIn Ordem: ");
   in_ordem(a);
   printf("\nPos Ordem: ");
   pos_ordem(a);

   if(pertence(a, 'h') == 1){
      printf("\nPertence");
   } 
   else{
      printf("\nNão pertence");
   }

   int countNos = conta_nos(a);
   printf("\nContagem de nós: %d", countNos);

   int countNosFolha = conta_nos_folha(a);
   printf("\nContagem de nós folha: %d", countNosFolha);

   arv_libera (a);

   return 0;
}