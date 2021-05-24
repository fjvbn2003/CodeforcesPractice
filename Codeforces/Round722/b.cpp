#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        sort(arr.begin(), arr.end());
        int cnt = 1;
        int min = 1e9+1e9+9;
        for(int i=1; i<n; i++){
            if(min > abs(arr[i]-arr[i-1])){
                min = abs(arr[i]-arr[i-1]);
            }
            if(arr[i]<=0) cnt++;
            else{
                if(min >= arr[i]){
                    cnt++;
                }else{
                    break;
                }
            }
        }
        cout <<cnt<<'\n';



    }


}