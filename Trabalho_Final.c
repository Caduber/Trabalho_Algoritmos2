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



// Q4 -> n1       pode ter mais de um parâmetro?
float encontraMaior( int tam, tipo_alunos alunos[tam]){

    float maiorNota = 0;

    for (int i = 0; i < tam; i++)
    {
        if (alunos[i].n1 > maiorNota)
        {
            maiorNota = alunos[i].n1;
        }
        
    }
    

    return maiorNota;
} 

// Q5 -> media geral
int encontraMenor( int tam, tipo_alunos * alunos){

    float menorMedia;

    for (int i = 0; i < tam; i++)
    {
        if (alunos[i].media < menorMedia || i == 1 )
        {
            menorMedia = alunos[i].media;
        }
        
    }

    return menorMedia;
    
} 

//Q6

int verificaAprovacao(){

}

//Q7

void imprimeVetor(int tam, tipo_alunos * alunos){

    for (int i = 0; i < tam; i++)
    {
        printf("Nome: %s\n", alunos[i].nome );
        printf("R.A.: %d\n", alunos[i].ra );
        printf("Nota 1: %.2f\n", alunos[i].n1 );
        printf("Nota 2: %.2f\n", alunos[i].n2 );
        printf("Nota 3: %.2f\n", alunos[i].n3 );
        printf("Media: %.2f\n\n", alunos[i].media );
        
    }
    

}

//Q8

void porcentagemAproveitamento(tipo_alunos * alunos, int tam){

    int bom=0, medio=0, abaixo=0;

    for (int i = 0; i < tam; i++)
    {
        if (alunos[i].media >= 8)
        {
            bom++;
        }
        if (alunos[i].media < 8 && alunos[i].media >= 6){
            medio++;
        }
        if (alunos[i].media < 6){
            abaixo++;
        }
    }

    printf("\nNa turma tem %d alunos com notas maiores que 80 porcento, %d alunos com notas inferiores a 80 porcento, mas na media e %d alunos com notas abaixo da media\n", bom, medio, abaixo);

}

void preencheVetor(tipo_alunos * alu,int tam)
{
    for (int i = 0; i < tam; i++)
    {
        alu[i].n1 = rand() % 11;
        alu[i].n2 = rand() % 11;
        alu[i].n3 = rand() % 11;
        alu[i].media = (alu[i].n1 + alu[i].n2 + alu[i].n3)/3 ;
        //alu[i].nome = ;
        alu[i].ra = i;
    }

}
////////////////////// MAIN
int main(){

//A alocação inicial do vetor de alunos deve conter dimensão máxima 10
    tipo_alunos alu[10];

    alocaVetor(5);
    realocaVetor(alu, 10);
    preencheVetor(alu, 10);
    imprimeVetor(10, alu);
    porcentagemAproveitamento(alu, 10);






    return 0;
}
