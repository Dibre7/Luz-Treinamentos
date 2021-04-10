#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

//--------Criando o nó
typedef struct no{
    int dado;              //-campo pra dado
    struct no *prox;       //-ponteiro pro proximo
}no;


typedef struct pilha{
    no *topo;
    int tamanho;             //-ponteiro pro topo
}pilha;


void inicializaPilha(pilha *p){
    p->topo = NULL;            //-ponteiro topo apontando pra nulo
}

void empilha (int dado, pilha *p){ //-recebe quem empilhar e referencia pra pilha
    no *ptr = (no*)malloc(sizeof(no)); //-alocação do nó
    if(ptr == NULL){                           //-Testar se o NÓ foi alocado corretamente
        printf("Erro de alocação de nó. \n");
        return;
    }else {
        ptr->dado = dado;
        ptr->prox = p->topo;
        p->topo = ptr;             //- apos inserir o novo dado(ptr), agora ele é o topo
    }
}

int desempilha(pilha *p){
    no* ptr = p->topo;
    int dado;                       //backup
    if(ptr == NULL){                //verificando se tem algo no topo
        printf("Pilha vazia. \n");
        return;
    }else {                         
        p ->topo = ptr->prox;        //apontando para futuro topo
        ptr->prox = NULL;            //desligando o antigo topo
        dado = ptr->dado;           //salvando backup do dado desimpilhando
        free(ptr);
        return dado;                 //retorna o dado de backup
    }
}

void imprimirPilha(pilha *p){
    no *ptr = p->topo;
    if(ptr == NULL){                //verificando se tem algo no topo
        printf("Pilha vazia. \n");
        return;
    }else {
        while(ptr != NULL){             //imprimindo
            printf("%d ", ptr->dado);
            ptr = ptr->prox;
        }
    printf("\n");
    }
}

int main (){
    pilha *p1 = (pilha*)malloc(sizeof(pilha));
    int opcao, dado;

    if(p1 == NULL){
        printf("Erro de alocação da pilha \n");
        exit(0);
    }else {
        inicializaPilha(p1);
        do { 
            printf(" 1 - Empilhar\n 2 - Imprimir a pilha\n 3 - Remover elemento\n 0 - Sair\n");
            scanf("%d", &opcao);
            switch (opcao)
            {
            case 1:
                printf("Digite o numero a entrar na pilha:\n");
                scanf("%d", &dado);
                empilha(dado, p1);
                break;
            case 2:
               imprimirPilha(p1);
               break;
            case 3:
                desempilha(p1);
                break;
            case 0:
                printf("Fim");
                break;
            default:
                printf("Opção Inválida\n");
        }
        }while(opcao!=0);
    }
    free(p1);
}