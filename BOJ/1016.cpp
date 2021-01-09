#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
bool nonono[1000001];
int main(){
    ll a,b;
    cin>> a>>b;
    
    for(ll i=2; i*i<=b; i++){
        ll s = a/(i*i);
        if(a%(i*i) !=0){
            s++;
        }
        // if(nonono[s*i*i -a]){
        //     continue;
        // }
    //cout <<a <<" "<<b<<endl;
        for(ll j=s; j*i*i <=b; j++){
            //cout << j*i*i<<" ";
            //cout << j*i*i - a<<" ";
            //cout <<endl;
            nonono[j*i*i -a] = true;
        }
    }

    int cnt = 0;
    
    for(ll i=a; i<=b; i++){
        //cout << nonono[i-a]<<" ";
        if(!nonono[i-a]) cnt++;
    }
    cout <<cnt<<endl;
    return 0;

}