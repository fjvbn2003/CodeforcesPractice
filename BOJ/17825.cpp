//
// Created by Yongju KIM on 2021/10/21.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> dices(10);
int ans =-1;
int lookup[34][6]={
        {0,1,2,3,4,5},//0
        {2,2,3,4,5,9},//1
        {4,3,4,5,9,10},//2
        {6,4,5,9,10,11},//3
        {8,5,9,10,11,12},//4
        {10,6,7,8,24,25},//5
        {13,7,8,24,25,26},//6
        {16,8,24,25,26,32},//7
        {19,24,25,26,32,33},// 8
        {12,10,11,12,13,14},//9
        {14,11,12,13,14,15},// 10

        {16,12,13,14,15,16},//11
        {18,13,14,15,16,17},//12
        {20,19,20,24,25,26},//13
        {22,15,16,17,18,28},//14
        {24,16,17,18,28,29},//15
        {26,17,18,28,29,30},// 16
        {28,18,28,29,30,31},// 17
        {30,21,22,23,24,25},//18
        {22,20,24,25,26,32},// 19
        {24,24,25,26,32,33},// 20

        {28,22,23,24,25,26},//21
        {27,23,24,25,26,32},//22
        {26,24,25,26,32,33},//23
        {25,25,26,32,33,33},//24
        {30,26,32,33,33,33},//25
        {35,32,33,33,33,33},// 26
        {0,0,0,0,0,0},// 27
        {32,29,30,31,32,33},//28
        {34,30,31,32,33,33},// 29
        {36,31,32,33,33,33},// 30

        {38,32,33,33,33,33},//31
        {40,33,33,33,33,33},// 32
        {0,33,33,33,33,33},// 33
};
void search(int bits){
    vector<int> positions(4, 0);
    int cand = 0;
    for(int turn =0; turn<10; turn++) {
        int move_horse = (bits >> (turn * 2)) & 3;
        //cout << move_horse<<endl;
        // 1~5 사이.
        int & cur_pos = positions[move_horse];
        int move_diff = dices[turn];

        // 이미 도착한 말을 움직이려고한다면 중지.
        if(cur_pos==33) return;
        int cand_pos = lookup[cur_pos][move_diff];
        // 해당 위치에 다른 말이 있으면 중지
        for(int i=0; i<4; i++){
            if(i==move_horse) continue;
            if(positions[i]!=33 && positions[i] == cand_pos) return;
        }
        cur_pos = cand_pos;
        cand += lookup[cur_pos][0];
    }
    ans = max(cand, ans);
    return ;

}

int main(){
    for(int i=0; i<10; i++){
        cin>> dices[i];
    }
    // 모든 경우를 전부 탐색.
    for(int bit=0; bit< (1<<20); bit++){
        search(bit);
    }
    //search(0b1010101001010101);
    cout <<ans<<endl;
    return 0;
}