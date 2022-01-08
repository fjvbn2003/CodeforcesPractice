#include <iostream>
using namespace std;


int main(){
    int n;

    cin>>n;
    long long ans =0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=i; j++){
            ans += i;
            ans += j;
        }
    }
    cout <<ans<<endl;
    return 0;
}   