#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
// BOJ 21609 상어 중학교
// set을 sort해서 계속 삽질했던 문제..
// iterator로 지울 때는 iter = erase(iter) 이런식으로 받아줘야한다.!

int R, C, M;
struct shark{
  int r;
  int c;
  int s;
  int d;
  int z;
  int id;
};
// 지울 때 잘 지우기 위해서.
struct shark_compare{
    bool operator () (const shark&  a, const shark&  b ) const {
    // 로우와 컬럼이 모두 같다면 크기가 큰 순서대로.
    // 나중에 상어가 겹쳐있을 때 제일 첫번째만 빼고 다 삭제.
    if((a.c == b.c) && (a.r == b.r)){
      return a.z > b.z;
    }
    if(a.c == b.c){
      return a.r < b.r;
    }
    return a.c < b.c;
  }
};


set<shark, shark_compare> sharks;
// d 0:위, 1:아래, 2:오른쪽, 3:왼쪽
void move_shark(){
  vector<shark> add_shark;
  for(auto iter=sharks.begin(); iter != sharks.end(); iter++){
    int speed = iter->s;
    int dir = iter->d;
    int r = iter->r;
    int c = iter->c;
    if(dir==0 || dir==1){
      // 이부분이 시간이 많이 소요될 것 같음..
      for(int i=0; i<speed; i++){
        if(r==0 && dir==0){dir=1;}
        if(r==R-1 && dir==1){dir =0;}
        if(dir==0) r--;
        else if(dir==1) r++;
      }
    }else if(dir ==2 || dir==3){
      for(int i=0; i<speed; i++){
        if(c==0 && dir==3){dir=2;}
        if(c==C-1 && dir==2){dir =3;}
        if(dir==3) c--;
        else if(dir==2) c++;
      }
    }
    shark new_shark;
    new_shark.r =r;
    new_shark.c =c;
    new_shark.d = dir;
    new_shark.z = iter->z;
    new_shark.s = speed;
    new_shark.id = iter->id;
    add_shark.push_back(new_shark);
  }
  sharks.clear();
  for(int i=0; i<add_shark.size(); i++){
    sharks.insert(add_shark[i]);
  }
  return ;
}
void eat_shark(){
  int r=-1;
  int c=-1;
  for(auto iter=sharks.begin(); iter != sharks.end(); iter++){
    int nr = iter->r;
    int nc = iter->c;
    int id = iter->id;
    //cout <<" shark nr: "<<nr<<"  nc:"<<nc<<endl;
    // 상어가 겹쳐있을 때
    if(r==nr && c == nc){
      //cout <<"erase shark r:"<< "nr: "<<nr<<" nc: "<<nc<<" size: "<<iter->s<<endl;
      iter = sharks.erase(iter);
    }else{
      r = nr;
      c = nc;
    }
  }
  return;
}
int main(){

  cin>>R>>C>>M;
  int r,c,s,d,z,id;
  // 상어 입력.
  for(int i=0; i<M; i++){
    cin>>r>>c>>s>>d>>z;
    // r : (0~R-1) , c:(0~C-1), d: (0~3)
    shark sk;
    sk.r = r-1;
    sk.c = c-1;
    sk.s = s;
    sk.z = z;
    sk.d = d-1;
    sk.id = i;
    sharks.insert(sk);
  }
  eat_shark();

  long long ans = 0;
  for(int fisher_pos = 0; fisher_pos<C; fisher_pos++){
    // 낚시왕이 현재 컬럼에 있는 가장 가까운 상어를 잡는다.
    bool cought = false;
    //cout <<"before iter:"<<fisher_pos<<" size of sharks:"<< sharks.size()<<endl;

    for(auto iter = sharks.begin();  iter != sharks.end(); iter++){
      if((iter->c) == fisher_pos){
        //상어 잡기.
        cought = true;
        //cout <<"catch: "<< (*iter).z << " at: " << fisher_pos<<endl;
        ans += (*iter).z;
        //상어 삭제.
        iter = sharks.erase(iter);
        break;
      }
      if((*iter).c >fisher_pos ) break;
    }
    //cout <<"after iter:"<<fisher_pos<<" size of sharks:"<< sharks.size()<<endl;

    // 상어 이동 (자신의 속도와 방향에 맞게)
    move_shark();
    //cout <<"after move:"<<fisher_pos<<" size of sharks:"<< sharks.size()<<endl;
      // for(auto iter2=sharks.begin(); iter2 != sharks.end(); iter2++){
      //   //cout <<"iter2: "<<iter2->r <<" "<<iter2->c<<endl;
      // }

    // 상어끼리 먹히기.
    eat_shark();
    //cout <<"after eat:"<<fisher_pos<<" size of sharks:"<< sharks.size()<<endl;

  }

  cout <<ans<<endl;
  return 0;
}