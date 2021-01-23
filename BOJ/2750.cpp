#include <iostream>
using namespace std;

int main(){
    int n;
    int arr[1002];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    int key, idx;
    // 삽입정렬
    for(int i=1; i<n; i++){
        key = arr[i];
        idx = i-1;
        while(key < arr[idx] && idx>-1){
            arr[idx+1] = arr[idx];
            idx--;
        }
        arr[idx+1] = key;
    }
    for(int i=0; i<n; i++){
        cout << arr[i]<<endl;
    }
    return 0;


}