#include <stdio.h>
char* arr[12] = {"자(쥐)", "축(소)", "인(호랑이)", "묘(토끼)", "묘진(용)",  "사(뱀)","오(말)","미(양)","신(원숭이)","유(닭)",  "술(개)", "해(돼지)"};
int main(){
   int year;
    printf("입력 연도: ");
    scanf("%d", &year);
    year -= 4;
    printf("%s 의 해 입니다.\n", arr[year%12]);
    return 0;
}