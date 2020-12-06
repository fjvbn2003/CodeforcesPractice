/*
ID: fjvbn201
TASK: friday
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n; //계산하고 싶은 기간 (년)
    int year_start = 2000; // 시작년도
    int month_days ;
    int day_of_the_week = 5;//2000년 1월 1일은 토요일
    vector<int> arr(7,0);
    cout <<" 계산하고 싶은 년수를 입력하세요: ";
    cin>> n;
    for(int i=0; i<n; i++){
        int cur_year = year_start+i;
        for(int j=1; j<=12; j++){
            if(j == 2){
                // leap year
                if(cur_year%4 == 0){
                    month_days = 29;
                    if(cur_year%100 == 0){
                        month_days = 28;
                        if(cur_year%400 ==0){
                            month_days = 29;
                        }              
                    }
                }else{
                    month_days = 28;
                }
            }
            else if(j == 4 || j == 6 || j == 11  || j==9){
                month_days = 30;
            }else{
                month_days = 31;
            }
            for(int k=1; k <= month_days; k++){
                if(k==13){
                    arr[day_of_the_week]++;
                }
                day_of_the_week++;
                day_of_the_week%=7;
            }
        }
    }
    cout << "2000년 1월 1일 ~"<< year_start+n-1<<"년 12월 31일까지의 13일의 요일 횟수"<<endl;
    vector<string> day_str = {"월","화","수","목","금","토","일"};
    for(int i=0; i<arr.size(); i++){
        cout << day_str[i]<<":"<<arr[i]<<" 일   ";
    }
    cout <<endl;
    return 0;
}