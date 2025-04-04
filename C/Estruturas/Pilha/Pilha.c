#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct pilha{
    int dados;
    struct pilha * next;
    struct pilha * back;
} pilha;

int opcaoMenu, valorProcura = 0, valorInserir = 0;
int contador = 0;
char respostaInserir = ' ';
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
                    scanf("%d", &valorInserir);

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
        printf("Valor no topo: %i \n", corrente -> dados);
    }


}

void push(int valor){

    if(contador > 5){
        printf("Stack Overflow.\n");
        printf("A pilha está cheia.");
    }else{
        corrente = (pilha *)malloc(sizeof(pilha));
        corrente -> dados = valor;
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

}

void pop(int valor){

    if(corrente == NULL){
        printf("A pilha está vazia. Adicione algo antes de buscar. \n");
    }else{
        while(corrente -> dados != valor){

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

        if(corrente -> dados == valor){
            auxiliar = auxiliar -> back;
            free(corrente);
            auxiliar -> next = NULL;
            corrente = auxiliar;
            printf("Valor encontrado no elemento: %i \n", contador);
            contador = contador - 1;
        }
    }
}


