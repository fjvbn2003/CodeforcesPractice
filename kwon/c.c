#include <stdio.h>

int main(){
    int scores[6][5];
    int sum_person[5];
    int sum_subject[3];
    double aves[5];
    int sum_all = 0;
    printf("학생성적을 입력 하세요 (5명의 학생 자료)\n");
    
    for(int i=0; i<5; i++){
        printf("%d번(국어, 영어, 수학): ", i+1);
        scanf("%d%d%d",&scores[i][0],&scores[i][1],&scores[i][2]);
    }
    //make sum_person
    for(int i=0; i<5; i++){
        int t = 0;
        for(int j=0; j<3; j++){
            t+= scores[i][j];
        }
        sum_person[i] = t;
    }
    //make sum_subject
    for(int i=0; i<3; i++){
        int t = 0;
        for(int j=0; j<5; j++){
            t+= scores[j][i];
        }
        sum_subject[i] = t;
        sum_all +=t;
    }
    //make aves
    for(int i=0; i<3; i++){
        aves[i] = (double)sum_subject[i]/5;
    }
    printf("===============================================\n");
    printf("%10s%8s%8s%8s%8s\n", "번호", "국어", "영어", "수학","총점");
    printf("===============================================\n");
    for(int i=0; i<5; i++){
        printf("%7d%7d%7d%7d%7d\n",i+1,scores[i][0],scores[i][1],scores[i][2],sum_person[i]);
    }
    printf("===============================================\n");
    printf("%10s%7d%7d%7d%7d\n", "과목총점",sum_subject[0],sum_subject[1],sum_subject[2],sum_all);
    printf("===============================================\n");
    printf("%10s%7.2f%7.2f%7.2f%7.2f\n", "과목평균",aves[0],aves[1],aves[2],(double)sum_all/5);
    printf("===============================================\n");

    return 0 ;
}