#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct pilha{
    int dados;
    struct no * prox;
    struct no * back;
} pilha;

int op, cod = 0;
char resp = '';
struct pilha * inicio = NULL, fim = NULL; corrente = NULL, auxiliar = NULL;


void inserir(int codigo){

    corrente = (pilha *)malloc(sizeof(pilha));
    corrente -> dados = codigo;
    if(inicio = NULL){
        inicio = corrente;
        auxiliar = corrente;
        fim = corrente;
        inicio -> back = NULL;
        inicio -> prox = NULL;
    }else{
        auxiliar = inicio;
        while(auxiliar -> prox != NULL){
            auxiliar = auxiliar -> prox;
        }
        corrente -> back = auxiliar;
        auxiliar -> prox = corrente;
        fim = corrente;
    }

}

int top(){
    return fim.dados;
}

void push(){
    corrente = (pilha *)malloc(sizeof(pilha));
    corrente -> next = NULL;
    fim -> prox = corrente;
    corrente -> back = fim;
    fim = corrente;
    fim
}

void pop(){
    auxiliar = fim;
    auxiliar = auxiliar -> back;
    auxiliar -> prox = NULL;
    free(fim);
    fim = auxiliar;
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

                    inserir(cod);

                    printf("Quer continuar a inserir? \n");
                    scanf("%s", &resp);


                    resp = toupper(resp);
                }while(resp != 'N');
                break;

            case 2:
                printf("Funcionalidade está sendo implementada./n");
                system("pause");
                break;

            case 3:
                printf("Funcionalidade está sendo implementada./n");
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
