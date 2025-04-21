#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct pilha{
    char dados;
    struct pilha * back;
} pilha;

bool caracterDesconhecido = false;
struct pilha * topo = NULL, * auxiliar = NULL;

void novoElemento(char valor){
    topo = (pilha *)malloc(sizeof(pilha));
    topo -> dados = valor;
}

char top(){

    return topo ? topo->dados : '\0';
    
}

void push(char valor){

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
        
    } else {
        auxiliar = topo;
        topo = topo->back;
        free(auxiliar);
    }
}

int procedencia(char elem){
    if(elem == '+' || elem == '-'){
        return 1;
    }

    if(elem == '*' || elem == '/'){
        return 2;
    }

    return 0;
}

void liberarPilha() {
    while (topo != NULL) {
        pop(); 
    }
}

void npr(char valor[256]){
    char resultado[256] = {' '};
    int quantidadeNumero = 0;
    int countResultado = 0;
    
    for(int i = 0; i < strlen(valor); i++){
        
        if(isalnum(valor[i])){
            resultado[countResultado++] = valor[i];
            continue;
        }

        if(valor[i] == '('){
            push(valor[i]);
            continue;
        }

        if(valor[i] == ')'){
            while (top() != '(' && topo != NULL){

                resultado[countResultado++] = top();;
                pop();

            }
            pop();
            continue;
        }

        if(valor[i] == '+' || valor[i] == '-' || valor[i] == '*' || valor[i] == '/'){
            while (topo != NULL && procedencia(top()) >= procedencia(valor[i]))
            {
                resultado[countResultado++] = top();
                pop();
            }
            push(valor[i]);
            continue;
        }

        caracterDesconhecido = true;
        break;

    }

    if(caracterDesconhecido){
        strcpy(resultado, "Caracter desconhecido inserido na expressao.");
    }else{
        while (topo != NULL)
        {
            resultado[countResultado] = top();
            countResultado++;
            pop();
        }
    }

    printf("Resultado: %s \n", resultado);

    liberarPilha();

}

int main(void){
    int opcaoMenu = 0;
    char expressao[256];
    do{

        system("cls");
        system("pause");
        printf("\n [ 1 ] Notacao Polonesa Reversa");
        printf("\n [ 2 ] Sair");
        printf("\n\nInforme a opcao [ ]");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu)
        {
            case 1:
                printf("Informe a expressao \n");

                scanf("%s", &expressao);

                npr(expressao);

                system("pause");
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

