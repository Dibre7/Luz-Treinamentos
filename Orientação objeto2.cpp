#include<stdio.h>
#include<stdlib.h>
#include<iostream>		

using namespace std;

struct No{
    int valor;
    No *proximo;
};


//-------------------Declarando a classe Lista
class Lista{
    private:
        No *inicio,*fim;

    public:
        Lista(){                     //o construtor
            inicio = NULL;
            fim = NULL;
        }
//--------------------Criando/inicializando no---------------------     
   		No *criano(int dado){
			No *novo = new No;
            novo->valor = dado;
            novo->proximo = NULL;
            return novo;
		}
            
//------------------- inserção ------------------------------------
        void inserirnoinicio (int valor){
            No *novo = criano(valor);

            if(inicio == NULL){
                inicio = novo;
                fim = novo;
            }
            else{
                novo->proximo = inicio;
                inicio=novo;
            }
        }
        
        void inserirnofim (int valor){
            No *novo = criano(valor);

            if (inicio == NULL){          //se estiver vazia
                inicio = novo;
                fim = novo;
            }
            else{                        //Senao estiver vazia
                fim->proximo = novo;
                fim = fim->proximo;
            }
        }
        
//--------------------------impressão------------------------------
        void imprimir(){
            No *novo = inicio;
            //novo = inicio; em cima
            while(novo != NULL){                //Enquanto novo não for nullo
                cout << novo->valor << " ";
                novo = novo->proximo;
            }
            printf("\n");
        }
        
//-------------------------remoção ----------------------------------
        void removerinicio (){
            No *novo = new No;
            No *remover = new No;
            novo = inicio;
            remover = NULL;

            if (inicio == NULL){          //Sem dados na lista
                cout << "Lista vazia";
            }
            if (inicio != NULL){          //Se tiver dados na Lista
                remover = inicio;
                novo = remover->proximo;
                inicio = novo;
                if(inicio == NULL){
                    fim = NULL;
                }
            }
            if(remover){
                free(remover);
            }
        }

        void removerfim (){
            No *novo = new No;
            No *antes = new No;
            novo = inicio;

            if(inicio == NULL){					//Se lista estiver vazia
                cout << "Lista Vazia";
            }
            while (novo->proximo != NULL){
                antes = novo;
                novo = novo->proximo;
            }
            if (novo == inicio){
                inicio = novo->proximo;
            }
            else{
                antes->proximo = novo->proximo;
            }
            free(novo);
        }

        void removernumeroescolhido(int v){
            No *novo = new No;
            No *remover = new No;
            No *antes = new No;
            novo = inicio;

            if(inicio == NULL){
                cout << "Lista Vazia";
            }
            if (inicio != NULL && inicio->valor == v){
                remover = inicio;
                novo = remover->proximo;
                inicio = novo;
                if(novo == NULL){
                    fim = NULL;
                }
                
            }
            else{
                while(novo != NULL && novo->proximo != NULL && novo->proximo->valor != v){
                    antes = novo;
                    novo = novo->proximo;
                }
                if(novo != NULL && novo->proximo != NULL){
                    remover = novo->proximo;
                    novo->proximo = remover->proximo;
                    if(novo->proximo == NULL){
                        antes->proximo = novo->proximo;
                    }
                }
            }
            free(remover);
        }
};


//-----------------------------------------MENU LISTA-----------------------------------------
void escolhalista (){
    Lista lista;
    int op, v;

    cout << "\nEscolhida a opcao Lista\n";
    do{
        cout << "Escolha uma das opçoes\n";
        cout << "1 - Inserir no inicio\n2 - Inserir no fim\n3 - Imprimir\n4 - Remover do Inicio\n5 - Remover do fim\n6 - Remover algum valor especifico\n0 - Sair\n";
        cin >> op;

        switch (op)
        {
            case 1:
                cout << "Digite um numero\n ";
                cin >> v;
                lista.inserirnoinicio(v);
                cout << "\n";
                break;
            case 2:
                cout << "Digite um numero\n ";
                cin >> v;
                lista.inserirnofim(v);
                cout << "\n";
                break;
            case 3:
                cout << "A lista completa\n";
                lista.imprimir();
                cout << "\n";
                break;
            case 4:
                cout << "Removido o primeiro numero\n";
                lista.removerinicio();
                cout << "\n";
                break;
            case 5:
                cout << "Removido o ultimo numero\n";
                lista.removerfim();
                cout << "\n";
                break;
            case 6:
                cout << "Digite o valor especifico\n";
                cin >> v;
                lista.removernumeroescolhido(v);
                cout << "\n";
                break;
            case 0:
                cout << "Voltando para o Menu Inicial\n";
                break;
            default:
                cout << "Opcao Invalida";
                cout << "\n";
                break;
        }
    }while (op != 0);
}

//-------------------------------Pilha------------------------------------
class Pilha{
    private:
        Lista *pilha = new Lista();
    
    public:
        void inserir(int valor);
        void remover();
        void imprimir();
};

void Pilha::inserir(int valor){
    pilha->inserirnoinicio(int (valor));
}

void Pilha::imprimir(){
    pilha->imprimir();
}

void Pilha::remover(){
    pilha->removerinicio();
}


//--------------------------------------MENU PILHA
void escolhapilha(){
    Pilha pilha;
    int op, v;

    cout <<"\nEscolhida a opcao Pilha\n";
    do {
        cout << "Escolha uma das opçoes\n";
        cout << "1 - inserir\n2 - Imprimir\n3 - Remover\n0 - Sair\n";
        cin >> op;

        switch (op)
        {
            case 1:
                cout << "Digite o numero\n";
                cin >> v;
                pilha.inserir(v);
                cout << "\n";
                break;
            case 2:
                cout << "A pilha completa\n";
                pilha.imprimir();
                cout << "\n";
                break;
            case 3:
                cout << "Numero removido";
                pilha.remover();
                cout << "\n";
                break;
            case 0:
                cout << "Voltando para o Menu Inicial\n";
                break;
            default:
                cout << "Opcao invalida\n";
                break;
        }
    }while(op != 0);
}

//------------------------------Fila--------------------------------------
class Fila{
    private:
        Lista *fila = new Lista();
    
    public:
        void inserir(int valor);
        void remover();
        void imprimir();
};

void Fila::inserir(int valor){
    fila->inserirnofim(int (valor));
}

void Fila::imprimir(){
    fila->imprimir();
}

void Fila::remover(){
    fila->removerinicio();
}

//---------------------------------------------MENU FILA
void escolhafila(){
    Fila fila;
    int op, v;
    
    cout << "\nEscolhida a opção Fila\n";
    do {
        cout << "Escolha uma das opçoes\n";
        cout << "1 - inserir\n2 - Imprimir\n3 - Remover\n0 - Sair\n";
        cin >> op;

        switch (op)
        {
            case 1:
                cout << "Digite o numero\n";
                cin >> v;
                fila.inserir(v);
                cout << "\n";
                break;
            case 2:
                cout << "A fila completa\n";
                fila.imprimir();
                cout << "\n";
                break;
            case 3:
                cout << "Numero removido";
                fila.remover();
                cout << "\n";
                break;
            case 0:
                cout << "Voltando para o Menu Inicial\n";
                break;
            default:
                cout << "Opcao invalida";
                break;
         }
    }while(op != 0);
}
//--------------------------------------------------------------
int main(){
    int e;
    //Lista *listateste = new Lista();
    //Fila *filateste = new Fila();

    do{
        cout << "Escolha uma das opcoes\n";
        cout << "1 - Criar uma pilha\n2 - Criar uma fila\n3 - Criar uma lista\n0 - Sair\n";
        cin >> e;

        switch (e)
        {
            case 1:
                escolhapilha();
                cout << "\n";
                break;
            case 2:
                escolhafila();
                cout << "\n";
                break;
            case 3:
                escolhalista();
                cout << "\n";
                break;
            case 0:
                cout << "Finalizando\n";
                break;
            default:
                cout <<"opcao invalida";
                break;
        }
    }while(e !=0);
 return 0;
}
