#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long test_case, n,t;
    long long s,ss;
    vector<long long> arr;
    cin>> test_case;
    while(test_case--){
        cin>>n;
        arr.clear();
        s = 0;
        for(int i=0; i<n+2; i++){
            cin>> t;
            arr.push_back(t);
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<n+2; i++){
            s+= arr[i];
        }
        bool flag = false;
        ss = s-arr[n+1];
        //n+1 is sum
        for(int i=0; i<n+1; i++){
            if(arr[n+1] ==  ss-arr[i]){
                arr[i] = -1;
                arr[n+1] = -1;
                flag = true;
                break;
            }
        }
        //n is sum, n+1 is random number
        ss = s-arr[n]-arr[n+1];
        if(ss== arr[n]){
            arr[n] = -1;
            arr[n+1] = -1;
            flag = true;
        }
        if(flag){
            for(int i=0; i<n+2; i++){
                if(arr[i]==-1){
                    continue;
                }else{
                    cout <<arr[i]<<' ';
                }
            }
            cout <<'\n';
        }else{
            cout <<-1<<endl;
        }
    }
    return 0;
}