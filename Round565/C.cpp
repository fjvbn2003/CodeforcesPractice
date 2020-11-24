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
    freopen("./output.txt","w",stdout);
    #endif 
    int test_case = 1;
    solve();
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
void solve(){
    vector<int> p({4,8,15,16,23,42});
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
    }
    vector<int> seq(6);
    for(int i=0; i<n; i++){
        if(a[i]==0){ // a[i]== 4
            seq[0]++;
        }else{
            if(seq[a[i]-1]>0){
                seq[a[i]-1]--;
                seq[a[i]]++;
            }
        }
    }
    if(seq[5]){
        cout << n-6*seq[5] <<endl;
    }else{
        cout <<n<<endl;
    }

}
/*
Author: fjvbn2003
Round: #565(Div.3)
problem: C. Lose it!
*/