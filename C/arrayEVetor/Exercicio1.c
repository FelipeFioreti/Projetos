#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void main(){

int matriz[4][5];
int soma[5] = {0};
int numero = 0;

setlocale(LC_ALL, "Portuguese");

for(int i = 0; i < 4;i++){
    for(int j = 0; j < 5; j++){
        printf("Digite o valor do número na posição [I] = %i e [J] = %i \n", i,j);
        scanf("%i", &numero);
        matriz[i][j] = numero;
    }
}


for(int i = 0; i < 4;i++){
    for(int j = 0; j < 5; j++){
        printf("%i \t", matriz[i][j]);
    }
    printf("\n");
}


for(int i = 0; i < 4;i++){
    for(int j = 0; j < 5; j++){
        soma[i] += matriz[j][i];
    }
    printf("\n");
}


for(int i = 0; i < 5; i++){
    printf("%i \n", soma[i]);
}

}
