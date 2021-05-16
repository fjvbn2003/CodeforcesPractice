#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int test_case;
    cin>> test_case;
    long long n;
    long long k;

    while(test_case--){
        cin>>n>>k;
        if(n%2 ==0){
            k--;
            k%=n;
            cout <<k+1<<"\n";
        }else{
            k--;
            long long div = k/(n-1);
            long long re = k%(n-1);

            long long semi = n/2;

            long long first = div%n;
            long long no = (div+semi)%n;
            // 이 부분을 시뮬레이션하지 말고 식으로 바꾸자.
            if(no>first){
                first+= re;
                if(no<=first){
                    first++;
                }
                first%=n;
            }else{
                first+=re;
                first%=n;
                if(no<=first){
                    first++;
                }
                first%=n;
            }            

            cout <<first+1<<"\n";

        }    
    }
    return 0;

}