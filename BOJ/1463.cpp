#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];
int min_cnt_ops(int x){
    if(x==1) return 0;
    if(dp[x]){return dp[x]; }
    if(x==3 || x== 2) return 1;
    int &ret = dp[x] = 1234567890;
    if(x%3 ==0){
        ret = min(min_cnt_ops(x/3)+1,ret);
    }
    if(x%2 == 0){
        ret = min(min_cnt_ops(x/2)+1, ret);
    }
    ret = min(min_cnt_ops(x-1)+1, ret);
    return ret;
}

int main(){
    int n;
    cin>>n;
    cout <<min_cnt_ops(n)<<endl;

}