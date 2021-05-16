#include <bits/stdc++.h>

using namespace std;

int main(){
    int test_case;
    cin>>test_case;
    vector<int> arr;
    vector<int> arr2;
    int n;
    while(test_case--){
        cin>>n;
        arr.clear();
        arr2.clear();
        arr.resize(n);
        arr2.resize(n);
        for(int i=0; i<n; i++){
            cin>> arr[i];
        }
        if(n%2 == 0){
            for(int i=0; i<n/2; i++){
                arr2[i*2] = arr[i];
            }

            for(int i= n-1; i>=n/2; i--){
                arr2[(n-1-i)*2+1] = arr[i];
            }

        }else{
            for(int i=0; i<=n/2; i++){
                arr2[i*2] = arr[i];
            }
            for(int i= n-1; i>n/2; i--){
                arr2[(n-1-i)*2+1] = arr[i];
            }
        }
        
        
        
        for(int i=0; i<n; i++){
            cout << arr2[i]<<" ";
        }
        cout <<endl;
    }
    return 0;
}