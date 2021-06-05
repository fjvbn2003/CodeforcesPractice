#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
        int t;
        cin>>t;
        
        while(t--){
            vector<int> arr(4);
            for(int i=0; i<4; i++){
                cin>> arr[i];
            }
            sort(arr.begin(), arr.begin()+2);
            sort(arr.begin()+2, arr.begin()+4);
            if(arr[0] >arr[3] || arr[2]>arr[1]){
                cout <<"NO"<<'\n';
            }else{
                cout <<"YES"<<'\n';
            }
            
        }

}