//
// Created by Yongju KIM on 2021/11/06.
//

//
// Created by Yongju KIM on 2021/11/06.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;
bool comp(pair<string, int> & a, pair<string,int> &b){

    return a.first< b.first;

}
int main(){
    int n;
    cin>>n;
    set<string> names;
    map<string, vector<int> > mp;
    string name, place;
    int from, to;
    int best_best = 0;
    for(int i=0; i<n ; i++){
        cin>> name>>place>>from>>to;
        if(names.count(name)>0) continue;
        names.insert(name);
        if(mp.count(place)==0){
            mp.insert(make_pair(place, vector<int>(50001)));
        }
        for(int j=from; j<to; j++){
            (mp[place])[j]++;
            best_best = max(best_best, (mp[place])[j]);
        }
    }

    vector<pair<string, int> >ans;
    for(auto i=mp.begin(); i!= mp.end(); i++){
        for(int j=0; j< 50001; j++){
           if((*i).second[j]==best_best){
               ans.push_back(make_pair( (*i).first, j));
           }
        }

    }
    sort(ans.begin(), ans.end(), comp);
    string ans_str = ans[0].first;
    int f = ans[0].second;
    int t = f;
    bool find_ans = false;
    vector<int> &ar = mp[ans_str];
    for(int i=f+1; i<50001; i++){
        if(ar[i] != best_best){
            t = i;
            find_ans = true;
            break;
        }
    }
    if(find_ans == false){
        t = 50001;
    }

    cout << ans_str<<" "<<f<<" "<<t<<endl;
//
//    for(auto i=mp.begin(); i!= mp.end(); i++){
//        int len = 0;
//        bool flag = false;
//        int best_len = 0;
//        for(int j=0; j< 500001; j++){
//            if((*i).second[j]==best_best){
//                if(flag) len++;
//                else{
//                    flag = true;
//                    len = 1;
//                }
//            }else{
//                best_len = max(best_len, len);
//                flag = false;
//                len = 0;
//            }
//        }
//        best_len = max(best_len, len);
//        ans.push_back(make_pair(best_len,(*i).first));
//    }
//    for(auto i=mp.begin(); i!= mp.end(); i++){
//        cout <<(*i).first<<endl;
//        for(int j=0; j< 20; j++){
//            cout << (*i).second[j]<<" ";
//        }
//        cout <<endl;
//    }
//    for(int i=0; i<ans.size(); i++){
//        cout <<ans[i].first<<" "<<ans[i].second<<endl;
//    }
//    sort(ans.begin(), ans.end(), comp);
//    string ans_str = ans[0].second;
//    int ans_len = ans[0].first;
//    vector<int> & ar = mp[ans_str];
//    int start = 0;
//    int end = 0;
//    bool find_ans = false;
//    bool flag = false;
//    int len = 0;
//
//    for(int i=0; i<500001; i++){
//        if(ar[i] ==best_best){
//            if(flag){
//                len++;
//            }
//            else{
//                flag = true;
//                len = 1;
//                start = i;
//            }
//        }else {
//            if (len == ans_len) {
//                end = i;
//                find_ans = true;
//                break;
//            } else {
//                flag = false;
//                len = 0;
//            }
//        }
//    }
//    if(find_ans== false){
//        end = 500000;
//    }

}