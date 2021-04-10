#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<stdbool.h>

void Selectionsort(int numeros[], int n) { 
  int  j, min, aux;
  for (int i = 0; i < (n-1); i++) 
  {
     min = i;
     for (j = (i+1); j < n; j++) {
       if(numeros[j] < numeros[min]) 
         min = j;
     }
     if (i != min) {
       troca (numeros, min, i);
     }
  }
}

//-------------Fazendo a troca
void troca(int numeros[], int min, int i){
    int aux = numeros[i];
    numeros[i] = numeros[min];
    numeros[min] = aux;
}


//---------------------- Principal
int main()
{
    int tam, i, *numeros;

    printf("Qual o tamanho da array ?\n");
    scanf("%d",&tam);
    numeros=(int*)malloc(tam*sizeof(int));
    printf("Entre com os números para preencher a array:\n");
    for(i=0; i<tam; i++){
        scanf("%d",& numeros[i]);
    }

    Selectionsort (numeros, tam);

    printf("\n Elementos do array em ordem crescente:\n");
    for(i=0;i<tam;i++){
        printf("%d ",numeros[i]);
    }
    free (numeros);
    return 0;

}