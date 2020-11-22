#include <bits/stdc++.h>
using namespace std;
bool primes [2750132];

int main(){
for(int i=2; i<2750132; i++) primes[i] = true;
    for(int i=2; i*i < 2750132; i++){
        if(primes[i]){
            for(int k=i*i; k<2750132; k+=i){
                primes[k] = false;
            }
        }
    }
    for(int i=1; i<2750132; i++){
        if(primes[i]){
            cout << i <<" ";
        }
    }
    cout <<endl;

}
