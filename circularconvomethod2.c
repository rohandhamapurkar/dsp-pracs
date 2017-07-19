#include<stdio.h>
//This is an implementation of circular convolution. 19
int main(){
    int lx,lh,i,k,maxlen,modval;
    printf("Enter length of x[n]");
    scanf("%d",&lx);
    printf("Enter length of h[n]");
    scanf("%d",&lh);

    if(lx>lh){
      maxlen = lx;
    }else{
      maxlen = lh;
    }

    int x[maxlen],h[maxlen],y[maxlen];

    printf("Enter elements for x[n]");
    for(i=0;i<maxlen;i++)
    {
      if(!(i>=lx)){
        scanf("%d",&x[i]);
      }
      else{
        x[i]=0;
      }

    }
    printf("Enter elements for h[n]");
    for(i=0;i<maxlen;i++)
    {
      if(!(i>=lh)){
        scanf("%d",&h[i]);
      }
      else{
        h[i]=0;
      }
    }

    for(i=0;i<maxlen;i++)
    {
        y[i]=0;
        for(k=0;k<maxlen;k++)
        {
            if((i-k)<0)
            {
              modval = maxlen+(i-k);
              y[i] += (x[k]*h[modval]);
            }
            else
            {
                y[i] += (x[k]*h[(i-k)]);
            }
        }
        printf("\ny(%d)=%d",i,y[i]);
        printf("\n");
    }
}
