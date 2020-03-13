#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet1[10], j=0,x,flag;
    do{
    flag=0;
        scanf("%d",&x);
        if(j==0){
            vet1[j] = x;
            j++;
        }
        else{
            for(int k=0;k<=j;k++){
                if(vet1[k] == x){
                flag = 1;
                }

            }
            if(flag == 0){
                vet1[j] = x;
                j++;
            }
            else{
                printf("numero ja existe insira novamente\n");
            }
        }
    }while(j<10);

    return 0;
}
