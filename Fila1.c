#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct no{
    int dado;
    struct no *prox;   //---ponteiro pro Próximo nó
}no;

typedef struct fila{
    no *inicio;        //---ponteiro pro inicio
    no *fim;           //---ponteiro pro fim
}fila;

void inicializaFila(fila *f){
    f -> inicio = NULL;
    f -> fim = NULL;
}


void enfileira (int dado, fila *f){
    no *ptr = (no*) malloc(sizeof(no));
    if(ptr == NULL){                     //---Teste se é nulo
        printf("Erro de alocação. \n");
        return;
    } else{
        ptr -> dado = dado;   //--- fila estando vazia
        ptr -> prox = NULL;   //--- Prox sempre apontando pra NULL
        if(f -> inicio == NULL){  //--- Se for Null, quer dizer que estou inserindo no inicio
            f -> inicio = ptr;   //--- Inicio aponta para o novo no
        } else{
            f -> fim -> prox = ptr; //-- FIm ira apontar pro proximo, antigo ptr
        }
        f ->fim = ptr;  //--- No final o Fim sempre sera apontado para o novo nó que entrou no fim
        return;
    }
}

int desenfileira(fila *f){
    no *ptr = f -> inicio;   //--- ponteiro para um nó auxilar ptr, apontando para o inicio
    int dado;               //---variavel de backup
    
    if(ptr != NULL){        //---Fileira tiver dados
        f -> inicio = ptr ->prox;  //---atualiza o valor do inicio com o prox nó
        ptr -> prox = NULL;       //---Desligar o nó por completo da fila
        dado = ptr -> dado;       //---salvando backup
        free(ptr);
        if(f -> inicio == NULL){  //--- garantindo que inicio e fim apontem para NULL
            f -> fim = NULL;
        }
        return dado;
    } else{                        //---Quando a fila estiver vazia 
        printf("Fila vazia. \n"); 
        return;
    }
}

void imprimiFila(fila *f){
    no *ptr = f -> inicio;  //---apontar para o inicio
    if(ptr != NULL){         //---verificar se fileira não está vazia
        while(ptr != NULL){             //---Imprimindo os dados na tela
            printf("%d ", ptr -> dado);
            ptr = ptr -> prox;          //--- conforme imprimi o PTR aponta para o PTR prox, até chegar em NULLo
        }
        printf("\n");
    } else {
        printf("Fila vazia. \n");  //---se fileira está vazia
        return;
    }
}


int main(){
    fila *f1 = (fila*) malloc(sizeof(fila));
    int opcao, dado;

    if(f1 == NULL){
        printf("Erro de alocação. \n");
        exit(-1);
    } else{
        inicializaFila(f1);

        do { 
            printf(" 1 - Enfileirar\n 2 - Imprimir a fila\n 3 - Remover elemento\n 0 - Sair\n");
            scanf("%d", &opcao);
            switch (opcao)
            {
            case 1:
                printf("Digite o numero a entrar na pilha:\n");
                scanf("%d", &dado);
                enfileira(dado, f1);
                break;
            case 2:
               imprimiFila(f1);
               break;
            case 3:
                desenfileira(f1);
                break;
            case 0:
                printf("Fim");
                break;
            default:
                printf("Opção Inválida\n");
        }
        }while(opcao!=0);
    }
    free(f1);

}