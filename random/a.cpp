#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

int main(){
    int test;
    cin>>test;
    int n;
    int t;
    while(test--){
        cin>>n;
        set<int> s;
        vector<int> arr;
        queue<int> q;
        for(int i=0; i<n; i++){
            cin>>t;
            arr.push_back(t);
            s.insert(t);
        }      
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                t = abs(arr[i]-arr[j]);
                if(s.count(t) ==0){
                    q.push(t);
                }
            }
        }
        //cout <<"q:size " <<q.size()<<endl;
        if(q.size() ==0){
            cout <<"YES"<<'\n';
            cout <<n<<'\n';
            for(int i=0; i<n; i++)
                cout << arr[i]<<" ";
            cout <<'\n';
        }else{
            while(!q.empty()){
                if(arr.size()>300) break;
                t = q.front();
                q.pop();
                // cout <<"q:size " <<q.size()<<endl;
                // cout <<"t: "<<t<<endl;

                if(s.count(t)==0){
                    for(int i=0; i<arr.size(); i++){
                    if(s.count(abs(t-arr[i])) == 0){
                        q.push(abs(t-arr[i]));
                    }
                    }
                    arr.push_back(t);
                    s.insert(t);
                }
     
            }
            if(arr.size()>300){
                cout <<"NO"<<'\n';
            }else{
                cout <<"YES"<<'\n';
                cout <<arr.size()<<'\n';
                for(int i=0; i<arr.size(); i++)
                    cout << arr[i]<<" ";
                cout <<'\n';
            }
        }
    }

}