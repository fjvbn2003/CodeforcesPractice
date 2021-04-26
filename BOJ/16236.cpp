#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int arr[21][21];
int ans = 0;
int n;
struct shark{
    int y;
    int x;
    int size;
    int eat;
};
int dist[21][21];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};
bool find_prey(shark& s){
    queue<pair<int, int> > q;
    // initialize dist 
    for(int i=0; i<21; i++)
        for(int j=0; j<21; j++)
            dist[i][j] = -1;
    q.push({s.y, s.x});
    dist[s.y][s.x] = 0;
    //BFS find shortest path
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(arr[y][x] !=9 && arr[y][x] !=0  && arr[y][x] <s.size){continue;}
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny>=0 && ny<n && nx>=0 && nx<n && dist[ny][nx]==-1 &&arr[ny][nx]<=s.size ){
                dist[ny][nx] = dist[y][x]+1;
                q.push({ny, nx});
            }
        }
    }
    // find minimum y, x, dist 
    int my = 100;
    int mx = 100;
    int m_dist = 401;
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(arr[i][j]!=0 && arr[i][j] !=9&& arr[i][j]<s.size && dist[i][j] != -1 && dist[i][j]<=m_dist){
                m_dist = dist[i][j];
                my = i;
                mx = j;
            }
        }
    }
    if(m_dist == 401){
        return false;
    }else{
        arr[s.y][s.x] =0; 
        s.y = my;
        s.x = mx;
        s.eat++;
        if(s.eat ==  s.size){
            s.eat = 0;
            s.size++;
        }
        arr[my][mx] = 9;
        ans+= dist[my][mx];
        return true;
    }
}
int main(){
    shark s;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>> arr[i][j];
            if(arr[i][j] == 9){
                s.y = i;
                s.x = j;
                s.size = 2;
                s.eat = 0;
            }
        }
    }
    while(true){
        if(find_prey(s)){
            continue;
        }else{
            break;
        }
    }
    cout <<ans<<endl;
    return 0;
}