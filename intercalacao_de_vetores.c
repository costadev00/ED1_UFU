#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet1[20], vet2[20], vet3[20];
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            vet1[j] = 0;
            vet2[j] = 0;
        }
        vet3[i] = 0;
    }
    for(int i=0;i<10;i++){
        scanf("%d",&vet1[i]);
    }
    for(int i=0;i<10;i++){
        scanf("%d",&vet2[i]);
    }
    for(int i=0;i<=20;i++){
        for(int j=0;j<10;j++){

            if(i%2==0 || i==0){
                vet3[i] = vet1[j];
            }

            else{
                vet3[i] = vet2[j];
            }
        }
        }
    for(int i=0;i<20;i++){
        printf("%d", vet3[i]);
    }
    return 0;
}
