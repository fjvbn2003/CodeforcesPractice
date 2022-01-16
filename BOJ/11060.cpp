#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> dp(n, 1234567890);
    for(int i=0; i<n; i++)
        cin>> arr[i];
    dp[0] = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<=i+arr[i]; j++){
            if(j<n){
                dp[j] = min(dp[j], dp[i]+1);
            }
        }
    }
    if(dp[n-1] == 1234567890){
        cout <<-1<<endl;
    }else{
        cout << dp[n-1]<<endl;
    }

    return 0;

}