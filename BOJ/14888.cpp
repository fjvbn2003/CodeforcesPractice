#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int n,t;
vector<int> arr;
vector<int> op;

int best = -1234567890;
int worst = 1234567890;

void bf(vector<int> ops, int remain, int val){
    if(remain ==0){
        best = max(best,val);
        worst = min(worst,val);
        return;
    }
    for(int i=0; i<4; i++){
        if(ops[i]>0){
            if(i==0){
                ops[i]--;
                bf(ops, remain-1, val+arr[n-remain]);
                ops[i]++;
            }else if(i==1){
                ops[i]--;
                bf(ops, remain-1, val-arr[n-remain]);
                ops[i]++;
            }else if(i==2){
                ops[i]--;
                bf(ops, remain-1, val*arr[n-remain]);
                ops[i]++;
            }else{
                ops[i]--;
                bf(ops, remain-1, val/arr[n-remain]);
                ops[i]++;
            }
        }
    }
    return;
}

int main(){
    cin>>n;
    for(int i=0; i< n; i++){
        cin>>t;
        arr.push_back(t);
    }
    for(int i=0; i<4; i++){
        cin>> t;
        op.push_back(t);
    }
    bf(op, n-1, arr[0]);
    cout << best<<endl;
    cout <<worst<<endl;
}