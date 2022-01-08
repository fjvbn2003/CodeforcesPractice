#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// counting sorting
int main(){
    int n,t;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    
    vector<int> arr(10001,0);
    for(int i=0; i<n; i++){
        cin>> t;
        arr[t]++;
    }
    for(int i=1; i<10001; i++){
        for(int j=0; j<arr[i]; j++)
            cout << i<<'\n';
    }
    cout <<endl;
    return 0;
}