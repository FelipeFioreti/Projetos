#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct no{

    int nr;
    char nome[10];
    struct no * next;

} no;

struct no * corrente = NULL,* auxiliar = NULL, * fim = NULL, * inicio = NULL;
int elementosInseridos = 0;

int gerarNumero(){
    return rand() % 10;
}

void novoElemento(int num, char * nome){
    corrente = (no*)malloc(sizeof(no));
    corrente -> nr = num;
    strcpy(corrente -> nome, nome);
    corrente -> next = NULL;
}

void inserir(int num, char * nome){

    if(inicio == NULL){
        novoElemento(num, nome);
        inicio = corrente;
        fim = corrente;
        elementosInseridos++;
    }else{
        novoElemento(num, nome);
        fim -> next = corrente;
        fim = corrente;
        elementosInseridos++;
    }
}

void sortear(int numero){
    auxiliar = inicio;
    corrente = inicio -> next;
    numero--;


    while(numero != 0){
        auxiliar = corrente;
        corrente = corrente -> next;
        numero--;
    }

    auxiliar -> next = corrente -> next;
    free(corrente);
}

int main(){
    int count = 1;
    int numeroSorteado = 0;

    srand(time(NULL));

    inserir(count++, "William");
    inserir(count++, "Wagner");
    inserir(count++, "Jonas");
    inserir(count++, "Toni");
    inserir(count++, "Ana");
    inserir(count++, "Diogenes");
    inserir(count++, "Perroti");
    fim -> next = inicio;

    while(fim -> next != NULL){
        numeroSorteado = gerarNumero();
        sortear(1);
    }

    printf("A pessoa escolhida foi: %s", fim -> nome);
    printf("Seu numero e: %i", fim -> nr);

    return 0;
}
