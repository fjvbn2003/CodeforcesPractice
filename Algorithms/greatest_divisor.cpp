 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n =2088;
    long long greatest_divisor =-1;
    for(long long i=2; i*i<=n; i++){
        if(n%i==0){greatest_divisor = n/i; break;}
    }
    if(greatest_divisor == -1){
        cout <<n<<" 은 소수입니다."<<endl;
    }else{
        cout <<greatest_divisor<<endl;
    }
}
