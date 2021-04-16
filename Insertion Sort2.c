#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<stdbool.h>
#include <time.h>

//-------------------------------------------------Gera numero
bool Existe(int valores[],int tam, int valor){
    for(int i = 0;i<tam;i++){
        if(valores[i]==valor)
            return true;
    }
    return false;
}

void GeraAleatorios(int numeros[],int quantNumeros,int Limite){
    srand(time(NULL));

    int v;
    for(int i=0;i<quantNumeros;i++){
        v = rand() % Limite;
        while(Existe(numeros,i,v)){
            v = rand() % Limite;
        }
        numeros[i] = v;
    }

}
//------------------------------------------------------------------------------


void Insertionsort(int numeros[], int n) {

    for (int i = 1; i < n; i++) {
        troca(numeros, i);
	}
}


//--------- Fazendo a troca
void troca(int numeros[], int i){
    int escolhido = numeros[i];
	int j = i - 1;
    bool trocou = false;
		
		while ((j >= 0) && (numeros[j] > escolhido)) {
			numeros[j + 1] = numeros[j];
			j--;
            trocou = true; 
		}
        if(trocou == true)
		numeros[j + 1] = escolhido;
}


//---------------------- Principal
int main()
{
    int tam, i, *numeros;

    printf("Qual o tamanho da array ?\n");
    scanf("%d",&tam);
    numeros=(int*)malloc(tam*sizeof(int));

    //Gerando  numeros
    GeraAleatorios(numeros,tam,tam);

    /* Entrada Manual
    printf("Entre com os números para preencher a array:\n");
    for(i=0; i<tam; i++){
        scanf("%d",& numeros[i]);
    }*/

    Insertionsort (numeros, tam);
    
    printf("\n Elementos do array em ordem crescente:\n");
    for(i=0;i<tam;i++){
        printf("%d ",numeros[i]);
    }
    free (numeros);
    return 0;

}