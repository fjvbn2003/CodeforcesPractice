#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<long long> arr = {1,1,1,2,2};
    for(int i=5; i<102; i++){
        arr.push_back(arr[i-1]+ arr[i-5]);
    }
    int n;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        cout << arr[t-1]<<endl;
    }
    return 0;
}