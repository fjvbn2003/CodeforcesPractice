#include <stdio.h>
#include <string.h>

int main(){
    int select;
    char s[30];
    char arr[5][30];
    printf("1 : E-mail --> 각 요소로 분리하기\n");
    printf("2 : 각 요소 --> Email 만들기\n");
    printf("선택하세요: ");
    
    scanf("%d", &select);
    if(select ==1){
      printf("E-mail을 입력하시오: ");
      scanf("%s", s);
      // name
      char* tmp = strstr(s,"@");
      strncpy(arr[0], s,tmp - s);
      arr[0][tmp-s] = '\0';
      printf("name: %s\n", arr[0]);
      strcpy(s, tmp+1);
      // system
      tmp = strstr(s,".");
      strncpy(arr[1], s,tmp - s);
      arr[1][tmp-s] = '\0';
      printf("system: %s\n", arr[1]);
      strcpy(s, tmp+1);
      //domain
      tmp = strstr(s,".");
      strncpy(arr[2], s,tmp - s);
      arr[2][tmp-s] = '\0';
      printf("domain: %s\n", arr[2]);
      strcpy(s, tmp+1);
      char* tmpp = s;
      //organization
      tmp = strstr(s,".");
      if(tmp != NULL){
        strncpy(arr[3], s,tmp - s);
        arr[3][tmp-s] = '\0';
        printf("organization: %s\n", arr[3]);
        strcpy(s, tmp+1);
      }else{
        strcpy(arr[3], tmpp);
        printf("organization: %s\n", arr[3]);
      }
      
      //organization
      if(tmp != NULL){
        strncpy(arr[4], s,tmp - s);
        arr[4][tmp-s] = '\0';
        printf("country: %s\n", arr[4]);
        strcpy(s, tmp+1);
      }else{
        strcpy(arr[4],"usa\0" );
        printf("country: %s\n", arr[4]);
      }
    }else if(select == 2){
        printf("E-mail : ");
        for(int i=0; i<5; i++){
            scanf("%s", arr[i]);
        }
        printf("%s@",arr[0]);
        for(int i=1; i<4; i++){
            printf("%s", arr[i]);
            if(i !=3){
                printf(".");
            }
        }
        if(strcmp(arr[4],"usa") != 0 ){
            printf(".%s", arr[4]);
        }
        printf("\n");
    }else{
        printf("1또는 2를 입력해주세요.\n");
    
    }

}