#include<stdio.h>
#include<math.h>

int main(){
    int n,i;
    printf("Enter value of n");
    scanf("%d",&n);
    int X[n],Y[n];
    printf("Enter values of X:");
    for(i=0;i<n;i++){
        scanf("%d",&X[i]);
    }
    printf("Enter values of Y:");
    for(i=0;i<n;i++){
        scanf("%d",&Y[i]);
    }
    double sgX=0.0,sgY=0.0,sgXY=0.0,sgYsq=0.0,sgXsq=0.0;
    for(i=0;i<n;i++){
        sgX += X[i];
        sgY += Y[i];
        sgXY += (X[i]*Y[i]);
        sgYsq += (Y[i]*Y[i]);
        sgXsq += (X[i]*X[i]);
    }
    double r;
    double N = 10;
    r = ((N*sgXY) - (sgX*sgY)) / sqrt(((N*sgXsq)-(sgX*sgX))*((N*sgYsq)-(sgY*sgY)));
    printf("Value of Carl's Coefficient:%f\n",r);
}
