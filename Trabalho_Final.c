#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int ra;
    char nome[80];
    float n1, n2, n3, media;
}tipo_alunos;

//Q1
tipo_alunos * alocaVetor(int dim){

    tipo_alunos *alu = (tipo_alunos*) calloc(dim, sizeof(tipo_alunos*));

    return alu;

}

// Q2
tipo_alunos * realocaVetor(tipo_alunos * vetor ,int novotam){

    vetor = realloc(vetor, novotam * sizeof(tipo_alunos));

    return vetor;

}

// Q3



// Q4 -> n1
int encontraMaior(tipo_alunos){

} 

// Q -> media geral


int main(){

//A alocação inicial do vetor de alunos deve conter dimensão máxima 10
    tipo_alunos alu[10];

    alocaVetor(5);

    return 0;
}
