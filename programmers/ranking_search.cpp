#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
vector<int> scores[4][3][3][3];
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, int> Map;
    Map["-"] = 0;
    Map["cpp"] = 1;
    Map["java"] = 2;
    Map["python"] = 3;
    
    Map["backend"] = 1;
    Map["frontend"] = 2;
    
    Map["junior"] = 1;
    Map["senior"] = 2;
    
    Map["chicken"] = 1;
    Map["pizza"] = 2;
    
    for(string s : info){
        stringstream ss(s);
        string lang, type, old, food;
        int score;
        ss>> lang>>type>>old>>food>>score;
        // 16군데에 저장되어야 함.
        for(int i=0; i< (1<<4); i++){
            int tmp[4] = {0};
            for(int j=0; j<4; j++){
                if((1<<j) & i){
                    tmp[j] = 1;
                }
            }
            for(int j=0; j<4; j++){
                if(j==0 && tmp[j]){
                    tmp[j] = Map[lang];
                }
                if(j==1 && tmp[j]){
                    tmp[j] = Map[type];
                }
                if(j==2 && tmp[j]){
                    tmp[j] = Map[old];
                }if(j==3 && tmp[j]){
                    tmp[j] = Map[food];
                }
            }
            scores[tmp[0]][tmp[1]][tmp[2]][tmp[3]].push_back(score);
        }
    }
    for(int i=0; i<4; i++)
        for(int j=0; j<3; j++)
            for(int k=0; k<3; k++)
                for(int l=0; l<3; l++)
                    sort(scores[i][j][k][l].begin(),scores[i][j][k][l].end());
    
    for(string s : query){
        stringstream ss(s);
        string lang, type, old, food, tmp;
        int score;
        ss>> lang>>tmp>>type>>tmp>>old>>tmp>>food>>score;
        vector<int>& t = scores[Map[lang]][Map[type]][Map[old]][Map[food]];
        int ans =  t.end() - lower_bound(t.begin(), t.end(), score);
        answer.push_back(ans);
    }
    
    return answer;
}