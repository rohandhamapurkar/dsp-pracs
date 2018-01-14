#include<stdio.h>

int cir_out[20][10];

void circonv(int x[],int h[], int len, int arr_flag){
	int i,k,modval;
	int maxlen = len;
	int y[maxlen];
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
            cir_out[arr_flag][i] = y[i];
        }
    }

    for(i=0;i<maxlen;i++)
    {
        printf("%d\t",cir_out[arr_flag][i]);
    }
}

int main(){
	int h[20], x[20];
    int lx,lh,i,j=0;
    printf("Enter length of x[n]\n");
    scanf("%d",&lx);
    printf("Enter length of h[n]\n");
    scanf("%d",&lh);

    printf("Enter elements for x[n]\n");
    for(i=0;i<lx;i++)
    {
        scanf("%d",&x[i]);
    }
    printf("Enter elements for h[n]\n");
    for(i=0;i<lh;i++)
    {
        scanf("%d",&h[i]);
    }

    int l = 4 , m = lh, n = l+m-1;
    int temp[lx+lh-1], set_arr[n], tempFlag=0, overlap_arr_counter=3, count = 0;
    if(lh < n)
    {
        for(i=lh;i<n;i++)
            h[i] = 0;
    }

    for(i=0 ; i<(lx+lh-1) ; i++)
    {
        if(i < m-1)
        {
            temp[i] = 0;
        }
        else 
        {
            temp[i] = x[j];
            j++;
        }
    }
    while(overlap_arr_counter != -1)
    {
        j=0;
        for(i=0+(l*tempFlag) ; i<n+((l+1)*tempFlag) ; i++)
        {
            if(i < lx+lh-1)
                set_arr[j] = temp[i];
            else    
                set_arr[j] = 0;
            printf("%d\n",i);
            j++;
        }
        circonv(set_arr, h, n, tempFlag);
        tempFlag++;
        if(i >= lx+lh+1)
            overlap_arr_counter = -1;
    }
    printf("\n");
    for(i=0 ; i<4; i++)
        for(j=l; j<n; j++)
            printf("%d\t", cir_out[i][j]);  
    printf("\n");        
}