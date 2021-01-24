#include <iostream>
#include <string>
using namespace std;
int n;
int brute_force(string s, int idx, char last){
    if(idx == n){
        return 1;
    }
    int ret = 0;
    if(s[idx] =='d'){
        for(int i=0; i<10; i++){
            if('0'+i != last){
                ret += brute_force(s, idx+1, '0'+i);
            }
        }
    }else{
        for(int i=0; i<26; i++){
            if('a'+i != last){
                ret += brute_force(s, idx+1, 'a'+i);
            }
        }
    }
    return ret;
}

int main(){
    string s;
    cin>>s;
    n = s.size();
    cout << brute_force(s, 0, ' ')<<endl;
    return 0;
}