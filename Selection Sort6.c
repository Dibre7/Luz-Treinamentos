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


void Selectionsort(int numeros[], int n) { 
  int  posicao, min, aux;
  bool trocou;
  for (int i = 0; i < (n-1); i++) 
  {
     min = numeros[i];
     posicao = i;
     trocou = false;
     for (int j = (i+1); j < n; j++) {   // Verifica as posições para frente que faltam
       if(numeros[j] < min) {
         min = numeros[j];
         posicao = j;
         trocou = true;
       }
     }
     if (trocou == true) {
       troca (numeros, min, posicao, i);

     }
  }
}

//-------------Fazendo a troca
void troca(int numeros[], int min, int posicao, int i){
    int aux = numeros[i];
    numeros[i] = min;
    numeros[posicao] = aux;
}


//---------------------- Principal
int main()
{
    int tam, i, *numeros;

    printf("Qual o tamanho da array ?\n");
    scanf("%d",&tam);
    numeros=(int*)malloc(tam*sizeof(int));

//----------------------------------Manual
    /*printf("Entre com os números para preencher a array:\n");
    for(i=0; i<tam; i++){
        scanf("%d",& numeros[i]);
    }*/


    //Gerando  numeros
    GeraAleatorios(numeros,tam,tam);


    Selectionsort (numeros, tam);

    printf("\n Elementos do array em ordem crescente:\n");
    for(i=0;i<tam;i++){
        printf("%d ",numeros[i]);
    }
    free (numeros);
    return 0;

}