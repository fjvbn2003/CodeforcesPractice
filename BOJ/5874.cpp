#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin>> s;
    vector<int> forward;
    vector<int> backward;
    for(int i=0; i<s.size()-1; i++){
        if(s[i]=='(' && s[i+1]=='('){
            forward.push_back(i);
        }
        if(s[i]==')' && s[i+1]==')'){
            backward.push_back(i);
        }
    }
    int ans = 0;
    int k  = backward.size();
    for(int i=0; i<forward.size(); i++){
        int tmp = forward[i];
        int diff = 0;
        if(lower_bound(backward.begin(), backward.end(), tmp)!= backward.end()){
            //cout <<"fow: "<<tmp<< " back: "<< *lower_bound(backward.begin(), backward.end(), tmp)<<endl;
            diff = k- (lower_bound(backward.begin(), backward.end(), tmp)-backward.begin());
        }
        ans += diff;
    }
    cout <<ans<<endl;
    return 0;
}