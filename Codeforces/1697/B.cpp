#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, q;
    cin>>n>>q;
    vector<long long> arr(n);
    vector<long long> s(n,0);
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    sort(arr.begin(), arr.end());
    s[0] = arr[0];
    for(int i=1; i<n; i++){
        s[i] = s[i-1]+arr[i];
    }
    for(int i=0; i<q; i++){
        int x, y;
        cin>>x>>y;
        int start = n-x;
        int end = n-x+y-1;
        if(start == end){
            cout << arr[start]<<endl;
        }
        else if(start ==0){
            cout << s[end]<<endl;
        }else{
            cout << s[end]-s[start-1]<<endl;
        }
    }
}