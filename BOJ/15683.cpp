#include <iostream>
#include <vector>

using namespace std;
int dy[4]= {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int n,m;
vector< vector<int> > arr;
int ans = 0;
vector<pair< pair<int, int>, int> > cctv;
void ccheck(int y, int x, int dir, vector<vector<int> >& temp){

    int ny = y+dy[dir];
    int nx = x+dx[dir];
    // cout <<"in ccheck"<<endl;
    // cout <<"ny: "<<ny<<" nx: "<<nx<<endl;

    while(ny<n && nx<m && ny>=0 && nx>=0){
        if(temp[ny][nx]==6){
            break;
        }
        temp[ny][nx]= 7;
        ny = ny+dy[dir];
        nx = nx+dx[dir];
            //cout <<"ny: "<<ny<<" nx: "<<nx<<endl;

    }
    //cout <<"in ccheck"<<endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout <<temp[i][j]<<" ";
    //     }
    //     cout <<endl;
    // }
    return ;
}

void go(int index, int dir, vector<vector<int> > temp){
    //cout << "index:"<<index<<" dir:"<<dir<< "temp: "<<endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout <<temp[i][j]<<" ";
    //     }
    //     cout <<endl;
    // }
    if(index ==  cctv.size()){
        int cand = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(temp[i][j]==0) cand++;
            }
        }
        if(ans > cand) ans = cand;
        return ;
    }
    int y = cctv[index].first.first;
    int x = cctv[index].first.second;
    int k  = cctv[index].second;
    //cout <<"y: "<<y<<" x: "<<x<<" k:"<<k<<endl;
    if(k == 1){
        ccheck(y,x, dir, temp);
    }else if(k == 2){
        ccheck(y,x, dir, temp);
        ccheck(y,x, (dir+2)%4, temp);
    }else if(k == 3){
        ccheck(y,x, dir, temp);
        ccheck(y,x, (dir+1)%4, temp);
    }else if(k ==  4){
        ccheck(y,x, dir, temp);
        ccheck(y,x, (dir+1)%4, temp);
        ccheck(y,x, (dir+2)%4, temp);
    }else if(k == 5){
        ccheck(y,x, dir, temp);
        ccheck(y,x, (dir+1)%4, temp);
        ccheck(y,x, (dir+2)%4, temp);
        ccheck(y,x, (dir+3)%4, temp);
    }  
    for(int i=0; i<4; i++){
        go(index+1, (dir+i)%4, temp);
    }
    // cout <<"after function"<<endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout <<temp[i][j]<<" ";
    //     }
    //     cout <<endl;
    // }
    return ;
}

int main(){
    cin>> n>>m;
    int t;
    for(int i=0; i<n; i++){
        vector<int> vi;
        for(int j=0; j<m; j++){
            cin>>t;
            vi.push_back(t);
            if(t != 0 && t != 6){
                cctv.push_back({{i,j},t});
            }
            if(t==0){ans++;}
        }
        arr.push_back(vi);
    }

    vector<vector<int> > tmp(arr);
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout <<tmp[i][j]<<" ";
    //     }
    //     cout <<endl;
    // }
    for(int i=0; i<4; i++){
        go(0,i, tmp);
    }
    cout <<ans<<endl;
    return 0;
    
}