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



void novoTree(int dados){
    corrente = (arvore *)malloc(sizeof(arvore));
    corrente -> dados = dados;
    corrente -> left = NULL;
    corrente -> center = NULL;
    corrente -> right = NULL;
}

int verificaTree(arvore* tree){
    int opcaoInserir = 0;
    
    printf("Escolha uma opcao para inserir o dado: ");
    printf("\n[ 1 ] Esquerda\n[ 2 ] Centro\n[ 3 ] Direita\n");

    do{
        printf("Por favor, escolha uma opcao de 1 a 3\n");
        printf("\nInforme a opcao [ ]: ");
        scanf("%d", &opcaoInserir);
        system("cls");
    }while (opcaoInserir < 1 || opcaoInserir > 3);
 
    return opcaoInserir;
    
}

void inserirTree(int dados){
    if(raiz == NULL){
        novoTree(dados);
        raiz = corrente;
        auxiliar = corrente;
    }else{
        int opcaoInserir = 0;
        corrente = raiz;
        while (corrente != NULL){
            auxiliar = corrente;
            switch (verificaTree(corrente))
            {
                case 1:
                    corrente = corrente -> left;
                    opcaoInserir = 1;
                    break;
                case 2:
                    corrente = corrente -> center;
                    opcaoInserir = 2;
                    break;
                case 3:
                    corrente = corrente -> right;
                    opcaoInserir = 3;
                    break;
                default:
                    printf("Opcao invalida, tente novamente\n");
                    system("pause");
                    system("cls");
                    break;
            }
            
        }

        novoTree(dados);
        
        if(opcaoInserir == 1){
            auxiliar -> left = corrente;
        }
        
        if (opcaoInserir == 2){
            auxiliar -> center = corrente;
        }
        
        if (opcaoInserir == 3){
            auxiliar -> right = corrente;
        }
             
    }

}

arvore* visualizarTree(arvore* tree){
    if(tree == NULL){
        return NULL;
    }

    printf("\n    %d    ", tree -> dados);
    printf("\n -------  ");

    if(tree != NULL){
        printf("\n|  Esquerda |\n");
        visualizarTree(tree -> left);
        printf("\n|  Centro   |\n");
        visualizarTree(tree -> center);
        printf("\n|  Direita  |\n");
        visualizarTree(tree -> right);
    }
}

int main(void){
    int opcaoMenu = 0, valorInserir = 0;
    char respostaInserir = 'S';

    do{

        system("cls");
        system("pause");
        printf("\n [ 1 ] Inserir");
        printf("\n [ 2 ] Visualizar");
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

                    inserirTree(valorInserir);

                    printf("Quer continuar a inserir?");
                    scanf(" %c", &respostaInserir);


                    respostaInserir = toupper(respostaInserir);
                }
                while(respostaInserir != 'N');
                break;

            case 2:
                printf("\nVisualizando a arvore...\n");
                visualizarTree(raiz);
                system("pause");
                break;

            case 3:
                system("pause");
                break;

            case 4:
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
    }while(opcaoMenu != 5);

}

