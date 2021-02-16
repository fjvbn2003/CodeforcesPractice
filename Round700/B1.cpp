#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    int a0=0;
    int a1 =0;
    cin>> n;
    vector<int> arr(n);
    vector<bool> arr2(n, false);
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    int before = -1;
    bool first = true;
    int a_count = 0;
    for(int i=0; i<n; i++){
        if(before !=  arr[i]){
            a0++;
            arr2[i]  = true;
        }else{
            continue;
        }
        before = arr[i];
    }
    before = -1;
    for(int i=0; i<n; i++){
        if(arr2[i] ==  false){
            if(before !=  arr[i]){
            a1++;
            first = true;
            }else{
                continue;
            }
            before = arr[i];
        }
        
    }
    cout << a0+a1<<endl;
    return 0;
}