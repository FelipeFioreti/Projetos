#ifndef LISTAENCADEADA_H

#define LISTAENCADEADA_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct no{
    int codigo;
    struct no * next;
    struct no * back;
} no;


struct no * listaEncadeadaCorrente = NULL, * listaEncadeadaInicio = NULL, * listaEncadeadaFim = NULL;

void novoElemento(int numero){
    listaEncadeadaCorrente = (no*)malloc(sizeof(no));
    listaEncadeadaCorrente -> codigo = numero;
}

void inserir(int numero){
    novoElemento(numero);

    if (listaEncadeadaInicio == NULL)
    {
        listaEncadeadaInicio = listaEncadeadaCorrente;
        listaEncadeadaFim = listaEncadeadaCorrente;
        listaEncadeadaCorrente -> back = NULL;
        listaEncadeadaCorrente -> next = NULL;

    }else{

        listaEncadeadaCorrente -> back = listaEncadeadaFim;
        listaEncadeadaFim -> next = listaEncadeadaCorrente;
        listaEncadeadaCorrente -> next = NULL;
        listaEncadeadaFim = listaEncadeadaCorrente;

    }
}

void exibir(int escolha){

    if(escolha < 1 && escolha > 2){
        return;
    }

    switch(escolha){
        case 1:
            listaEncadeadaCorrente = listaEncadeadaInicio;
            while (listaEncadeadaCorrente != NULL)
            {
                printf("Codigo: %d \n\n", listaEncadeadaCorrente -> codigo);
                listaEncadeadaCorrente = listaEncadeadaCorrente -> next;
            }
            break;
        case 2:
            listaEncadeadaCorrente = listaEncadeadaFim;
            while (listaEncadeadaCorrente != NULL)
            {
                printf("Codigo: %d \n\n", listaEncadeadaCorrente -> codigo);
                listaEncadeadaCorrente = listaEncadeadaCorrente -> back;
            }
            break;
        default:
            printf("Resposta invalida.");
    }


}

void excluir(){
    listaEncadeadaCorrente = listaEncadeadaInicio;

    int valor = 0;
    bool achou = false;


    printf("Digite o valor a ser deletado:");
    scanf("%d", &valor);

    if(listaEncadeadaInicio == NULL){
        printf("A lista esta vazia");

    }else{

        if(listaEncadeadaInicio -> codigo == valor){
            listaEncadeadaInicio = listaEncadeadaInicio -> next;
            free(listaEncadeadaCorrente);
            listaEncadeadaInicio -> back = NULL;
        }else{

            listaEncadeadaCorrente = listaEncadeadaCorrente -> next;
            while(listaEncadeadaCorrente != NULL && listaEncadeadaCorrente != listaEncadeadaFim){

                if(listaEncadeadaCorrente -> codigo == valor){
                    listaEncadeadaCorrente -> back -> next = listaEncadeadaCorrente -> next;
                    listaEncadeadaCorrente -> next -> back = listaEncadeadaCorrente -> back;
                    free(listaEncadeadaCorrente);
                    achou = true;
                    break;
                }
                listaEncadeadaCorrente = listaEncadeadaCorrente -> next;
            }

            if(listaEncadeadaCorrente == listaEncadeadaFim && listaEncadeadaCorrente -> codigo == valor){
                listaEncadeadaFim = listaEncadeadaFim -> back;
                listaEncadeadaFim -> next = NULL;
                free(listaEncadeadaCorrente);
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