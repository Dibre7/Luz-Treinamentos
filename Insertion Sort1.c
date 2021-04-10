#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Insertionsort (int numeros[], int n){

    

    for(int i=0; i<n; i++){
        for(int j= i+1; j>0; j--){
            if(numeros[j] < numeros[j - 1]){
                troca (numeros, j);
            }
            else
                break;
        }
    }
}


//--------- Fazendo a troca
void troca(int numeros[], int j){
    int aux = numeros [j];
    numeros[j] = numeros[j-1];
    numeros[j-1] = aux;
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

    Insertionsort (numeros, tam-1);
    
    printf("\n Elementos do array em ordem crescente:\n");
    for(i=0;i<tam;i++){
        printf("%d ",numeros[i]);
    }
    free (numeros);
    return 0;

}