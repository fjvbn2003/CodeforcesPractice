#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;


int main(){
    int test;
    cin>>test;
    int n;
    string s;
    vector<string> ans;
    string t = "  ";
    string tt ="   ";
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            t[0] = char('a'+i);
            t[1] = char('a'+j);
            ans.push_back(t);
            for(int k=0; k<26; k++){
                tt[0] = char('a'+i);
                tt[1] = char('a'+j);
                tt[2] = char('a'+k);
                ans.push_back(tt);
            }

        }
    }
    sort(ans.begin(), ans.end());
    // for(int i=0; i<ans.size(); i++){
    //     cout <<ans[i]<<" ";
    // }
    // cout <<endl;

    while(test--){
        cin>>n;
        cin>> s;
        set<char> st;
        vector<string> arr;
        for(int i=0; i<n-1; i++){
            arr.push_back(s.substr(i,2));
            if(i!=n-1){
                arr.push_back(s.substr(i,3));
            }
        }
        sort(arr.begin(), arr.end());
        char first,second;
        // for(int i=0; i<n-1; i++){
        //     cout<<arr[i]<<" ";
        // }

        // cout <<endl;
        for(int i=0; i<n; i++){
            st.insert(s[i]);
        }
        if(st.size() != 26){
            for(int i=0; i<26; i++){
                if(st.count(char('a'+i))==0){
                    cout << char('a'+i)<<'\n';
                    break;
                }
            }
            continue;
        }
        for(int i=0; i<arr.size(); i++){
            if(ans[i]<arr[i]){
                cout << ans[i]<<'\n';
                break;
            }
        }
    }

}