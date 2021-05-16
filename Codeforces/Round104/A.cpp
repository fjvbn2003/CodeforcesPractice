#include <bits/stdc++.h>
using namespace std;

int main(){
    int test_case;
    cin>> test_case;
    int n;
    vector<int> arr;
    while(test_case--){
        cin>> n;
        arr.clear();
        arr.resize(n);
        for(int i=0; i<n; i++){
            cin>> arr[i];
        }
        sort(arr.begin(), arr.end());
        int mini = arr[0];
        int k=1;
        for(int i=1; i<n; i++){
            if(arr[i]>mini){
                break;
            }
            k++;
        }
        if(k==n){
            cout <<0<<endl;
        }else{
            cout <<n-k<<endl;
        }
    }
    return 0;
}