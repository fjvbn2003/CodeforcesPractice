#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-variable"

#include <bits/stdc++.h>
using namespace std;
int arr[52][52];
vector<pair<int,int>> chicken;
vector<pair<int,int>> houses;
int n, m;

int dist(vector<int> & cand){
    int ans = 0;
    for(int j=0; j< houses.size(); j++){
        int mini = 987654321;
        for(int i=0; i<cand.size(); i++){
            if(cand[i]==1){
                mini = min(mini, abs(houses[j].first-chicken[i].first)+ abs(houses[j].second-chicken[i].second));
            }
        }
        ans+= mini;
    }
    return ans;
}
int main(){
    #ifdef hi
    freopen("./input.txt","r",stdin);
    #endif 
    
    cin>> n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>> arr[i][j];
            if(arr[i][j]==2){
                chicken.push_back({i,j});
            }else if(arr[i][j] == 1){
                houses.push_back({i,j});
            }else{
                continue;
            }
        }
    }
    vector<int> b;
    for(int i=0; i<m; i++) b.push_back(1);
    for(int i=0; i<chicken.size()-m; i++) b.push_back(0);

    sort(b.begin(), b.end());
    int mini = 987654321;
    do{
        mini = min(dist(b), mini);
    }while(next_permutation(b.begin(), b.end()));
    cout <<mini<<endl;
    return 0;
}
/*
15686 치킨배달.
*/