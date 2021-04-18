#include <stdio.h>
#include <string.h>
int main(){
    char name[5][7];
    int arr[5][4];
    int sum_person[5];
    int sum_quarter[4];
    double avg_quarter[4];
    int avg_percentile[4];
    int tmp = 0;
    int all_sum = 0;
    char map[10][40];
    for(int i=0; i<5; i++){
        scanf("%s", name[i]);
        for(int j=0; j<4; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    // make sum_person
    for(int i=0; i<5; i++){
        tmp = 0;
        for(int j=0; j<4; j++){
            tmp+= arr[i][j];
        }
        sum_person[i] = tmp;
    }
    // make sum_quarter
    for(int i=0; i<4; i++){
        tmp = 0;
        for(int j=0; j<5; j++){
            tmp+= arr[j][i];
        }
        sum_quarter[i] = tmp;
        all_sum += tmp;
    }
    // make avg_quarter
    for(int i=0; i<4; i++){
        avg_quarter[i] = (double)sum_quarter[i] / 5;
    }
    printf("========================================================\n");
    printf("%10s%10s%10s%10s%10s%10s","판매사원", " 1/4분기", " 2/4분기", " 3/4분기", " 4/4분기",  " 총합\n");
    printf("========================================================\n");
    for(int i=0; i<5; i++){
        printf("%7s%10d%10d%10d%10d%10d\n",name[i],arr[i][0],arr[i][1],arr[i][2],arr[i][3],sum_person[i]);
    }
    printf("%10s%10d%10d%10d%10d%10d\n","분기총합",sum_quarter[0],sum_quarter[1],sum_quarter[2],sum_quarter[3],all_sum );
    printf("========================================================\n");
    printf("%10s%10.2f%10.2f%10.2f%10.2f%10.2f\n","분기평균",avg_quarter[0],avg_quarter[1],avg_quarter[2],avg_quarter[3],(double)all_sum/5 );
    printf("========================================================\n");
    // make graph
    for(int i=0; i<4; i++){
        avg_percentile[i] = ((double)avg_quarter[i] /((double)all_sum/5))*10;
    }
    // make map
    for(int i=0; i<10; i++){
        for(int j=0; j<40; j++){
            map[i][j] = ' ';
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<avg_percentile[i]; j++){
            map[9-j][4+i*8] = '*';
        }
    }
    for(int i=0; i<10; i++){
        printf("|");
        for(int j=0; j<40; j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------------\n");
    printf("%8s%8s%8s%8s\n","1/4","2/4","3/4","4/4");
    return 0;
}