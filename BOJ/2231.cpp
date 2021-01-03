#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n, t;
    int digits = 0;
    cin>>n;
    t = n;
    while(t){
        t/=10;
        digits++;
    }
    for(int i=n-digits*9; i<n; i++){
        int s = 0;
        t = i;
        while(t){
            s+= t%10;
            t/=10;
        }
        s+=i;
        if(s ==n){
            cout<< i<<endl;
            return 0;
        }
    }
    cout <<0<<endl;
    return 0;
}