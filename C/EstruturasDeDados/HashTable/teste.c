#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO_TABELA 26
#define TAM_MAX_NOME 100

// Estrutura de um nó da lista
typedef struct No {
    char nome[TAM_MAX_NOME];
    struct No* proximo;
} No;

// A tabela hash: array de ponteiros para listas (uma para cada letra)
No* tabela[TAMANHO_TABELA];

// Função hash: mapeia a primeira letra para um índice de 0 a 25
int hash(char c) {
    c = tolower(c); // considerar letras minúsculas
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    return -1; // caractere inválido
}

// Inserir nome na hash table
void inserir(char* nome) {
    int indice = hash(nome[0]);
    if (indice == -1) {
        printf("Caractere inválido: %s\n", nome);
        return;
    }

    // Criar novo nó
    No* novo = (No*) malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->proximo = NULL;

    // Inserir na lista da posição correta
    if (tabela[indice] == NULL) {
        tabela[indice] = novo;
    } else {
        // Insere no início (ou você pode ordenar se quiser)
        novo->proximo = tabela[indice];
        tabela[indice] = novo;
    }
}

// Imprimir a tabela
void imprimirTabela() {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        printf("[%c]: ", i + 'A');
        No* atual = tabela[i];
        while (atual != NULL) {
            printf("%s -> ", atual->nome);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

// Liberar memória
void liberarTabela() {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        No* atual = tabela[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
}

int main() {
    inserir("Ana");
    inserir("Amanda");
    inserir("Bruno");
    inserir("Carlos");
    inserir("alice");
    inserir("bob");

    imprimirTabela();

    liberarTabela();
    return 0;
}
