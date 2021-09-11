#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> appeach;
vector<int> answer;

int max_win = 0;
void shot(int key, int remain){
    int score_a=0;
    int score_r=0;
//     bool mode =false;
//     if((key&(1<<0)) && (key&(1<<1)) &&(key&(1<<2)) &&(key&(1<<4)) && (key&(1<<5)) && (key&(1<<6)) ){
        
//         for(int i=0; i<11; i++){
//             if(key&(1<<i)){
//                 cout <<1<<" | ";
//             }else{
//                 cout <<0<<" | ";
//             }
//         }
//         mode = true;
//         cout<<endl;
//     }
    // 키가 있는 과녁은 반드시 이겨야한다.
    for(int i=0; i<10; i++){
        // if(mode){
        //     cout <<"i: "<<i<<" remain n: "<<remain<<endl;
        // }
        if(key&(1<<i)){
            if(appeach[i] >0){
                if(remain>=appeach[i]+1){
                    score_r += (10-i);
                    remain -= (appeach[i]+1);
                }else{
                    return;
                }    
            }else{
                if(remain>=1){
                    score_r +=(10-i);
                    remain--;
                }else{
                    return;
                }
            }
        }else{
            if(appeach[i]>0){
                score_a += (10-i);
            }
        }
    }
    // 저장
    // if(mode){
    //     cout <<"in mode score r: "<< score_r<<" score_a: "<<score_a<<endl;
    // }
    if(score_r-score_a == 0) return;
    if( score_r-score_a == max_win){
        if(remain < answer[10]){
            return;
        }else if(remain == answer[10]){
            for(int i=9; i>=0; i--){
                if(key&(1<<i)){
                    if(answer[i] > appeach[i]+1){
                        return;
                    }else if(answer[i]< appeach[i]+1){
                        break;
                    }    
                }else{
                    if(answer[i]>0) return;   
                }
            }   
        }        
    }
    if(score_r-score_a >= max_win){
//         cout << "find: "<< score_r-score_a<<endl;
//         cout <<"score r: "<< score_r<<" score_a: "<<score_a<<endl;
        
        max_win = (score_r-score_a);
        for(int i=0; i<11; i++){
            if(key&(1<<i)){
                //cout <<1<<" ";
                answer[i] = appeach[i]+1;
            }else{
                //cout <<0<<" ";
                answer[i] = 0;
            }
        }
        if(remain){
            answer[10] = remain;
        }
        cout <<endl;
    }
}
int bit_cnt(int t){
    int ret =0;
    while(t){
        ret += (t%2);
        t/=2;
    }
    return ret;
}
vector<int> solution(int n, vector<int> info) {
    appeach = info;
    answer.resize(11, 0);
    int t = n;
    for(int i=1; i<(1<<10); i++){
        if(bit_cnt(i) >n) continue;
        shot(i, t);
    }
    if(max_win == 0){
        return {-1};
    }
    return answer;
}