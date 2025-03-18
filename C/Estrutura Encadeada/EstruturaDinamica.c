#include <stdio.h>
#include <string.h>

/*

typedef struct no{
	int ra;
	char nome[20];
}no;

struct no *A, *B;

A = NULL;
B = NULL;

A = (no*)malloc(sizeof(no));
printf("\n informe o Ra");
scanf("%d", &A -> ra);
printf("\n informe o Nome");
scanf("%s", &A -> nome);

B = (no*)malloc(sizeof(no));
printf("\n informe o Ra");
scanf("%d", &B -> ra);
printf("\n informe o Nome");
scanf("%s", &B -> nome);

A = B;
B = NULL;

printf("\n Ra do Aluno %d", A -> ra);

*/

int main(void){
typedef struct no{
int RA;
char nome[20];
} no;

struct no *A, *B;

A = NULL;
B = NULL;

for (int i = 0; i < 5; i++){

    A = (no*)malloc(sizeof(no));
    printf("\n informe o Ra");
    scanf("%d", &A -> RA);
    printf("\n informe o Nome");
    scanf("%s", &A -> nome);

    printf("\n Ra do Aluno %d", A -> RA);

}

}

