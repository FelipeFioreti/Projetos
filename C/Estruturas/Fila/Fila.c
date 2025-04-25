#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct fila{

    int codigo;
    struct fila * next;

} fila;

struct fila * fim = NULL, * corrente = NULL, * inicio = NULL;

void novoElemento(int valor){
    corrente = (fila*)malloc(sizeof(fila));
    corrente -> codigo = valor;
    corrente -> next = NULL;
}

void enqueue(int valor){
    novoElemento(valor);
    if(inicio == NULL)
    {
        inicio = corrente;
        fim = corrente;
    }else{
         fim -> next = corrente;
         fim = corrente;
    }
}

void dequeue(){
    if(inicio == NULL){
        printf("A Fila esta vazia \n");
    }

    corrente = inicio;
    inicio = inicio -> next;
    free(corrente);

}

void seaqueue(int valor){
    int count = 0;
    bool naoAchou = true;

    if(inicio == NULL){
        printf("A Fila esta vazia. \n");
    }

    corrente = inicio;
    while(corrente != NULL ){
        if(corrente -> codigo == valor){
            printf("Codigo encontrado no indice: %i \n", count);
            naoAchou = false;
            break;
        }
        count++;
        corrente = corrente -> next;
    }

    if(naoAchou){
        printf("O codigo nao foi encontrado na Fila. \n");
    }
}

void exibir(){

    int count = 0;
    corrente = inicio;

    if(inicio == NULL){
        return;
    }

    while(corrente != NULL){
        printf("Elemento %i: %i \n" , count, corrente -> codigo);
        count++;
        corrente = corrente -> next;
    }

}


void liberarFila(){
    corrente = inicio;

    while(corrente != NULL){
        dequeue();
    }
}


int main(){
int opcaoMenu = 0, valorEnqueue = 0, valorSeaqueue = 0;
char respostaEnqueue = ' ';


do{

        system("cls");
        system("pause");
        printf("\n [ 1 ] Enqueue");
        printf("\n [ 2 ] Dequeue");
        printf("\n [ 3 ] Seaqueue");
        printf("\n [ 4 ] Mostrar Fila");
        printf("\n [ 5 ] Sair");
        printf("\n\n Informe a opcao [ ]");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu)
        {
            case 1:
                do{
                    printf("Informe o codigo \n");
                    scanf("%d", &valorEnqueue);

                    enqueue(valorEnqueue);

                    printf("Quer continuar a inserir? \n");
                    scanf(" %c", &respostaEnqueue);


                    respostaEnqueue = toupper(respostaEnqueue);
                }
                while(respostaEnqueue != 'N');
                break;

            case 2:

                dequeue();

                system("pause");
                break;

            case 3:

                printf("Informe o valor a ser pesquisado: \n");
                scanf("%i", &valorSeaqueue);

                seaqueue(valorSeaqueue);


                system("pause");
                break;

            case 4:

                // Apenas para ver se esta funcionando corretamente.
                exibir();
                system("pause");

                break;

            case 5:
                printf("\nSaindo...\n");
                liberarFila();
                system("pause");
                exit(0);
                break;

            default :
                printf("\nOpcao invalida, tente novamente \n");
                system("pause");
        }
    }while(opcaoMenu != 5);

    return 0;
}
