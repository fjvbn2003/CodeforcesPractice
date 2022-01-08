#include <bits/stdc++.h>
using namespace std;

bool primes [10000];
int main(){
// 배열 인덱스 2부터 100까지 모두 소수라는 가정을 한다.
for(int i=2; i<10000; i++){
     primes[i] = true;
}
for(int i=2; i*i < 10000; i++){
    //만약 소수를 만난다면
    if(primes[i]){
        // 소수에 어떤 값을 곱하더라도 합성수이기 때문에
        // 범위 내에 있는 k의 배수들을 모조리 false로 체크한다.
        for(int k=i*i; k<10000; k+=i){
            primes[k] = false;
        }
    }
    
}
    int N;
    cin>>N;
    vector<int> arr;
    int before = 2;
    //만약 primes[i] == true 라면, i는 소수이다.
    for(int i=3; i<10000; i++){
        if(primes[i]){
            arr.push_back(before*i);
            before = i;
        }
    }
    sort(arr.begin(), arr.end());
    cout << *lower_bound(arr.begin(), arr.end(), N+1)<<endl;
    return 0;
}
