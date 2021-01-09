#include <iostream>

using namespace std;
#define MAX 1000001
bool prime[MAX];
int main(){
    int m,n;
    cin>>m>>n;
    prime[1] = true;
    for(int i=2; i*i<MAX; i+=1){
        if(!prime[i]){
            for(int j=2*i; j<MAX; j+=i)
                prime[j] = true;
        }
    }
    for(int i=m; i<=n; i++){
        if(!prime[i])
            cout <<i<<" ";
    }
    cout <<endl;

}