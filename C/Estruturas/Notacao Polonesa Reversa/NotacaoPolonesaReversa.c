#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct pilha{
    char caracter;
    struct pilha * next;
    struct pilha * back;
} pilha;

int opcaoMenu, valorProcura = 0;
int contador = 0;
char respostaInserir = ' ', valorInserir = ' ';
struct pilha * corrente = NULL, * auxiliar = NULL;


int main(void){

    do{

        system("cls");
        system("pause");
        printf("\n [ 1 ] Inserir elementos na pilha");
        printf("\n [ 2 ] Procurar elementos na pilha");
        printf("\n [ 3 ] Mostrar elemento no topo");
        printf("\n [ 4 ] Sair");
        printf("\n\nInforme a opcao [ ]");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu)
        {
            case 1:
                do{
                    printf("Informe o codigo \n");
                    scanf("%s", &valorInserir);

                    push(valorInserir);

                    printf("Quer continuar a inserir? \n");
                    scanf("%s", &respostaInserir);


                    respostaInserir = toupper(respostaInserir);
                }
                while(respostaInserir != 'N');
                break;

            case 2:
                printf("Insira o valor a ser procurado: \n");
                scanf("%d", &valorProcura);

                pop(valorProcura);

                system("pause");
                break;

            case 3:
                top();
                system("pause");
                break;

            case 4:
                printf("\nSaindo...\n");
                system("pause");
                exit(0);
                break;

            default :
                printf("\nOpcao invalida, tente novamente");
                system("pause");
        }
    }while(opcaoMenu != 4);

}

void top(){

    if(corrente == NULL){
        printf("A pilha não possui nenhum valor, então seu topo é Nulo. \n");
    }else{
        printf("Teste");
        printf("Valor no topo: %c \n", corrente -> caracter);
    }


}

void push(char valor){

    corrente = (pilha *)malloc(sizeof(pilha));
    corrente -> caracter = valor;
    if(auxiliar == NULL){
        corrente -> next = NULL;
        corrente -> back = NULL;
        auxiliar = corrente;
        contador = contador + 1;
    }else{
        auxiliar -> next = corrente;
        corrente -> back = auxiliar;
        corrente -> next = NULL;
        auxiliar = corrente;
        contador = contador + 1;
    }

}

void pop(char valor){

    if(corrente == NULL){
        printf("A pilha está vazia. Adicione algo antes de buscar. \n");
    }else{
        while(corrente -> caracter != valor){

            if(corrente -> back == NULL){
                corrente -> next = NULL;
                free(corrente);
                corrente = NULL;
                auxiliar = NULL;
                printf("O elemento não foi encontrado na pilha");
                contador = contador - 1;
                }

            auxiliar = auxiliar -> back;
            free(corrente);
            auxiliar -> next = NULL;
            corrente = auxiliar;
            contador = contador - 1;
        }

        if(corrente -> caracter == valor){
            auxiliar = auxiliar -> back;
            free(corrente);
            auxiliar -> next = NULL;
            corrente = auxiliar;
            printf("Valor encontrado no elemento: %i \n", contador);
            contador = contador - 1;
        }
    }
}


