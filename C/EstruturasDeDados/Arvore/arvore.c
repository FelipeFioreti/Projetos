#include "listaSimples.h"
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

int verificaTree(){
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
            switch (verificaTree())
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

arvore* pesquisarTree(int valor, arvore* tree){
    if(tree == NULL){
        return NULL;
    }

    if(valor == tree -> dados){
        printf("Valor encontrado!");
        return  NULL;
    }

    if(tree != NULL){
        pesquisarTree(valor, tree -> left);
        pesquisarTree(valor, tree -> center);
        pesquisarTree(valor, tree -> right);
    }
}

void criarLista(arvore* tree){
    if(tree == NULL){
        return;
    }

    inserir(tree -> dados);

    criarLista(tree -> left);
    criarLista(tree -> center);
    criarLista(tree -> right);
}

int * QuickSort(int * array, int tamanho){

    if(tamanho < 2){
        return array;
    }

    int pivo = array[0];

    int * maiores = (int *)malloc(tamanho * sizeof(int));
    int * menores = (int *)malloc(tamanho * sizeof(int));
    int countMaior = 0;
    int countMenor = 0;

    for(int i = 1; i < tamanho; i++){
        if(array[i] <= pivo){
            menores[countMenor++] = array[i];
        }else{
            maiores[countMaior++] = array[i];
        }
    }

    int* menoresOrdenado = QuickSort(menores, countMenor);
    int* maioresOrdenado = QuickSort(maiores, countMaior);

    int* resultado = (int*)malloc(tamanho * sizeof(int));
    for (int i = 0; i < countMenor; i++) {
        resultado[i] = menoresOrdenado[i];
    }

    resultado[countMenor] = pivo;

    for (int i = 0; i < countMaior; i++) {
        resultado[countMenor + 1 + i] = maioresOrdenado[i];
    }

    
    free(menores);
    free(maiores);

    return resultado;
}

int ordenarTree(int * array, int count, arvore * tree){
    if(tree == NULL){
        return count;
    }

    tree -> dados = array[count++];

    if(tree != NULL){
        count = ordenarTree(array, count, tree->left);
        count = ordenarTree(array, count, tree -> center);
        count = ordenarTree(array, count, tree -> right);
    }

    return count;
}

void organizarTree(){
    if(raiz == NULL){
        printf("A arvore esta vazia\n");
        return;
    }

    criarLista(raiz);
    
    int count = 0;
    auxiliarLista = inicioLista;
    while(auxiliarLista != NULL){
        count++;
        auxiliarLista = auxiliarLista -> next;  
    }

    int array[count];

    auxiliarLista = inicioLista;
    for(int i = 0; i < count; i++){
        array[i] = auxiliarLista -> codigo;
        auxiliarLista = auxiliarLista -> next;
    }
    
    ordenarTree(QuickSort(array, count), 0, raiz);
    printf("A arvore foi ordenada com sucesso!");
}



int main(void){
    char respostaInserir = 'S';
    int opcaoMenu = 0, valorInserir = 0, valorPesquisa = 0;

    do{

        system("cls");
        system("pause");
        printf("\n [ 1 ] Inserir");
        printf("\n [ 2 ] Visualizar");
        printf("\n [ 3 ] Pesquisar");
        printf("\n [ 4 ] Organizar Arvore");
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
                printf("Digite o valor que quer pesquisar: \n");
                scanf("%i", &valorPesquisa);
                pesquisarTree(valorPesquisa, raiz);
                system("pause");
                break;

            case 4:
                organizarTree();
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

