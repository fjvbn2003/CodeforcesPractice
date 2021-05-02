#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[20][20];
struct student{
    int id;
    int frd[4];
};
struct position{
    position():r(0),c(0),frd_s(0),empty_s(0), idx(0){}
    int r;
    int c;
    int frd_s;
    int empty_s;
    int idx;
};
bool comp(position& a, position& b){
    if(a.frd_s == b.frd_s){
        if(a.empty_s ==  b.empty_s){
            if(a.r == b.r){
                return a.c<b.c;
            }else{
                return a.r<b.r;
            }
        }else{
            return a.empty_s >  b.empty_s;
        }
    }else{
        return a.frd_s>b.frd_s;
    }
}

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int main(){
    int n;
    vector<student> students;
    cin>> n;
    student tmp;
    for(int i=0; i<n*n; i++){
        cin>> tmp.id;
        for(int j=0; j<4; j++){
            cin>>tmp.frd[j];
        }
        students.push_back(tmp);
    }
    position pos;
    vector<position> positions;
    for(int i=0; i<n*n; i++){
        tmp = students[i];
        positions.clear();
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(arr[j][k] != 0) continue;
                // check frd if position j,k;
                int frd_s = 0;
                int empty_s = 0;
                for(int m=0; m<4; m++){
                    int ny = j+dy[m];
                    int nx = k+dx[m];
                    if(ny>=0 && ny<n && nx>=0 && nx<n){
                        if(arr[ny][nx]==0){
                            empty_s++;
                            continue;
                        }
                        for(int n=0; n<4; n++){
                            if(arr[ny][nx] == tmp.frd[n]){
                                frd_s++;
                                break;
                            }
                        }
                    }
                }
                pos.r = j;
                pos.c = k;
                pos.frd_s = frd_s;
                pos.empty_s = empty_s;
                pos.idx = i;
                positions.push_back(pos);
            }
        }
        sort(positions.begin(), positions.end(), comp );
        arr[positions[0].r][positions[0].c] = tmp.id;
    }
    int ans = 0;
    for(int j=0; j<n; j++){
        for(int k=0; k<n; k++){
            int id = arr[j][k];
            // find students
            for(int i=0; i<n*n; i++){
               if(students[i].id == id){
                   tmp = students[i];
                   break;
               } 
            }
            int frd_s = 0;
            for(int m=0; m<4; m++){
                int ny = j+dy[m];
                int nx = k+dx[m];
                if(ny>=0 && ny<n && nx>=0 && nx<n){
                    for(int n=0; n<4; n++){
                        if(arr[ny][nx] == tmp.frd[n]){
                            frd_s++;
                            break;
                        }
                    }
                }
            }
            if(frd_s==4) ans+=1000;
            else if(frd_s==3) ans+= 100;
            else if(frd_s==2) ans+= 10;
            else if(frd_s==1) ans+= 1;
            else ans+=0;
        }
    }
    cout <<ans<<endl;
    return 0;
   
    


}