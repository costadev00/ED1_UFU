#include <stdio.h>
#include <stdlib.h>

int main()
{
    float trab_lab=0,aval_sems=0,exam_final=0,nota_final=0;
    char conceito;
    scanf("%f",&trab_lab);
    trab_lab = trab_lab*0.2;
    scanf("%f",&aval_sems);
    aval_sems = aval_sems * 0.3;
    scanf("%f",&exam_final);
    exam_final = exam_final * 0.5;
    nota_final = trab_lab + aval_sems + exam_final;
    if(nota_final>=8.01 && nota_final<=10.0){
        conceito = 'A';
    }
    else if(nota_final>=7.01 && nota_final<=8.0){
        conceito = 'B';
    }
    else if(nota_final>=6.01 && nota_final<=7.0){
        conceito = 'C';
    }
    else if(nota_final>=5.01 && nota_final<=6.0){
        conceito = 'D';
    }
    else {
        conceito = 'E';
    }
    printf("%f", nota_final);
    printf("%c", conceito);
    return 0;
}
