//
// Created by Yongju KIM on 2021/10/23.
//

#include <set>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
 * C++ map, queue, set, multimap, multiset, list, deque 사용법 정리.
 */

int main(){

    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(3);
    st.insert(4);
    set<int> st2;
    st2.insert(3);
    st2.insert(2);
    st2.insert(4);

    cout <<"first set: ";
    for(auto it : st){
        cout << it<<" ";
    }
    cout <<endl;
    cout <<"second set: ";
    for(auto it : st2){
        cout << it<<" ";
    }
    cout <<endl;

    vector<int> vi;
    vi.push_back(1);
    vi.push_back(12);
    vi.push_back(13);
    vi.push_back(13);
    vi.push_back(2);
    vi.push_back(1);
    vi.push_back(1);
    vi.push_back(3);
    sort(vi.begin(), vi.end());
    vi.erase(unique(vi.begin(),vi.end()),vi.end());
    cout << "unique elements "<<"\n";
    for(int i=0; i<vi.size(); i++){
        cout << vi[i]<<" ";
    }



    return 0;
}