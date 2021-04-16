#include<stdio.h>
#include<stdlib.h>


typedef struct no{      //definir nó como um tipo de variavel e estrutura
    int valor;
    struct no *proximo;                         //obs é preciso struct ?
}no;

typedef struct listaL{  //definir ListaL como um tipo de variavel e estrutura
    no *inicio, *fim;
    int tamanho;
}listaL;

no *criano (int dado){                                //Inicializando e criando o nó
    no *novo =(no*)malloc(sizeof(no));                //Alocando na memória
    novo->valor = dado;
    novo->proximo = NULL;
    return novo;
}

listaL *criaLista (){                                 //Inicializando e criando a lista
    listaL *nova =(listaL*)malloc(sizeof(listaL));    //Alocando na memória
    nova ->inicio = NULL;
    nova ->fim = NULL;
    nova ->tamanho = 0;
    return nova; 
}

//limpa memoria
/*listaL *limpaLista (){
    ListaL
}*/

void inserirnoinicio (listaL *lista, int dado){
    no *novo = criano(dado);
    if (lista->inicio == NULL){
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    }
    else{
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    }
    lista->tamanho++;
}

void inserirnofim (listaL *lista, int dado){
    no *novo = criano(dado);

    if (lista->inicio == NULL){        //Se estiver vazia
        lista->inicio = novo;
        lista->fim = novo;
    }
    else{                              //Não estiver vazia
        lista->fim->proximo = novo;
        lista->fim =  novo;
    }
    lista->tamanho++;
}

void removerinicio (listaL *lista){
    no *inicio = lista->inicio;
    no *remover = NULL;

    if(inicio != NULL){                  //remover se for o primeiro elemento
        remover = lista->inicio;
        lista->inicio = remover->proximo;
        if (lista->inicio == NULL){
            lista->fim = NULL;
        }
    }
    if(remover){
        free(remover);
        lista->tamanho--;
    }
}

void removerfim (listaL *lista){
    no *inicio = lista->inicio;
    no *remover = NULL;

    while(inicio !=NULL && inicio->proximo !=NULL){
        inicio = inicio->proximo;
    }
    if(inicio !=NULL && inicio->proximo !=NULL){
        remover = inicio->proximo;
        inicio->proximo = remover->proximo;
        if (inicio->proximo == NULL){
            lista->fim = inicio;
        }
    }
    if(remover){
        free(remover);
        lista->tamanho--;
    }

}

void remover (listaL *lista, int dado){
    no *inicio = lista->inicio;
    no *remover = NULL;

    if(inicio != NULL && lista->inicio->valor == dado){ // remover se for o primeiro
        remover = lista->inicio;
        lista->inicio = remover->proximo;
        if (lista->inicio == NULL){
            lista->fim = NULL;
        }
    }
    else{                                        //remover se for no meio ou ultimo
            while(inicio !=NULL && inicio->proximo !=NULL && inicio->proximo->valor != dado){
                inicio = inicio->proximo;
            }
            if (inicio !=NULL && inicio->proximo !=NULL){
                remover = inicio->proximo;
                inicio->proximo = remover->proximo;
                if (inicio->proximo == NULL){
                    lista->fim = inicio;
                }
            }
    }
    if(remover){
        free(remover);
        lista->tamanho--;
    }
}

void imprimirlista (listaL *lista){
    no *inicio = lista->inicio;
    while(inicio != NULL){
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n");
}

void imprimirlistatamanho (listaL *lista){
    no *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tamanho);
}

void imprimircompleto (listaL *lista){
    no *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tamanho);
    while(inicio != NULL){
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n");
}



int main(){
    listaL *listaligada = criaLista();
    int opcao, dado;


    do {
        printf(" 1 - Inserir no inicio\n 2 - Inserir no fim \n 3 - Remover do Inicio\n 4 - Remover do fim\n 5 - Remover algum outro valor \n 6 - Quantidade de valores na lista\n 7 - Lista completa\n 8 - Imprimir Lista Completa e quantidade\n 0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o numero a ser inserido\n");
            scanf("%d", &dado);
            inserirnoinicio(&listaligada, dado);
            printf("\n");
            break;

        case 2:
            printf("Digite o numero a ser inserido\n");
            scanf("%d", &dado);
            inserirnofim(&listaligada, dado);
            printf("\n");
            break;
            
        case 3:
            removerinicio(&listaligada);
            printf("\n");

        case 4:
            removerfim(&listaligada);
            printf("\n");

        case 5:
            printf("Digite o numero a ser removido\n");
            scanf("%d", &dado);
            remover(&listaligada, dado);
            printf("\n");
            break;

        case 6:
            imprimirlistatamanho(&listaligada);
            printf("\n");
            break;

        case 7:
            imprimirlista(&listaligada);
            printf("\n");
            break;

        case 8:
            imprimircompleto(&listaligada);
            printf("\n");

        case 0:
            printf("Finalizando");
            printf("\n");
            break;
        default:
            printf("Opcao Invalida");
            printf("\n");
        }
    }while(opcao!=0);

    return 0;
}