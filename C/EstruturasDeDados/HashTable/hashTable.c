#include "listaEncadeada.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TAMANHO_MINIMO 26

typedef struct table
{
    int valor;
    char chave[30];
} table;


table * criar_HashTable(int tamanho){

    table * hashTable[tamanho];
    return hashTable;
}

int main(){
    table * hashTable = criar_HashTable(TAMANHO_MINIMO);
    hashTable[0].valor = 1;

    printf("%i", hashTable[0].valor);
    return 0;
}