#include <iostream>
using namespace std;
int arr[11];
int arr2[11];

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        for(int i=0; i<n; i++){
            if(arr[i]==0 && arr2[i]==0){
                cout << i+1<<" ";
                arr2[i] = 1;
                for(int j=0; j<i; j++){
                    if(arr[j]>0){
                    arr[j]--;
                    }
                }
                break;
            }
        }
    
    }
    cout <<endl;
    // for(int i=0; i<n; i++){
    //     cout << arr[i]<<endl;
    // }
    return 0;
}