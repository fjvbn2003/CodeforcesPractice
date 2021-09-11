#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
bool this_prime(long long tmp){
    //cout <<"is_prime: "<<tmp<<endl;
    if(tmp==1) return false;
    if(tmp ==2) return true;
    if(tmp%2 ==0) return false;

    for(long long i=3; i*i<=tmp; i++){
        //cout << "hi: "<<i<<endl;
        if((tmp%i) ==0){
            //cout <<"fail at: "<< i<<endl;
            return false;  
        } 
    }
    //cout <<"bottom"<<endl;
    return true;
}
int solution(int n, int k) {
    
    //n을 k진수로 바꿔서 문자열로 저장.
    // 0을 기준으로 split 한 뒤에 각각을 소수인지 판단하기. 
    int answer = 0;    
    int t = n;
    vector<int> arr;
    while(t){
        arr.push_back(t%k);
        t/=k;
    }
    //reverse(arr.begin(), arr.end());
    
    // for(int i=0; i<arr.size(); i++){
    //     cout << arr[i]<<" ";
    // }
    // cout <<endl;
    int cnt = 0;
    long long cand = 0;
    for(int i=0; i<arr.size(); i++){
        // cand가 소수인지 판단한다.
        if(arr[i]==0){
            if(cand==0) continue;
            if(this_prime(cand)){
                //cout <<"find prime "<< cand<<endl;
                answer++;
            }
            cand = 0;
            cnt=0;
        }else{
            cand+= arr[i]*pow(10, cnt);
            cnt++;
        }
    }
    if(cand >0){
        //cout <<"in cand: "<<cand<<endl;
        if(this_prime(cand)){
            //cout <<"find prime "<< cand<<endl;
            answer++;
        }
    }
    
    return answer;
}