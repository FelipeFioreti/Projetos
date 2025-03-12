#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
typedef struct no{
    int codigo;
    struct no * prox;
} no;
int cod, op;
char resp;
struct no * corrente = NULL, * auxiliar = NULL, * inicio = NULL;

void inserir(int numero){
    struct no * pont;
    auxiliar = corrente;
    corrente = (no*)malloc(sizeof(no));
    corrente -> codigo = numero;

    if (inicio == NULL)
    {

        inicio = corrente;
        auxiliar = corrente;

    }else{

        if(corrente -> codigo <= inicio -> codigo){
            corrente -> prox = inicio;
            inicio = corrente;
        }else{

            pont = inicio;

            while(corrente -> codigo > pont -> codigo){

                if(pont -> prox == NULL){
                    auxiliar -> prox = corrente;
                    corrente -> prox = NULL;
                    auxiliar = corrente;
                }

                auxiliar = pont;
                pont = pont -> prox;
            }

            corrente -> prox = auxiliar -> prox;
            auxiliar -> prox = corrente;

        }
    }
}

void exibir(){
    auxiliar = inicio;
    while (auxiliar != NULL)
    {
        printf("%d ", auxiliar -> codigo);
        auxiliar = auxiliar -> prox;
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

