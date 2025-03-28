#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct no{
    int codigo;
    char nome[20];
    struct no * prox;
    struct no * back;
} no;

int cod, op;
char resp;
char nomePessoa[20];
struct no * corrente = NULL, * auxiliar = NULL, * inicio = NULL, * fim = NULL;

void inserir(int numero){
    struct no * pont;
    auxiliar = corrente;
    corrente = (no*)malloc(sizeof(no));
    corrente -> codigo = numero;

    strcpy(&corrente -> nome, &nomePessoa);

    if (inicio == NULL)
    {
        inicio = corrente;
        auxiliar = corrente;
        fim = corrente;
        corrente -> back = NULL;
        corrente -> prox = NULL;

    }else{

        if(corrente -> codigo <= inicio -> codigo){
            corrente -> prox = inicio;
            inicio -> back = corrente;
            inicio = corrente;
        }else{

            pont = inicio;

            while(corrente -> codigo > pont -> codigo){
                auxiliar = pont;

                if (pont -> prox == NULL) {
                    auxiliar -> prox = corrente;
                    corrente -> back = auxiliar;
                    corrente -> prox = NULL;
                    auxiliar = corrente;
                    fim = corrente;
                };

                pont = pont -> prox;
            }

            if((auxiliar -> codigo < corrente -> codigo) && (corrente -> codigo < pont -> codigo)){
                corrente -> prox = pont;
                corrente -> back = auxiliar;
                auxiliar -> prox = corrente;
            }


        }
    }
}

void exibir(){

    printf("Imprimir do início ao fim [1] ou do fim ao início [2] ? \n");
    scanf("%d", &resp);

    switch(resp){
        case 1:
            auxiliar = inicio;
            while (auxiliar != NULL)
            {
                printf("Nome: %s \n", auxiliar -> nome);
                printf("Codigo: %d \n\n", auxiliar -> codigo);
                auxiliar = auxiliar -> prox;
            }
            break;
        case 2:
            auxiliar = fim;
            while (auxiliar != NULL)
            {
                printf("Nome: %s \n", auxiliar -> nome);
                printf("Codigo: %d \n\n", auxiliar -> codigo);
                auxiliar = auxiliar -> back;
            }
            break;
        default:
            printf("Resposta inválida.");
    }


}

void excluir(){
    auxiliar = inicio;
    int cont = 0;
    int elem;
    struct no * pont;

    printf("Digite o elemento a ser deletado:");
    scanf("%d", &elem);

    if(elem == 0){
    auxiliar = inicio -> prox;
    free(inicio);
    inicio = auxiliar;
    }else{
        while(true){
            if(auxiliar -> prox == NULL){
                printf("Elementro invalido.\n");
                break;
            }
            else if((cont + 1) == elem){
                pont = auxiliar;
                auxiliar = auxiliar -> prox;

                if(auxiliar -> prox == NULL){
                    pont -> prox = NULL;
                    free(auxiliar);
                    corrente = pont;
                }else{
                    pont -> prox = auxiliar -> prox;
                    free(auxiliar);
                }
                break;
            }else{
                auxiliar = auxiliar -> prox;
                cont++;
            }
        }
    }
}


int main(void){


do{

    system("cls");
    system("pause");
    printf("\n [ 1 ] Inserindo elementos na lista");
    printf("\n [ 2 ] Exibindo os elementos da lista");
    printf("\n [ 3 ] Removendo os elementos da lista");
    printf("\n [ 4 ] Classificar os elementos da lista");
    printf("\n [ 5 ] Sair");
    printf("\n\nInforme a opcao [ ]");
    scanf("%d", &op);

    switch (op)
    {
        case 1:
            do{
                printf("Informe o codigo \n");
                scanf("%d", &cod);

                printf("Informe o nome \n");
                scanf("%s", &nomePessoa);

                inserir(cod);

                printf("Quer continuar a inserir? \n");
                scanf("%s", &resp);


                resp = toupper(resp);
            }while(resp != 'N');
            break;

        case 2:
            exibir();
            system("pause");
            break;

        case 3:
            excluir();
            system("pause");
            break;

        case 4:
            printf("Funcionalidade está sendo implementada./n");
            system("pause");
            break;

        case 5:
            printf("\nSaindo...\n");
            system("pause");
            exit(0);
            break;

        default :
            printf("\nOpcao invalida, tente novamente");
            system("pause");
    }
}while(op != 4);


}

