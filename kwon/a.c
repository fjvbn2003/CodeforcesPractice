#include <stdio.h>
#include <math.h>

int main(){
    double dia;
    double price;
    double S;
    double C;

    printf("피자 직경(cm)?: ");
    scanf("%lf", &dia);
    printf("피자 가격(원)?: ");
    scanf("%lf", &price);
    S = M_PI*dia*dia/4; 
    C = price/S*10;
    printf("피자의 크기: ");
    printf("%lf \n", S);
    printf("10cm당 가격: %lf \n", C);
    return 0;
}