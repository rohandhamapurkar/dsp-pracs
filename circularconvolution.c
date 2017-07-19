#include<stdio.h>

void downshift(int colNum ,int n,int arr[][n],int iter){
    int k,j;
    for(j=0;j<iter;j++)
    {
        int temp=arr[n-1][colNum];
        for(k=n-1;k>0;k--){
            arr[k][colNum]=arr[k-1][colNum];
        }
        arr[0][colNum]=temp;
    }

}

int main(){
    int n,m,i,j;

    printf("Enter length of x[n]"); //input len x[n]
    scanf("%d",&n);
    printf("Enter length of h[n]"); //input len h[n]
    scanf("%d",&m);
    int ylen = n+m-1;  //y[n] length determined *****need to change to the longest array
    int x[ylen][ylen],h[ylen],y[ylen];

    printf("Enter x[n]"); //input x[n]
    for(i=0;i<n;i++){
        scanf("%d",&x[i][0]);
    }

    for(i=0;i<ylen;i++){  //creating x[ylen][ylen] matrix for calculation
        for(j=0;j<ylen;j++){
            if(i<n){
                x[i][j]=x[i][0];
            }
            else{
                x[i][j] = 0;
            }

        }
    }

    printf("Enter h[m]");  //input x[n]
    for(i=0;i<ylen;i++){
        if(i<m){
            scanf("%d",&h[i]);
        }
        else{
            h[i]=0;
        }
    }

    for(i=1;i<ylen;i++) //rotation of x[ylen][ylen]
    {
        downshift(i,ylen,x,i);
    }

    for(i=0;i<ylen;i++){
        y[i]=0;
        for(j=0;j<ylen;j++){
            y[i] += x[i][j]*h[j];
        }
        printf("\ny[%d]=%d",i,y[i]);
    }


    for(i=0;i<ylen;i++){

        for(j=0;j<ylen;j++){
            printf("%d",x[i][j]); //print x[ylen][ylen]
        }
        printf("\n");
    }

return 0;
}
