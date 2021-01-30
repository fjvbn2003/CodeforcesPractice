#include <iostream>
#include <vector>

using namespace std;
int dp[1001];
int num_of_fill(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }

    if(dp[n]) return dp[n];
    return dp[n] = (num_of_fill(n-1)+num_of_fill(n-2))%10007;

}

int main(){
    int n;
    cin>> n;
    cout << num_of_fill(n)%10007<<endl;;
    return 0;
}