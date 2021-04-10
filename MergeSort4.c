#include<stdio.h>
#include<stdlib.h>


void mergeSort (int *vetor, int inicio, int fim){
    if (fim <= inicio){
    return;
    }

    int meio = (inicio+fim)/2;
    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio+1, fim);
    merge (vetor, inicio, meio, fim);
}

//-------Faz a montagem do vetor ordenado
void merge (int *vetor, int inicio, int meio, int fim){

    int ladoesq = inicio;      //----marcador do 1
    int ladodir = meio + 1;    //----marcador do 2

    int tamanho = fim + 1;                             //---- tamanho do vetor auxiliar
    int *vetoraux = (int*)malloc(tamanho*sizeof(int)); //---- tamanho do vetor auxiliar

    for (int j = inicio; j <= fim; j++){

        if(ladoesq == meio+1){                    //--
            vetoraux[j] = vetor[ladodir];
            ladodir++;
        }
        else if (ladodir == fim + 1){
            vetoraux[j] = vetor[ladoesq];
            ladoesq++;
        }
        else if (vetor[ladoesq] < vetor[ladodir]){
            vetoraux[j] = vetor[ladoesq];   
            ladoesq++;
        }else {
            vetoraux[j] = vetor[ladodir];
            ladodir++;
        }
    }
    for(int j = inicio; j <= fim; j++){   //----------Montando o vetor ordenado no principal
        vetor[j] = vetoraux[j];
    }
    free(vetoraux);
}


int main(){

int *vetor, tam, i;
printf("Qual é o tamanho da array ?\n");
scanf("%d", &tam);
vetor = (int*)malloc(tam*sizeof(int));
printf("Entre com os números para preencher a array:\n");
    for (i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }

mergeSort (vetor, 0, tam-1);

printf("\n Elementos do array em ordem crescente:\n");
for(i=0; i < tam; i++){
    printf("%d ",vetor[i]);
}
free(vetor);
return 0; 
}