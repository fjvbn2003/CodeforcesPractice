#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> research, int n, int k) {
    string answer = "";
    vector<map<char, int> > Map(research.size(), map<char,int>());
    for(int i=0; i<research.size(); i++){
        string s = research[i];
        for(int j=0; j< s.size(); j++){
            if(Map[i].find(s[j]) == Map[i].end())
                Map[i][s[j]] = 1;
            else{
                Map[i][s[j]]++;
            }
        }
        // for(map<char, int>::iterator it = Map[i].begin(); it != Map[i].end(); it++){
        //     cout << it->first<<" "<<it->second<<endl;
        // }
    }
    map<char, int> issue;
    for(int i=0; i<research.size(); i++){
        if(i+n > research.size()) continue;
        for(int j=i+n; j<research.size(); j++){
            // i일 ~ j일 까지 검색어 판단.
            int cnt = 0;
            
            for(auto t : Map[i]){
                char character = t.first;
                int cnt = t.second;
                bool suc = true;
                if(cnt < k) continue;    
                for(int t=i+1; t<j; t++){
                    if((Map[t].find(character) == Map[t].end()) || (Map[t][character] <k)){
                        suc = false;
                        break;
                    }
                    cnt += Map[t][character];
                }   
                if(suc && cnt>=2*n*k){
                    if(issue.find(character) == issue.end()){
                        issue[character] = 1;
                    }else{
                        issue[character]++;
                    }
                }
            }
            
        }
    }
    
    return answer;
}