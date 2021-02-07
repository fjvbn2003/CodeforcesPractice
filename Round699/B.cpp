#include <iostream>
#include <vector>

using namespace std;

int main(){

    long long test_case,n,k,t;
    vector<long long> arr;
    cin>> test_case;
    while(test_case--){
        arr.clear();
        cin>> n>>k;
        for(int i=0; i<n; i++){
            cin>>t;
            arr.push_back(t);
        }
        long long sum =0;
        bool ans_flag = false;
        long long ans = -1;
        while(1){
            bool flag = false;
            for(int i=0; i<n-1; i++){
                if(arr[i]<arr[i+1]){
                    sum+= arr[i+1]-arr[i];
                    arr[i] = arr[i+1];
                    if(k <=sum){
                        ans = i+1;
                        ans_flag = true;
                    }
                    flag = true;
                    break;
                }
            }
            if(ans_flag) break;
            if(!flag) break;
        }
        cout <<ans<<endl;
    }
    return 0;


}