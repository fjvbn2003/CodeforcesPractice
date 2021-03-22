#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
long long calc(long long y, long long x, long long n){
    if(y==0 && x==0){
        return 1LL;
    }
    long long k = y+x;
    long long start = k*(k+1)/2;
    if(k > n-1){
        long long dif = k-(n-1);
        start -= dif*(dif+1)/2;
    }
    if(k%2 ==0){
        start += x+1;
    }else{
        start += y+1;
    }

    return start;
}
int main(){
    int test_case;
    cin>>test_case;
    int ttt =1;
    while(ttt<=test_case){
        long long n, k;
        cin>>n>>k;
        
        string s;
        cin>>s;
        long long i=0;
        long long j = 0;
        long long ans = 0;
        for(int l=0; l<s.size();l++){
            if(s[l]=='U'){
                i--;
            }else if(s[l] =='D'){
                i++;
            }else if(s[l] =='L'){
                j--;
            }else if(s[l] == 'R'){
                j++;
            }else {
                continue;
            }
            cout <<"calc "<<i<<" "<<j<<" "<<calc(i,j,n)<<endl;
            ans += calc(i,j,n);
        }
        cout <<"Case #"<<ttt<<'\n';
        cout <<ans+1LL<<'\n';
        ttt++;
    }
    return 0;
}