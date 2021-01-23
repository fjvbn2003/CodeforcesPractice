#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
int base[11][11];
int fertile[11][11];
int dy[8] = {0,0,1,1,1,-1,-1,-1};
int dx[8] = {1,-1,0,1,-1,0,1,-1 };
priority_queue< tuple<int,int,int> > trees;
int main(){
    int n,m,k;
    int x,y,z;
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            base[i][j] = 5;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>fertile[i][j];
        }
    }
    for(int i=0; i<m; i++){
        cin>>x>>y>>z;
        trees.push({ -z, x-1,y-1 });
    }
    vector<tuple<int, int, int> > dead;
    vector<tuple<int, int, int> > seed;
    vector<tuple<int, int, int> > grow;
    
    for(int i=0; i<k; i++){
        int age, x, y;
        int tree_cnt = trees.size();
        dead.clear();
        seed.clear();
        grow.clear();
        for(int j=0; j<tree_cnt; j++){
            tie(age,x,y) = trees.top();
            age = -age;
            if(base[y][x]<age){
                trees.pop();
                //죽고나면 양분으로 변함
                dead.push_back({age,x,y});
            }
            else{
                // 나이만큼 비료를 먹고 나이가 1 증가
                trees.pop();
                base[y][x] -= age;
                grow.push_back({(age+1),x,y});
            }
        }
            // summer
        for(int j=0; j<dead.size(); j++){
            tie(age,x,y) = dead[j];
            base[y][x] += (age)/2;
        }
        //fall
        for(int j=0; j<grow.size(); j++){
            tie(age,x,y) = grow[j];
            trees.push({-age, x, y});
            if( (age)%5 ==0 ){
                seed.push_back({age,x,y});
            }
        }

        for(int j=0; j<seed.size(); j++){
            tie(age,x,y) = seed[j];
            for(int i=0; i<8; i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(0<=nx && nx<n && ny<=0 && ny<n){
                    trees.push({-1,nx, ny});
                }
            }
        }

        for(int j=0; j<n;j++){
            for(int k=0; k<n; k++){
                base[j][k] += fertile[j][k];
            }
        }
        for(int j=0; j<n;j++){
            for(int k=0; k<n; k++){
                cout << base[j][k]<<" ";
            }
            cout <<endl;
        }
    }
    cout << trees.size()<<endl;
    return 0;
}