#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int codigo;
    struct no * next;
    struct no * back;
} no;


struct no * corrente = NULL, * inicio = NULL, * fim = NULL;

void novoElemento(int numero){
    corrente = (no*)malloc(sizeof(no));
    corrente -> codigo = numero;
}

void inserir(int numero){
    novoElemento(numero);

    if (inicio == NULL)
    {
        inicio = corrente;
        fim = corrente;
        corrente -> back = NULL;
        corrente -> next = NULL;

    }else{

        corrente -> back = fim;
        fim -> next = corrente;
        corrente -> next = NULL;
        fim = corrente;

    }
}

void exibir(){
    int resp = 0;

    printf("Imprimir do inicio ao fim [1] ou do fim ao inicio [2] ? \n");
    scanf("%d", &resp);

    switch(resp){
        case 1:
            corrente = inicio;
            while (corrente != NULL)
            {
                printf("Codigo: %d \n\n", corrente -> codigo);
                corrente = corrente -> next;
            }
            break;
        case 2:
            corrente = fim;
            while (corrente != NULL)
            {
                printf("Codigo: %d \n\n", corrente -> codigo);
                corrente = corrente -> back;
            }
            break;
        default:
            printf("Resposta invalida.");
    }


}

void excluir(){
    corrente = inicio;

    int valor = 0;
    bool achou = false;


    printf("Digite o valor a ser deletado:");
    scanf("%d", &valor);

    if(inicio == NULL){
        printf("A lista esta vazia");

    }else{

        if(inicio -> codigo == valor){
            inicio = inicio -> next;
            free(corrente);
            inicio -> back = NULL;
        }else{

            corrente = corrente -> next;
            while(corrente != NULL && corrente != fim){

                if(corrente -> codigo == valor){
                    corrente -> back -> next = corrente -> next;
                    corrente -> next -> back = corrente -> back;
                    free(corrente);
                    achou = true;
                    break;
                }
                corrente = corrente -> next;
            }

            if(corrente == fim && corrente -> codigo == valor){
                fim = fim -> back;
                fim -> next = NULL;
                free(corrente);
                achou = true;
            }


            if(achou){
                printf("Elemento apagado");
            }else{
                printf("Elemento não encontrado na lista");
            }
        }
    }
}

int main(){
int cod = 0, op = 0;
char resp = ' ';


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
            exibir();
            system("pause");
            break;

        case 3:
            excluir();
            system("pause");
            break;

        case 4:
            printf("Funcionalidade est� sendo implementada./n");
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



return 0;
}


