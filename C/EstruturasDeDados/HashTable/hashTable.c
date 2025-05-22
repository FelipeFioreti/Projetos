#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO 26
#define TAM_MAX_NOME 100

typedef struct Table {
    char chave[TAM_MAX_NOME];
    struct Table* proximo;
} Table;

Table* hashTable[TAMANHO];

void converterParaMaiusculo(char *nome) {
    for (int i = 0; nome[i]; i++) {
        nome[i] = toupper(nome[i]);
    }
}

int hash(char c) {
    c = tolower(c); 
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    return -1; 
}

Table * novoElemento(char* nome){
    Table* novo = (Table*) malloc(sizeof(Table));
    strcpy(novo->chave, nome);
    novo->proximo = NULL;
    return novo;
}

void inserir(char* nome) {
    int indice = hash(nome[0]);
    if (indice == -1) {
        printf("Caractere inválido: %s\n", nome);
        return;
    }

    Table * novo = novoElemento(nome);
    
    if (hashTable[indice] == NULL) {
        hashTable[indice] = novo;
        return;
    }
    
    if (strcmp(novo -> chave, hashTable[indice] -> chave) == 0) {
        printf("Nao podem existir valores repetidos em uma Hash Table.\n");
        free(novo); 
        return;
    }

    
    if(strcmp(novo -> chave, hashTable[indice] -> chave) < 0){
        novo -> proximo = hashTable[indice];
        hashTable[indice] = novo;
        return;
    }

    Table * auxiliar = hashTable[indice];
    Table * corrente = auxiliar -> proximo;

    while (corrente != NULL)
    {
        if(strcmp(corrente -> chave, novo -> chave) == 0){
            printf("Nao podem existir valores repetidos em uma Hash Table. \n");
            free(novo); 
            return;
        }

        if(strcmp(corrente -> chave, novo -> chave) > 0){
            break;
        }

        auxiliar = corrente;
        corrente = corrente -> proximo;
    }

    if(corrente == NULL){
        auxiliar -> proximo = novo;
        novo -> proximo = NULL;
    }else{
        auxiliar -> proximo = novo;
        novo -> proximo = corrente;
    }

}


void imprimirHashTable() {
    for (int i = 0; i < TAMANHO; i++) {

        if (hashTable[i]) {

            printf("[%c]: ", i + 'A');
            
            Table* corrente = hashTable[i];
            
            while (corrente != NULL) {
            
                printf("%s -> ", corrente->chave);
                corrente = corrente->proximo;

            }

            printf("NULL\n");
        }
    }
}

void pesquisarHashTable(char* nome){
    int indice = hash(nome[0]);

    if (indice == -1) {
        printf("Caractere inválido: %s\n", nome);
        return;
    }

    if(hashTable[indice] == NULL){
        printf("Nenhum nome na Hash Table comeca com a letra %c \n", nome[0]);
    }else{

        Table * corrente = hashTable[indice];
        int achou = 0;

        while(corrente != NULL){
            if(strcmp(corrente -> chave, nome) == 0){
                achou = 1;
                break;
            }

            corrente = corrente -> proximo;
        }

        if(achou){
            printf("Nome encontrado. \n");
        }else{
            printf("Nome não foi encontrado. \n");
        }

    }

}

void removerHashTable(char * nome){
   int indice = hash(nome[0]);

    if (indice == -1) {
        printf("Caractere inválido: %s\n", nome);
        return;
    }

    if(hashTable[indice] == NULL){
        printf("Nenhum nome na Hash Table comeca com a letra %c \n", nome[0]);
    }else{
        
        Table * corrente = hashTable[indice];

        if (strcmp(hashTable[indice] -> chave, nome) == 0) {
            hashTable[indice] = corrente -> proximo;
            free(corrente);
            printf("Nome removido com sucesso.\n");
            return;
        }

        Table * auxiliar = corrente;
        corrente = corrente -> proximo;
        int achou = 0;

        while(corrente != NULL){
            if(strcmp(corrente -> chave, nome) == 0){
                auxiliar -> proximo = corrente -> proximo;
                free(corrente);
                achou = 1;
                break;
            }

            auxiliar = corrente;
            corrente = corrente -> proximo;
        }

        if(achou){
            printf("Nome removido com sucesso.\n");
        }else{
            printf("Nome não foi encontrado.\n");
        }

    }

}

void liberarHashTable() {
    for (int i = 0; i < TAMANHO; i++) {
        Table* atual = hashTable[i];
        while (atual != NULL) {
            Table* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
}

int main() {

    for(int i = 0; i < TAMANHO; i++){
        hashTable[i] = NULL;
    }

    int opcaoMenu = 0;

    // Inserir
    char nomeInserir[TAM_MAX_NOME];   
    char respostaInserir = 'S';

    // Pesquisar
    char nomePesquisar[TAM_MAX_NOME];

    // Remover
    char nomeRemover[TAM_MAX_NOME];

    do{

        system("cls");
        system("pause");
        printf("\n [ 1 ] Inserir");
        printf("\n [ 2 ] Visualizar");
        printf("\n [ 3 ] Pesquisar");
        printf("\n [ 4 ] Remover");
        printf("\n [ 5 ] Sair");
        printf("\n\nInforme a opcao [ ]");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu)
        {
            case 1:
                do {
                    printf("\nInforme o nome: \n");
                    
                    fflush(stdin);
                    fgets(nomeInserir, TAM_MAX_NOME, stdin);
                    fflush(stdin);

                    nomeInserir[strcspn(nomeInserir, "\n")] = '\0';

                    converterParaMaiusculo(nomeInserir);

                    inserir(nomeInserir);

                    printf("Quer continuar a inserir? (S/N): \n");
                    scanf(" %c", &respostaInserir);
                    respostaInserir = toupper(respostaInserir);

                } while (respostaInserir != 'N');
                break;
            case 2:
                imprimirHashTable();
                system("pause");
                break;

            case 3:
                printf("Informe o nome que quer pesquisar: \n");
                
                fflush(stdin);
                fgets(nomePesquisar, TAM_MAX_NOME, stdin);
                fflush(stdin);

                nomePesquisar[strcspn(nomePesquisar, "\n")] = '\0';

                converterParaMaiusculo(nomePesquisar);

                pesquisarHashTable(nomePesquisar);

                system("pause");
                break;

            case 4:
                printf("Informe o nome que quer remover: \n");
                
                fflush(stdin);
                fgets(nomeRemover, TAM_MAX_NOME, stdin);
                fflush(stdin);

                nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

                converterParaMaiusculo(nomeRemover);

                removerHashTable(nomeRemover);

                system("pause");
                break;

            case 5:
                printf("\nSaindo...\n");
                system("pause");
                liberarHashTable();
                exit(0);
                break;

            default :
                printf("\nOpcao invalida, tente novamente \n");
                system("pause");
                break;
        }
    }while(opcaoMenu != 5);

    return 0;
}
