#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int cnt = 0;
int col[16];
void bf(int col_idx){
    if(col_idx == n+1){
        cnt++;
        return;
    }
    for(int i=1; i<=n; i++){
        bool flag  = false;
        for(int j = 1; j<col_idx; j++){
            if(col[j]== i || abs(j-col_idx) == abs(col[j]-i)){flag = true; break;}
        }
        if(flag) continue;
        else{
            col[col_idx] = i;
            bf(col_idx+1);
            col[col_idx] = 0;
        }
    }

}
int main(){
    cin>>n;
    bf(1);
    cout <<cnt<<endl;
}