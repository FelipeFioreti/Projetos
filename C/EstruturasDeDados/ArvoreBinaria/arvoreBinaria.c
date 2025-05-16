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

arvore * novoTree(int dados){
    corrente = (arvore *)malloc(sizeof(arvore));
    corrente -> dados = dados;
    corrente -> left = NULL;
    corrente -> right = NULL;
    return corrente;
}

arvore * inserirTree(arvore * tree, int valor){
   if(raiz == NULL){
        raiz = novoTree(valor);
    } 
    else{

        if(tree == NULL){
            novoTree(valor);
            return corrente;
        }

        if(valor == tree -> dados){
            printf("Valor ja existe na arvore\n");
            return tree;
        }

        if(valor < tree -> dados){
            tree -> left = inserirTree(tree -> left, valor);
        }
        else{
            tree -> right = inserirTree(tree -> right, valor);
        }
    }
    return tree;
}

void visualizarTree(arvore * tree){
    if(tree != NULL){
        printf("%d ", tree -> dados);
        printf("\n");

        visualizarTree(tree -> left);

        visualizarTree(tree -> right);
    }
}

arvore * pesquisarTree(arvore * tree, int valor){
    if(tree == NULL){
        return NULL;
    }

    if(tree -> dados == valor){
        printf("Valor %d encontrado na arvore\n", valor);
        return tree;
    }

    if(valor < tree -> dados){
        pesquisarTree(tree -> left, valor);
    }
    else{
        pesquisarTree(tree -> right, valor);
    }
}


int main(void){
    char respostaInserir = 'S';
    int opcaoMenu = 0, valorInserir = 0, valorPesquisa = 0, valorRemove = 0;

    do{

        system("cls");
        system("pause");
        printf("\n [ 1 ] Inserir");
        printf("\n [ 2 ] Visualizar");
        printf("\n [ 3 ] Pesquisar");
        printf("\n [ 4 ] Sair");
        printf("\n\nInforme a opcao [ ]");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu)
        {
            case 1:
                do{
                    printf("Informe o codigo \n");
                    scanf("%d", &valorInserir);

                    inserirTree(raiz, valorInserir);

                    printf("Quer continuar a inserir?");
                    scanf(" %c", &respostaInserir);


                    respostaInserir = toupper(respostaInserir);
                }
                while(respostaInserir != 'N');
                break;

            case 2:
                printf("Visualizando a arvore...\n");
                printf("\n\n");
                visualizarTree(raiz);
                system("pause");
                break;

            case 3:
            
                printf("Informe o valor a ser pesquisado\n");
                scanf("%d", &valorPesquisa);

                printf("Pesquisando na arvore...\n");
                printf("\n\n");
                if(pesquisarTree(raiz, valorPesquisa) == NULL){
                    printf("Valor %d nao encontrado na arvore\n", valorPesquisa);
                }
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

