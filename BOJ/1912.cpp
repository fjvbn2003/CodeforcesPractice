#include <iostream>
using namespace std;
int dp[100001];
int arr[100001];
int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    dp[1] = arr[1];
    for(int i=2; i<=n; i++){
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
    }
    int ans = arr[1];
    for(int i=1; i<=n; i++){
        if(ans<dp[i]){
            ans = dp[i];
        }
    }
    cout <<ans<<endl;
    return 0;
}