#include <iostream>
using namespace std;

int main(){
    unsigned int test_case, n, t, ans;

    cin>>test_case;
    for(unsigned int i = 0; i<test_case; i++){
        cin>>n;
        ans = 0;
        for(unsigned int j=0; j<n; j++){
            cin>>t;
            ans ^= t;
        }
        cout <<"Case #"<<i+1<<endl;
        cout <<ans<<endl;
    }
    return 0;
}