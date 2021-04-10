#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct No{   
    int numero;
    struct No *pDireita,*pEsquerda;
}No;

typedef struct Arvore{   
    No* pRaiz;
    int tamanho;
}Arvore;


void inserir(struct No **pRaiz, int numero){
     if(*pRaiz == NULL){
* pRaiz = (struct No *) malloc(sizeof(struct No));
         (*pRaiz)→pEsquerda = NULL;
         (*pRaiz)→pDireita = NULL;
         (*pRaiz)→numero = numero;
     }else{
         if(numero <(*pRaiz)→numero)
              inserir(&(*pRaiz)→pEsquerda, numero);
         else
              inserir(&(*pRaiz)→pDireita, numero);
     }
 }

void emOrdem(struct No *pNo) {
     if(pNo != NULL) {
         emOrdem(pNo→pEsquerda);
         visita(pNo);
         emOrdem(pNo→pDireita);
     }
 }


 void preOrdem(struct No *pNo){
     if(pNo != NULL){
         visita(pNo);
         preOrdem(pNo→pEsquerda);
         preOrdem(pNo→pDireita);
     }
 }

 void posOrdem(struct No *pNo){
     if(pNo != NULL){
         posOrdem(pNo→pEsquerda);
         posOrdem(pNo→pDireita);
         visita(pNo);
     }
 }

 int contagem(struct node *tree) {
    return (tree != NULL) ? (contagem(tree->left) + contagem(tree->right) + 1) : 0;
 }

 