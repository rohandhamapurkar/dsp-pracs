#include<stdio.h>
//This is an implementation of linear convolution.
int main(){
    int lx,lh,i,k;
    printf("Enter length of x[n]");
    scanf("%d",&lx);
    printf("Enter length of h[n]");
    scanf("%d",&lh);

    int x[lx],h[lh],y[lx+lh-1];

    printf("Enter elements for x[n]");
    for(i=0;i<lx;i++)
    {
        scanf("%d",&x[i]);
    }
    printf("Enter elements for h[n]");
    for(i=0;i<lh;i++)
    {
        scanf("%d",&h[i]);
    }
    for(i=0;i<(lx+lh-1);i++)
    {
        y[i]=0;
        for(k=0;k<(lx+lh-1);k++)
        {
            if(!((i-k)<0 || (i-k)>=lh || k>=lx))
            {
                y[i] += (x[k]*h[i-k]);
            }
        }
        printf("\ny(%d)=%d",i,y[i]);
        printf("\n");
    }
    return 0;
}