#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[10], acm_neg=0,acm_pos=0;

    for(int i=0;i<10;i++){
        scanf("%d",&vet[i]);
    }
    for(int i =0;i<10;i++){
        if(vet[i]>0){
            acm_pos = acm_pos + vet[i];
        }
        if(vet[i]<0){
            acm_neg++;
        }
    }
    printf("possuimos %d numeros negativos", acm_neg);
    printf("a soma dos numeros positovos é: %d", acm_pos);
    return 0;
}
