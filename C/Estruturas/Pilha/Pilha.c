#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct pilha{
    int dados;
    struct pilha * back;
} pilha;

int opcaoMenu, valorProcura = 0, valorInserir = 0;
char respostaInserir = ' ';
struct pilha * topo = NULL, * auxiliar = NULL;

void novoElemento(int valor){
    topo = (pilha *)malloc(sizeof(pilha));
    topo -> dados = valor;
}

void top(){

    if(topo == NULL){
        printf("A pilha não possui nenhum valor, então seu topo é Nulo. \n");
    }else{
        printf("Valor no topo: %i \n", topo -> dados);
    }
}

void push(int valor){

    if(topo == NULL){
        novoElemento(valor);
        topo -> back = NULL;
        auxiliar = topo;
    }else{
        auxiliar = topo;
        novoElemento(valor);
        topo -> back = auxiliar;
        auxiliar = topo;
    }
    
}

void pop(){
    if(topo == NULL){
        printf("A pilha está vazia.\n");
    } else {
        printf("Removendo o elemento: %d\n", topo->dados);
        auxiliar = topo;
        topo = topo->back;
        free(auxiliar);
    }
}

void mostrarPilha() {
    pilha *temp = topo;
    printf("Pilha atual (topo -> base): ");
    while (temp != NULL) {
        printf("%d ", temp->dados);
        temp = temp->back;
    }
    printf("\n");
}

void liberarPilha() {
    while (topo != NULL) {
        pop(); 
    }
}

int main(void){

    do{

        system("cls");
        system("pause");
        printf("\n [ 1 ] Push");
        printf("\n [ 2 ] Pop");
        printf("\n [ 3 ] Topo");
        printf("\n [ 4 ] Mostrar Pilha");
        printf("\n [ 5 ] Sair");
        printf("\n\nInforme a opcao [ ]");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu)
        {
            case 1:
                do{
                    printf("Informe o codigo \n");
                    scanf("%d", &valorInserir);

                    push(valorInserir);

                    printf("Quer continuar a inserir?");
                    scanf(" %c", &respostaInserir);


                    respostaInserir = toupper(respostaInserir);
                }
                while(respostaInserir != 'N');
                break;

            case 2:

                pop();

                system("pause");
                break;

            case 3:
                top();
                system("pause");
                break;

            case 4:
                mostrarPilha();
                system("pause");
                break;

            case 5:
                printf("\nSaindo...\n");
                liberarPilha();
                system("pause");
                exit(0);
                break;

            default :
                printf("\nOpcao invalida, tente novamente");
                system("pause");
        }
    }while(opcaoMenu != 5);

}

