#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet1[2], vet2[2],j=0;
    for(int i=0;i<3;i++){
        vet1[i] = 0;
        vet2[i] = 0;
    }
    for(int i=0; i<=2; i++)
    {
        scanf("%d",&vet1[i]);
    }
    for(int i=2; i>=0; i--)
    {
        vet2[j] = vet1[i];
        j++;
    }
    for(int i=0; i<=2; i++)
    {
        printf("%d \n", vet2[i]);
    }

    return 0;
}
