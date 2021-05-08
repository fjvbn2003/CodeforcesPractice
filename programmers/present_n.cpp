#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int Max_Cnt = 9;
int Arr[8];

void Make_NumberArray(int n){
    int Temp = n;
    for(int i=0; i<8; i++){
        Arr[i] = Temp;
        Temp = Temp*10;
        Temp = Temp+n;
    }
}

void DFS(int Cnt, int Res, int number){
    if(Cnt >= Max_Cnt) return;
    if(Res == number){
        Max_Cnt = Cnt;
        return;
    }
    for(int i=0; i<8; i++){
        int nCnt = Cnt + (i+1);
        DFS(nCnt, Res+Arr[i], number);
        DFS(nCnt, Res-Arr[i], number);
        DFS(nCnt, Res*Arr[i], number);
        DFS(nCnt, Res/Arr[i], number);
    }
}
int main(){
    int n,number;
    cin>> n>>number;
    Make_NumberArray(n);
    DFS(0,0, number);
    if(Max_Cnt == 9){
        Max_Cnt = -1;
    }
    cout << Max_Cnt<<endl;
    return 0;
}