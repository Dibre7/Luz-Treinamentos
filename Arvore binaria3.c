#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct No{
	int dado;
	struct No *esquerda, *direita;             //tipo do ponteiro
}No;

/*typedef struct arvB{
	No *raiz;
	int tam;
}arvB;*/

No *criano (int valor){                                //Inicializando e criando o nó
    No *novo =(No*)malloc(sizeof(No));      //Criando um novo nó e determinando quantidade do tamanho(no) e endereço(no*)
	novo -> dado = valor;				
	novo -> esquerda = NULL;
	novo -> direita = NULL;
	return novo;
}


//-------------------------------------------------------------
No *inserirNova(No *raiz, int valor){
	if(raiz == NULL){                       //Se Raiz for nula
		No *novo = criano(valor);         //criando nó
		return novo;                      //Retornando novo nó
	}
	else{
		if(valor < raiz ->dado){                                    //valor é menor que o valor da raiz
			raiz ->esquerda = inserirNova(raiz ->esquerda, valor);  //retorna o endereço do nó
		}
		if(valor > raiz ->dado){                                    //valor é maior que o valor da raiz
			raiz ->direita = inserirNova(raiz ->direita, valor);    //retorna o endereço do nó
		}
        else{
            printf("\nValor ja inserido\n");
        }
		return raiz;                                    //retorna o valor da raiz, para nao perder
	}
}

No *remover(No *raiz, int chave){
	if(raiz == NULL){
		printf("Valor nao encontrado! \n");
		return NULL;
	}
	else{
		if(raiz ->dado == chave){                                      //Se o dado da chave é igual a raiz
			if(raiz ->esquerda == NULL && raiz->direita == NULL){      //Se o raiz não tiver filhos a esquerda e direita
				free(raiz);
				return NULL;
			}
			else{
				if(raiz ->esquerda == NULL || raiz ->direita == NULL){  //Se o raiz tiver um filho em algum dos lados
					No *aux;
					if(raiz ->esquerda != NULL){                      //Se o lado esquerdo tiver filho
						aux = raiz ->esquerda;                        //Salva nó esquerdo em aux
					}
					else{                                            //Se o lado direito tiver filho
						aux = raiz ->direita;                        //Salva nó direita em aux
					}
					free(raiz);
					return aux;              //retornando o nó que precisa ser salvo
				}
				//------retirar nó com 2 filhos
				else{                  
					if(raiz ->direita == NULL){                            // se a direita for null, entao abaixo ir para subarvore esquerda e no mais a direita
					No *aux = raiz ->esquerda;                 //Ponteiro para a esquerda (subarvore)
					while(aux ->direita != NULL){              //Indo pro nó mais a direita da esquerda
						aux = aux ->direita;
					}
					raiz ->dado = aux ->dado;                //não remover o dado, alterar a raiz
					aux ->dado = chave;
					raiz ->esquerda = remover(raiz ->esquerda, chave);
					return raiz;
					}
					// senao a esquerda então é null, abaixo ir para direita
					else{                                    // se a esquerda for null, entao abaixo ir para subarvore direita e no mais a esquerda
					No *aux = raiz ->direita;                 //Ponteiro para a esquerda (subarvore)
					while(aux ->esquerda != NULL){              //Indo pro nó mais a direita da esquerda
						aux = aux ->esquerda;
					}
					raiz ->dado = aux ->dado;
					aux ->dado = chave;
					raiz ->direita = remover(raiz ->direita, chave);
					return raiz;
					}
				}
			}
		}
		else{
			if(chave < raiz ->dado){				//se o dado da chave é menor que o dado raiz
				raiz ->esquerda = remover(raiz ->esquerda, chave); // recebe a chamada recursiva
			}
			else{	                    			//se o dado da chave é maior que o dado raiz
				raiz ->direita = remover(raiz ->direita, chave); // recebe a chamada recursiva
			}
			return raiz;
		}
	}
}

//------------------------------------------------------------
int buscar(No *raiz, int chave){
    if(raiz == NULL){
        return -1;
    }
    else{
        if(raiz ->dado == chave){    // conteudo do nó é igual ao valor chave(caso não fosse inteiro raiz ->dado ->chave, para verificar o tipo)
            return raiz ->dado;
        }
        else{
            if(chave < raiz ->dado){                    //verificar se tem que ir a esquerda
                return buscar(raiz ->esquerda, chave);  //chamada recursiva pra esquerda
            }
            else{                                       //verificar se tem que ir a direita
                return buscar(raiz ->direita, chave);  //chamada recursiva pra direita
            }
        }
    }   
}


//------------------------------------------------------------
int tamanho(No *raiz){
    if(raiz ==NULL){
        return 0;
    }
    else{
        return 1 + tamanho(raiz ->esquerda) + tamanho(raiz ->direita); 
    }
}


//-------------------------------------------------------------
void imprimir(No *raiz){
	if(raiz  != NULL){
		imprimir (raiz ->esquerda);
		printf("%d  ", raiz ->dado);
		imprimir(raiz -> direita);
	}
}

//Obs -  raiz ->esquerda   =   (*raiz).esquerda


int main(){
	int opcao, valor;

    No *raiz = NULL;

	do{
		printf("\n 0-Sair\n 1-Inserir\n 2-Imprimir\n 3-Buscar\n 4-Remover\n ");
		scanf("%d", &opcao);

		switch(opcao){
			case 0:
				printf("\nSaindo.. \n");
				break;
			case 1:
				printf("\nDigite um valor:");
				scanf("%d", &valor);
				raiz = inserirNova(raiz, valor);
				break;
			case 2:
                printf("\nTamanho: %d ", tamanho(raiz));
				printf("\nImpressao da arvore binaria:\n");
				imprimir(raiz);
				printf("\n");
				break;
            case 3:
                printf("\nQual valor deseja buscar ? ");
                scanf("%d", &valor);
                printf("\nResultado da busca: %d\n", buscar(raiz, valor));	
                break;
			case 4:
				printf("\nDigite um valor a ser removido:");
				scanf("%d", &valor);
				raiz = remover(raiz, valor);
				printf("\n");
				break;
			default:
				printf("\nOpcao invalida\n");
		}

	}while(opcao != 0);

}