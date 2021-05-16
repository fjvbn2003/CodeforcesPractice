#include <bits/stdc++.h>
using namespace std;
int tmp[3];
int main(){
    int test_case;
    cin>>test_case;
    while(test_case--){
        int n;
        cin>>n;
        vector<int> arr(n);
        tmp[0] = 0;
        tmp[1] = 0;
        tmp[2] = 0;
        for(int i=0; i<n; i++){
            cin>> arr[i];
            tmp[arr[i]%3]++;
        }
        int div = n/3;
        int ans = 0;
        while(tmp[0]<div){
            if(tmp[2]>div){
                tmp[2]--;
                tmp[0]++;
                ans++;
                continue;
            }
            if(tmp[1]>div){
                tmp[1]--;
                tmp[0]++;
                ans++;
                ans++;
                continue;
            }
        }
        //cout <<"tmp [0]: "<<tmp[0]<<endl;
        while(tmp[1]<div){
            if(tmp[0]>div){
                tmp[0]--;
                tmp[1]++;
                ans++;
                continue;
            }
            if(tmp[2]>div){
                tmp[2]--;
                tmp[1]++;
                ans++;
                ans++;
                continue;
            }
        }
                //cout <<"tmp [1]: "<<tmp[2]<<endl;

        while(tmp[2]<div){
            if(tmp[1]>div){
                tmp[1]--;
                tmp[2]++;
                ans++;
                continue;
            }
            if(tmp[0]>div){
                tmp[0]--;
                tmp[2]++;
                ans++;
                ans++;
                continue;
            }
        }
                //cout <<"tmp [2]: "<<tmp[2]<<endl;

        //cout <<"tmp"<<endl;
        // for(int i=0; i<3; i++){
        //     cout<<tmp[i]<<" ";
        // }
        cout  <<ans<<"\n";
    }
    return 0;
}