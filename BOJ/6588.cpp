#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000001
bool prime[MAX];
vector<int> primes;
int main(){
    int t;
    cin.tie(0);
    prime[1] = true;
    for(int i=2; i*i<MAX; i+=1){
        if(!prime[i]){
            for(int j=i*2; j<MAX; j+=i){
                prime[j] = true;
            }
        }
    }
    for(int i=2; i<MAX; i++){
        if(!prime[i]) primes.push_back(i);
    }
    int ps = primes.size();
    while(1){
        cin>>t;
        if(t==0) return 0;
        bool flag = false;
        for(int i=0; i<ps; i++){
            if(!prime[t-primes[i]]){
                cout << t << " = " << primes[i]<<" + "<< t-primes[i]<<"\n";
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << "Goldbach's conjecture is wrong.\n"<<"\n";
        }
    }
    return 0;
}