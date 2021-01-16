#include <iostream>
using namespace std;
#define MOD 1000000007 
long long arr[101];

int main(){
    long long a, x;
    cin>>a>>x;
    a%=MOD;
    arr[1] = a;
    for(int i=2; i<=100; i++){
        arr[i] = (arr[i-1]*arr[i-1])%MOD;
    }
    long long ans = 1;
    long long t = 1;
    int i=1;
    long long k = x;
    while(k){
        if(x&t){
            ans = ((ans%MOD)*arr[i])%MOD;    
        }
        k >>=1;
        t <<=1;
        i++;
    }

    cout << ans%MOD<<endl;
    return 0;

}