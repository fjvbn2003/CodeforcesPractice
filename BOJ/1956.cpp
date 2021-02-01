#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dist[401][401];
int INF  = 400000;
int v,e;
int main(){
    cin>>v>>e;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            dist[i][j] = INF;

        }
    }
    // for(int i=0; i<v; i++){
    //     for(int j=0; j<v; j++){
    //         cout <<dist[i][j]<<" ";
    //     }
    //     cout <<endl;
    // }    
    int a,b,w;
    int ans = INF;
    for(int i=0; i<e; i++){
        cin>>a>>b>>w;
        dist[a-1][b-1] = min(dist[a-1][b-1],w);
    }
    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(dist[i][k]+dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }     
    }
        
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(i != j){
                if((dist[i][j] != INF) && (dist[j][i] != INF)){
                        ans = min(ans, dist[i][j]+dist[j][i]);
                }
            }
        }
    }
    // for(int i=0; i<v; i++){
    //     for(int j=0; j<v; j++){
    //         cout <<dist[i][j]<<" ";
    //     }
    //     cout <<endl;
    //}
    if(ans == INF){
        cout <<-1<<endl;
    }else{
        cout <<ans<<endl;
    }
    //cout << 1234567890 + 1234567890<<endl;
    return 0;
        

}