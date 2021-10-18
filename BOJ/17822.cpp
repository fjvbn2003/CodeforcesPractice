#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;
// BOJ 17822 원판돌리기.

int N,M,T;
vector<deque<int> > disks;
int D[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool bfs(int r, int c, vector<vector<bool> > & visit){
    vector<pair<int, int> > updated;
    updated.push_back(make_pair(r,c));
    visit[r][c] =true;
    queue<pair<int, int> > q;
    q.push(make_pair(r,c));
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nr = cr+D[i][0];
            int nc = cc+D[i][1];
            // 반대편 가능
            if(nc<0) nc+=M;
            if(nc>=M) nc-=M;
            //if(nr<0) nr+=N;
            //if(nr>=N) nc-=N;

            if(nr>=N  || nr <0 || visit[nr][nc] || disks[nr][nc]!=disks[cr][cc]) continue;

            updated.push_back(make_pair(nr,nc));
            visit[nr][nc] = true;
            q.push(make_pair(nr, nc));
        }

    }
    //update to 0


    if(updated.size() < 2){
        visit[r][c] = false;
        return false;
    }else{
        for(int i=0; i<updated.size(); i++){
            int cr = updated[i].first;
            int cc = updated[i].second;
            disks[cr][cc] = 0;
        }
        return true;
    }
}

int main(){
    cin>>N>>M>>T;
    disks.resize(N, deque<int>(M, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            cin >> disks[i][j];
        }
    }
    int x,d,k;
    for(int t=0; t<T; t++){
        cin>>x>>d>>k;
        //x의 배수의 원판을 d 방향으로 k번 만큼 돌린다.
        for(int j=x; j<=N; j+=x){
            //시계방향
            if(d==0){
                for(int times=0; times<k; times++){
                    int tmp = disks[j-1].back();
                    disks[j-1].pop_back();
                    disks[j-1].push_front(tmp);
                }
            }else{
                for(int times=0; times<k; times++){
                    int tmp = disks[j-1].front();
                    disks[j-1].pop_front();
                    disks[j-1].push_back(tmp);
                }
            }
        }
//        cout <<"after rotating"<<endl;
//        for(int i=0; i<N; i++){
//            for(int j=0; j<M; j++) {
//                cout <<disks[i][j]<<" ";
//            }
//            cout <<endl;
//        }
//        cout <<endl;

        // 인접한 것들 삭제
        vector<vector<bool> > visited(N, vector<bool>(M, false));
        bool update = false;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(disks[i][j] !=0 && visited[i][j]==false){
                    if(bfs(i, j, visited)){
                        update = true;
                    }
                }
            }
        }
//        cout <<"after deleting"<<endl;
//        for(int i=0; i<N; i++){
//            for(int j=0; j<M; j++) {
//                cout <<disks[i][j]<<" ";
//            }
//            cout <<endl;
//        }
//        cout <<endl;


        if(!update){
            double s = 0;
            double cnt = 0;
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    if(disks[i][j] >0){
                        s += disks[i][j];
                        cnt++;
                    }
                }
            }
            //평균
            s/=cnt;
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    if(disks[i][j] >0){
                        if((double)disks[i][j]- 1e-7 <s && s<(double)disks[i][j]+ 1e-7 ){
                            continue;
                        }
                        else if((double)disks[i][j] > s){
                            disks[i][j]--;
                            //cout <<"down"<< i<<" "<<j<<" "<<disks[i][j]<<endl;
                        }
                        else if((double)disks[i][j]<s){
                            disks[i][j]++;
                            //cout <<"down"<< i<<" "<<j<<" "<<disks[i][j]<<endl;

                        }
                    }
                }
            }
//            cout <<"after updating S: "<< s<<endl;
//            for(int i=0; i<N; i++){
//                for(int j=0; j<M; j++) {
//                    cout <<disks[i][j]<<" ";
//                }
//                cout <<endl;
//            }
//            cout <<endl;
        }


    }
    //cout<<"final"<<endl;
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            //cout <<disks[i][j]<<" ";
            ans += disks[i][j];
        }
        //cout <<endl;
    }
    cout <<ans<<endl;
    return 0;


}