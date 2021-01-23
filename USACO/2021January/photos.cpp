#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int n,id;
int dp[1000][2];
int maximum_group(int idx, int even){
    if(dp[idx][even]) return dp[idx][even];
    if(idx == n){return 0;}
    int even_sum = 0;
    int odd_sum = 0;
    int ret = -1000;
    if(even==0){
        for(int i=idx; i<n; i++){
            even_sum += arr[i];
            if(even_sum%2 ==0){
                ret = max(ret, maximum_group(i+1, 1)+1);
            }
        }
    }else{
        for(int i=idx; i<n; i++){
            odd_sum += arr[i];
            if(odd_sum%2 ==1){
                ret = max(ret, maximum_group(i+1, 0)+1);
            }
        }
    }
    return ret;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>> id;
        arr.push_back(id);
    }
    cout <<maximum_group(0, 0)<<endl;
    return 0;

}