#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TAM_MAX_NOME 30

typedef struct Pilha{
    char nome[TAM_MAX_NOME];
    struct Pilha * back;

} Pilha;

typedef struct Fila{
    char nome[TAM_MAX_NOME];
    struct Fila * next;

} Fila;

struct Pilha * topoPilha = NULL, * auxiliarPilha = NULL;
struct Fila * inicioFila = NULL, * fimFila = NULL, * correnteFila = NULL;

novoElementoPilha(char * dados){

    topoPilha = (Pilha*)malloc(sizeof(Pilha));
    strcpy(topoPilha -> nome, dados);
}

novoElementoFila(char * dados){

    correnteFila = (Fila*)malloc(sizeof(Fila));
    strcpy(correnteFila -> nome, dados);
    correnteFila -> next = NULL;
}

void topPilha(){
    if(topoPilha == NULL){
        printf("Topo esta vazio. \n");
        return;
    }
    printf("Topo: %s \n", topoPilha->nome);
}

void pushPilha(char * dados){

    if(topoPilha == NULL){
        novoElementoPilha(dados);
        topoPilha -> back = NULL;
    }else{

        auxiliarPilha = topoPilha;
        novoElementoPilha(dados);
        topoPilha -> back = auxiliarPilha;
    }
}

void popPilha(){
    auxiliarPilha = topoPilha -> back;
    free(topoPilha);
    topoPilha = auxiliarPilha;

}

void mostrarPilha() {
    auxiliarPilha = topoPilha;

    printf("Pilha atual (topo -> base): ");
    while (auxiliarPilha != NULL) {
        printf("%s ", auxiliarPilha->nome);
        auxiliarPilha = auxiliarPilha -> back;
    }
    printf("\n");
}

void enqueueFila(char * dados){
    if(inicioFila == NULL){
        novoElementoFila(dados);
        inicioFila = correnteFila;
        fimFila = correnteFila;
    }else{
        novoElementoFila(dados);
        fimFila -> next = correnteFila;
        fimFila = correnteFila;
    }
}

void transformar(){

    if(topoPilha == NULL){
        printf("Nao e possivel transformar para fila. A pilha esta vazia. \n");
        return;
    }

    while(topoPilha != NULL){
        enqueueFila(topoPilha -> nome);
        popPilha();
    }
}

void exibirFila(){
    if(inicioFila == NULL){
        printf("A fila esta vazia.\n");
        return;
    }

    correnteFila = inicioFila;
    while(correnteFila != NULL){
        printf("%s", correnteFila -> nome);
        correnteFila = correnteFila -> next;
    }

}

int main (){

int opcaoMenu;

char valorInserir[TAM_MAX_NOME];

char respostaInserir = ' ';

    do{

    system("cls");
    system("pause");
    printf("\n [ 1 ] Push");
    printf("\n [ 2 ] Pop");
    printf("\n [ 3 ] Topo");
    printf("\n [ 4 ] Mostrar Pilha");
    printf("\n [ 5 ] Transformar para Fila");
    printf("\n [ 6 ] Mostrar Fila");
    printf("\n [ 7 ] Sair");
    printf("\n\nInforme a opcao [ ]");
    scanf("%d", &opcaoMenu);

    switch (opcaoMenu)
        {
            case 1:
                do{
                    printf("Informe o codigo \n");
                    fflush(stdin);
                    fgets(valorInserir, TAM_MAX_NOME, stdin);
                    fflush(stdin);

                    pushPilha(valorInserir);

                    printf("Quer continuar a inserir?");
                    scanf(" %c", &respostaInserir);


                    respostaInserir = toupper(respostaInserir);
                }
                while(respostaInserir != 'N');
                break;

            case 2:

                popPilha();

                system("pause");
                break;

            case 3:
                topPilha();
                system("pause");
                break;

            case 4:
                mostrarPilha();
                system("pause");
                break;

            case 5:
                transformar();
                system("pause");
                break;

            case 6:
                exibirFila();
                system("pause");
                break;

            case 7:
                printf("\nSaindo...\n");
                system("pause");
                exit(0);
                break;

            default :
                printf("\nOpcao invalida, tente novamente");
                system("pause");
        }
    }while(opcaoMenu != 7);


    return 0;
}
