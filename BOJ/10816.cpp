#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,t,m;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
      cin>>arr[i];  
    }
    sort(arr.begin(), arr.end());
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>t;
        int cnt = upper_bound(arr.begin(), arr.end(),t )-lower_bound(arr.begin(), arr.end(),t );
        cout <<cnt<<" ";
    }
    cout <<endl;
    return 0;
}