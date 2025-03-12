#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void main(){

int matriz[5][10];
float preco[10] = {0};
int quantidadeProdutoArmazem[5] = {0};
int quantidadeProdutoIndexadoArmazem[10] = {0};
float menorPreco[5] = {0};
float menor = 0;

setlocale(LC_ALL, "Portuguese");

for(int i = 0; i < 10; i++){
    printf("Digite o preço do produto %i: \n", i);
    scanf("%f", &preco[i]);
}

for(int i = 0; i < 5; i++){
    for(int j = 0; j < 10; j++){
        printf("Digite a quantidade estocada de cada produto no armazem %i posição %i: \n", i, j);
        scanf("%i", &matriz[i][j]);
        quantidadeProdutoArmazem[i] += matriz[i][j];
        menorPreco[i] += preco[i] * quantidadeProdutoArmazem[i];
        }
}

for(int i = 0; i < 10; i++){
    for(int j = 0; j < 5; j++){
        quantidadeProdutoIndexadoArmazem[i] += matriz[j][i];
    }
}

for(int i = 0; i < 5; i++){
    printf("Quantidade de produtos estocados no armazem %i: \n", i , quantidadeProdutoArmazem[i]);

    if(menor == 0){
        menor == menorPreco[i];
    }
    if(menor > menorPreco[i]){
        menor = menorPreco[i];
    }
}


for(int i = 0; i < 10; i++){
    printf("Quantidade de cada produto armazenado em todos os armazens juntos - produto %i: %i \n", i, quantidadeProdutoIndexadoArmazem[i]);
}

printf("O menor preço armazenado dentre os armazens é: %f", menor);

}
