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

void cadastraAlunos(tipo_alunos * alunos, int pos){

    printf("Nome: \n");
    setbuf(stdin, NULL);
    fgets(alunos[pos].nome, 80, stdin);
    printf("R.A.:\n");
    scanf("%d", &alunos[pos].ra);
    printf("n1:\n");
    scanf("%f", &alunos[pos].n1);
    printf("n2:\n");
    scanf("%f", &alunos[pos].n2);
    printf("n3:\n");
    scanf("%f", &alunos[pos].n3);
    alunos[pos].media = (alunos[pos].n1 + alunos[pos].n2 + alunos[pos].n3) / 3 ;


}

// Q4 -> n1       pode ter mais de um parâmetro? SIM!
void encontraMaior( int tam, tipo_alunos alunos[tam]){

    float maiorNota = 0;
    int ramaior;

    for (int i = 0; i < tam; i++)
    {
        if (alunos[i].n1 > maiorNota)
        {
            maiorNota = alunos[i].n1;
            ramaior = alunos[i].ra;
        }
        
    }
    
    printf("O aluno com a maior nota foi %d, sendo %.2f\n", ramaior, maiorNota);

} 

// Q5 -> media geral
void encontraMenor( int tam, tipo_alunos * alunos){

    float menorMedia;
    int ramenor;

    for (int i = 0; i < tam; i++)
    {
        if (alunos[i].media < menorMedia || i == 1 )
        {
            menorMedia = alunos[i].media;
            ramenor = alunos[i].ra;
        }
        
    }

    printf("O aluno com menor media foi %d, sendo %.2f\n", ramenor, menorMedia);
    
} 

//Q6

void verificaAprovacao(tipo_alunos * alunos, int procurado, int tam){


    if (procurado == 1)
    {
        for (int i = 0; i < tam; i++)
        {
            if (alunos[i].media >=6)
            {
                printf("%d APROVADO !\n", alunos[i].ra);
            }
            
        }
    }
    if (procurado == 2)
    {
        for (int i = 0; i < tam; i++)
        {
            if (alunos[i].media < 6)
            {
                printf("%d REPROVADO !\n", alunos[i].ra);
            }
            
        }
    }

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

/////////////// Uso em testes

/*void preencheVetor(tipo_alunos * alu,int tam)
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
*/
////////////////////// MAIN
int main(){

//A alocação inicial do vetor de alunos deve conter dimensão máxima 10
    tipo_alunos *alu = (tipo_alunos*) calloc(5, sizeof(tipo_alunos));

    int tam = 0;
    int menu=10;
    int aprov;

    alocaVetor(5);

    do{

        printf("1- Alocar Vetor\n2- Realocar Vetor\n3- Cadastrar Alunos\n4- Checar maior nota\n5- Checar menor media\n6- Verificar Aprovacoes\n7- Mostrar todos os alunos\n8- Analisar performance\n0- SAIR\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:

            printf("Tamanho:\n");
            scanf("%d", &tam);
            alu = alocaVetor(tam);
            break;
        
        case 2:

            printf("Tamanho:\n");
            scanf("%d", &tam);
            alu = realocaVetor(alu, tam);
            break;

        case 3:
        
            for (int i = 0; i < tam; i++)
            {
                cadastraAlunos(alu, i);
            }
            break;

        case 4:

            encontraMaior(tam, alu);
            break;

        case 5:

            encontraMenor(tam, alu);
            break;

        case 6:

            printf("1- procurar aprovados\n2- procurar reprovados\n");
            scanf("%d", &aprov);

            verificaAprovacao(alu, aprov, tam);
            break;

        case 7:

            imprimeVetor(tam, alu);
            break;
            
        case 8:

            porcentagemAproveitamento(alu, tam);
            break;

        default:
            break;
        }

    }while (menu != 0);
    

    return 0;
}
