#include <string>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> Map;
    for(int i=0; i<id_list.size(); i++){
        Map[id_list[i]] = i;
    }
    
    vector<int> vote(id_list.size(), 0);
    vector<set<int> > st(id_list.size(), set<int>());
    for(string s : report){
        string a,b;
        stringstream ss(s);
        ss>>a>>b;
        st[Map[a]].insert(Map[b]);
    }
    for(int i=0; i<st.size(); i++){
        for(auto it: st[i]){
            vote[it]++;
        }
    }
    
    for(int i=0; i<st.size(); i++){
        for(auto it: st[i]){
            if(vote[it]>=k){
                answer[i]++;
            }
        }
    }
    // for(int i=0; i<st.size(); i++){
    //     cout << "i: "<<i<<endl;
    //     for(auto it : st[i]){
    //         cout<< it<<" ";
    //     }
    //     cout <<endl;
    // }
    return answer;
}