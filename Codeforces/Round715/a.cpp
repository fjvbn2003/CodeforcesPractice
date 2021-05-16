#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[20001];
bool comp(int a, int b){
    if(a&1 && b&1){
        return a<b;
    }else if(a&1){
        return true;
    }else if(b&1){
        return false;
    }
    return a<b;

}
int main(){
    int test_case;
    cin>>test_case;
    int n,t;
    while(test_case--){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n, comp);

        for(int i=0; i<n; i++){
            cout << arr[i]<<" ";
        }
        cout <<'\n';
    }
    return 0;
}