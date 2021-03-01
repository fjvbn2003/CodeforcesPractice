#include <bits/stdc++.h>
using namespace std;

int main(){
    int test_case;
    int n;
    cin>> test_case;
    while(test_case--){
        cin>>n;
        vector<int> arr(n);
        int ans =0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        for(int i=0; i<n-1; i++){
            int maxi = max(arr[i], arr[i+1]);
            int mini = min(arr[i], arr[i+1]);
            int cnt = 0;
            int tmp = mini;
            //cout <<"mini "<<mini<<" maxi "<<maxi<<endl;
            if(double(maxi)/mini >2){
                while(tmp < maxi){
                    tmp = tmp*2;
                    cnt++;
                }
            }

            ans+= max(0,cnt-1);
            //cout <<"cnt "<<cnt<<endl;
        }
        cout <<ans<<endl;
    }
    return 0;
}

