#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int args,char * argv[]){
    int test;
    cin>>test;
    int n;
    while(test--){
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>> arr[i];
        }
        sort(arr.begin(), arr.end());
        int small = arr[0];
        int ds = arr[0];
        int cnt = 1;
        int idx = -1;
        for(int i=1; i<n; i++){
            if(arr[i] == small){
                cnt++;
                ds+=arr[i];
            }else{
                idx = i;
                break;
            }
        }
        int ans = 0;
        if(idx==-1)
            cout <<ans<<'\n';
        else{
            for(int i=idx; i<n; i++){
                if(ds < cnt*arr[i]){
                    ans++;
                }else{
                    break;
                }
            }
            cout <<ans<<'\n';
        }
        

    }
    return 0;

}