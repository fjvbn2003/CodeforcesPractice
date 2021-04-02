#include <iostream>
using namespace std;

int main(){
    int test_case;
    cin>> test_case;
    long long n,m, i,j,k;
    while(test_case--){
        cin>> n>>m>>k;
        k--;
        j = k/n;
        i = k- (j*n);
        cout << i*m+(j+1)<<endl;
    }
    return 0;

}