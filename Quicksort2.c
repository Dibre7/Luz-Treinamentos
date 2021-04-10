#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<stdbool.h>


void Quicksort(int numeros[], int inicio, int fim)
{
	int i, j, pivo;
	i = inicio;
	j = fim-1;
	pivo = numeros[(inicio + fim) / 2];
	while(i <= j)
	{
		while(numeros[i] < pivo && i < fim)
		{
			i++;
		}
		while(numeros[j] > pivo && j > inicio)
		{
			j--;
		}
		if(i <= j)
		{
            troca(numeros, i, j);
			i++;
			j--;
		}
	}
	if(j > inicio)
		Quicksort(numeros, inicio, j+1);
	if(i < fim)
		Quicksort(numeros, i, fim);
}

//-------------------Fazendo a Troca
void troca(int numeros[], int i, int j){
    int aux = numeros[i];
	numeros[i] = numeros[j];
	numeros[j] = aux;
}


//------------------------Principal
int main(int argc, char *argv[])
{
	int tam,i,*numeros;
    
    printf("Qual é o tamanho da array ?\n");
    scanf("%d",&tam);
    numeros=(int*)malloc(tam*sizeof(int));
    printf("Entre com os números para preencher a array:\n");
    for(i=0; i<tam; i++){
        scanf("%d",& numeros[i]);
    }

	Quicksort(numeros, 0, tam);
	
    printf("\n Elementos do array em ordem crescente:\n");
    for(i=0;i<tam;i++){
        printf("%d ",numeros[i]);
    }
    free (numeros);
    return 0;
}