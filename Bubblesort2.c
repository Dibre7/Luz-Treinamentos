#include<stdio.h>
#include<stdlib.h>

void Bubblesort(int *numeros, int n){ 
    if (n < 1)return; 
    int ref = 0;

    for (int i=0; i<n; i++) {
        if (numeros[i] > numeros[i+1]){ 
            troca(&numeros[i], &numeros[i+1]);
            ref = 1;
        }  
    }
    if(ref == 1) Bubblesort(numeros, n-1);
    
} 

//---------------Fazendo a troca
void troca(int *a, int *b){ 
    int aux = *a; 
    *a = *b; 
    *b = aux; 
} 



int main(){
    int tam,i,*numeros;
    
    printf("Qual o tamanho da array ?\n");
    scanf("%d",&tam);
    numeros=(int*)malloc(tam*sizeof(int));
    printf("Entre com os números para preencher a array:\n");
    for(i=0; i<tam; i++){
        scanf("%d",& numeros[i]);
    }

    Bubblesort(numeros,tam-1);

    printf("\n Elementos do array em ordem crescente:\n");
    for(i=0;i<tam;i++){
        printf("%d ",numeros[i]);
    }
    free (numeros);
    return 0;
}