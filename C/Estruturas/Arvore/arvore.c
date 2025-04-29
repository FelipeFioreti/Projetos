#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct arvore{
    int dados;
    struct arvore * left;
    struct arvore * center;
    struct arvore * right;
} arvore;

struct arvore * raiz = NULL, * auxiliar = NULL, * corrente = NULL;



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


void novoTree(int dados){
    corrente = (arvore *)malloc(sizeof(arvore));
    corrente -> dados = dados;
    corrente -> left = NULL;
    corrente -> center = NULL;
    corrente -> rigth = NULL;
}

void inserirTree(int dados){
    novoTree(dados);
    if(raiz == NULL){
        raiz = corrente;
        auxiliar = corrente;
    }else{
        auxiliar = raiz;
    }


}
