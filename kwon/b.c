#include <stdio.h>
int arr[3][3] = {{2,2,5}, {2,2,5}, {2,5,7}};
int main(){
    int income;
    int level;
    printf("****************************\n");
    printf("월 수입액: ");
    scanf("%d", &income);
    printf("등급 (1:생활보호 대상자, 2:국가유공자, 3:일반): ");
    scanf("%d", &level);
    printf("****************************\n");
    printf("****************************\n");
    printf("%10s %10s %10s \n", "금액", "세율", "세금");
    printf("----------------------------\n");
    level--;
    int sum = 0;
    if(income >= 500000){
        int outcome = 500000*arr[level][0]/100;
        sum += outcome;
        printf("%8d %8d%% %8d \n", 500000, arr[level][0], outcome);
        income -= 500000;
    }else{
        int outcome = income*arr[level][0]/100;
        sum += outcome;
        printf("%8d %8d%% %8d \n", income, arr[level][0], outcome);
        income =0;
    }
    if(income >= 500000){
        int outcome = 500000*arr[level][1]/100;
        sum += outcome;
        printf("%8d %8d%% %8d \n", 500000, arr[level][1], outcome);
        income -= 500000;
    }else{
        if(income > 0){
            int outcome = income*arr[level][1]/100;
            sum += outcome;
            printf("%8d %8d%% %8d \n", income, arr[level][1], outcome);
            income =0;
        }
        
    }
    if(income >0){
        int outcome = income*arr[level][2]/100;
        sum += outcome;
        printf("%8d %8d%% %8d \n", income, arr[level][2], outcome);
        income =0;
    }
    printf("----------------------------\n");
    printf("총 세금:%18d원\n", sum);
    printf("============================\n");
    return 0;

}