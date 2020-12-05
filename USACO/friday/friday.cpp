/*
ID: fjvbn201
TASK: friday
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n;
    int year = 1900;
    int th = 1;
    int days ;
    int c = 2;
    vector<int> arr(7,0);
    fin>> n;
    for(int i=0; i<n; i++){
        int cur_year = year+i;
        for(int j=1; j<=12; j++){
            if(j == 2){
                // leap year
                if(cur_year%4 == 0){
                    days = 29;
                    if(cur_year%100 == 0){
                        days = 28;
                        if(cur_year%400 ==0){
                            days = 29;
                        }              
                    }
                }else{
                    days = 28;
                }
            }
            else if(j == 4 || j == 6 || j == 11  || j==9){
                days = 30;
            }else{
                days = 31;
            }
            for(int k=1; k <= days; k++){
                if(k==13){
                    arr[c]++;
                }
                c++;
                c%=7;
            }
            //cout << "year: "<<cur_year<< "month: "<< j<<" days: "<<days<<endl;
        }
    }
    for(int i=0; i<arr.size()-1; i++){
        fout << arr[i]<<" ";
    }
    fout << arr[6];
    fout <<endl;
    return 0;
}