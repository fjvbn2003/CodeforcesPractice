#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    
    cin>>n>>m;
    vector<int> row(n+1);
    vector<int> col(m+1);
    
    string s;
    for(int i=1; i<=n; i++){
        cin>>s;
        for(int j=1; j<=m; j++){
            if(s[j-1]=='.'){
                continue;
            }else{
                row[i] = j;
                col[j] = i;
            }
        }
    }

    int ans = 0;
    int rn = 0;
    int rm = 0;
    for(int i=1; i<=n; i++){
        if(row[i]==0){
            rn++;
        }
    }
      for(int i=1; i<=m; i++){
        if(col[i]==0){
            rm++;
        }
    }
    cout << max(rn,rm)<<endl;


}