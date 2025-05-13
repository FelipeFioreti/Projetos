#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct arvore{
    int dados;
    struct arvore * left;
    struct arvore * right;
} arvore;

struct arvore * raiz = NULL, * auxiliar = NULL, * corrente = NULL;

void novoTree(int dados){
    corrente = (arvore *)malloc(sizeof(arvore));
    corrente -> dados = dados;
    corrente -> left = NULL;
    corrente -> right = NULL;
}

arvore * inserirTree(arvore * tree, int valor){
    if(raiz == null){
        novoTree(valor);
        raiz = corrente;
    }else{

        if(tree == NULL){
            return tree;
        }

        auxiliar = tree;
        corrente = tree;
        if(tree -> dados == valor){
            printf("Nao podem ser inseridos valores repetidos.");
            return;
        }

        if(tree -> dados > valor){
            novoTree(valor);
            if(inserirTree(corrente -> left, valor) == NULL){
                auxiliar -> left = corrente;
            }
        }
    }
}


int main(void){
    char respostaInserir = 'S';
    int opcaoMenu = 0, valorInserir = 0, valorPesquisa = 0, valorRemove = 0;

    do{

        system("cls");
        system("pause");
        printf("\n [ 1 ] Inserir");
        printf("\n [ 2 ] Sair");
        printf("\n\nInforme a opcao [ ]");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu)
        {
            case 1:
                do{
                    printf("Informe o codigo \n");
                    scanf("%d", &valorInserir);

                    inserirTree(valorInserir);

                    printf("Quer continuar a inserir?");
                    scanf(" %c", &respostaInserir);


                    respostaInserir = toupper(respostaInserir);
                }
                while(respostaInserir != 'N');
                break;

            case 2:
                printf("\nSaindo...\n");
                system("pause");
                exit(0);
                break;

            default :
                printf("\nOpcao invalida, tente novamente");
                system("pause");
        }
    }while(opcaoMenu != 2);

}

