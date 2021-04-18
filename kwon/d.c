#include <stdio.h>
#include <stdlib.h>
int getMonthDay(int month){
    int days = 31;
    if(month == 4 ||month == 6 ||month == 9 || month == 11)
        days = 30;
    if(month == 2)
        days = 28;
    return days;
}
double* getDays(double* days, int dayNum){
    days = (double*)calloc(dayNum, sizeof(double));
    printf("온도를 입력하시오 (1 ~ %d일) : ", dayNum);
    for(int i=0; i<dayNum; i++){
        scanf("%lf",&days[i]);
    }
    return days;
}

int getHiDay(double* days, int dayNum){
    double hi = -1;
    int h_idx;
    for(int i=0; i<dayNum; i++){
        if(days[i]>hi){
            hi = days[i];
            h_idx = i;
        }
    }
    return h_idx;
}
void display(double* days, int start, int count){
    printf("day:==========0========================================\n");
    for(int i=start; i<start+count; i++){
        printf("%4d",i);
        for(int j=-10; j<=40; j++){
            if((int)days[i-1] == j){
                printf("*");
            }
            else if(j == 0){
                printf("|");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("   :==========0========================================\n");
    return;
}
int getLowDay(double* days, int dayNum){
    double low = -1;
    int l_idx;
    for(int i=0; i<dayNum; i++){
        if(days[i]<low){
            low = days[i];
            l_idx = i;
        }
    }
    return l_idx;
}
double getAve(double* days, int dayNum){
    double sum = 0;
    for(int i=0; i<dayNum; i++){
        sum += days[i];
    }
    return sum/dayNum;
}
int main(){
    int month;
    int dayNum;
    double* days;
    int hiDay,lowDay;
    double ave;
    int start, count;
    printf("월을 입력하세요 : ");
    scanf("%d",&month);
    dayNum = getMonthDay(month);
    days = getDays(days, dayNum);
    hiDay = getHiDay(days, dayNum);
    lowDay = getLowDay(days, dayNum);
    ave = getAve(days, dayNum);
    printf("%d월 기온 보고서\n", month);
    printf("===============================\n");
    printf("%10s%10d일\n", "가장 더운날",hiDay+1);
    printf("%10s%10d일\n", "가장 추운날",lowDay+1);
    printf("%10s%10.2lf도\n", "평균 기온",ave);
    printf("===============================\n");
    printf("그래프 출력을 원하는 기간(시작일, 기간) :");
    scanf("%d%d",&start, &count);
    display(days, start, count);
    return 0;

}