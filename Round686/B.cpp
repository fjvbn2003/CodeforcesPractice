#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-variable"

#include <bits/stdc++.h>
using namespace std;
void solve();
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    #ifdef hi
    freopen("./input.txt","r",stdin);
    #endif 
    int test_case = 1;
    cin>> test_case;
    while(test_case--){
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
void solve(){
    int n,t;
    vector<int> arr;
    vector<pair<int,int> > arr2;
    multiset<int > s;
    set<int> s2;
    
    cin>>n;
    //cout <<"n: "<< n<<endl;
    for(int i=0; i<n; i++){
        cin>>t;
        s.insert(t);
        s2.insert(t);
        arr.push_back(t);
    }
    for(auto i: s2){
        arr2.push_back({s.count(i), i});
    }
    sort(arr2.begin(), arr2.end());
    // for(pair<int,int> i : arr2){
    //     cout <<i.first <<" "<<i.second<<" " ;
    // }

    if(arr2[0].first == 1){
        int idx = -1;
        for(int i=0; i< arr.size(); i++){
            if(arr[i]==arr2[0].second){
                idx = i;
                break;
            }
        }
        cout << idx+1<<"\n";
    }else{
        cout <<-1<<endl;
    }
    
}
/*
Author: fjvbn2003
Round: #
problem: B.
*/