#include <iostream>
#include <vector>

using namespace std;

int main(){
    int test_case;
    cin>> test_case;
    vector<int> arr;

    while(test_case--){
    arr.clear();
    int n,t;
    cin>> n;
    for(int i=0; i<n; i++){
        cin>>t;
        arr.push_back(t);
    }
    int before = arr[0];
    int b_idx = 0;
    for(int i=1; i<n; i++){
        if(before != arr[i]){
            before = arr[i];
            b_idx = i;
        }
    }
    if(arr[2] == arr[0] && arr[0] != arr[1]){
        b_idx = 2;
    }
    if(arr[1]== arr[2] && arr[0] != arr[1]){
        b_idx = 1;
    }
    if(arr[n-1] != arr[n-2] && arr[n-2] == arr[n-3]){
        b_idx = n;
    }
    cout << b_idx<<endl;
    }
    return 0;


}