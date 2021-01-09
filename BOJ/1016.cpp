#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
// bool prime[1000001];
// ll arr[1000001];

int main(){
    ll a,b;
    cin>> a>>b;
    // prime[1] = true;
    // for(int i=2; i*i<1000001; i+=1){
    //     if(!prime[i]){
    //         for(int j=i*2; j<1000001; j+=i){
    //             prime[j] = true;
    //         }
    //     }
    // }
    int cnt = 0;
    ll m = (ll)sqrt(b);
    
    for(ll i = a; i<=b; i++){
        for(ll j=2; j<=m; j++ ){
            
            if(j*j == i){cnt++; break;}
            if(i%j==0){break;}
        }
    }
    if(a==1){
        cout << b-a-cnt<<endl;
        return 0;
    }
    cout << b-a+1-cnt<<endl;
    return 0;

}