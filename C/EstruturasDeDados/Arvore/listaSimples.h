#ifndef LISTASIMPLES_H

#define LISTASIMPLES_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct no{
    int codigo;
    struct no * next;
} no;


struct no * correnteLista = NULL, * inicioLista = NULL, * auxiliarLista = NULL, * fimLista = NULL;

void novoElemento(int numero){
    correnteLista = (no*)malloc(sizeof(no));
    correnteLista -> codigo = numero;
}

void inserir(int numero){
    novoElemento(numero);

    if (inicioLista == NULL)
    {
        inicioLista = correnteLista;
        fimLista = correnteLista;
        correnteLista -> next = NULL;

    }else{

        fimLista -> next = correnteLista;
        correnteLista -> next = NULL;
        fimLista = correnteLista;
    }
}

void exibir(){
    int resp = 0;

    correnteLista = inicioLista;
    while (correnteLista != NULL)
    {
        printf("Codigo: %d \n\n", correnteLista -> codigo);
        correnteLista = correnteLista -> next;
    }
}

void excluir(){
    correnteLista = inicioLista;

    int valor = 0;
    bool achou = false;


    printf("Digite o valor a ser deletado:");
    scanf("%d", &valor);

    if(inicioLista == NULL){
        printf("A lista esta vazia");

    }else{

        if(inicioLista -> codigo == valor){
            inicioLista = inicioLista -> next;
            free(correnteLista);
        }else{;
            auxiliarLista = correnteLista;
            correnteLista = correnteLista -> next;
            while(correnteLista != NULL && correnteLista != fimLista){

                if(correnteLista -> codigo == valor){
                    auxiliarLista -> next = correnteLista -> next;
                    free(correnteLista);
                    achou = true;
                    break;
                }
                auxiliarLista = correnteLista;
                correnteLista = correnteLista -> next;
            }

            if(correnteLista == fimLista && correnteLista -> codigo == valor){
                auxiliarLista -> next = NULL;
                fimLista = auxiliarLista;
                free(correnteLista);
                achou = true;
            }

            if(achou){
                printf("Elemento apagado");
            }else{
                printf("Elemento não encontrado na lista");
            }
        }
    }
}

#endif
