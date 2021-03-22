#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string name = "CANAANAA";
    char alph[26] = {'A','B','C','D', 'E','F','G','H', 'I','J','K','L', 'M','N','O','P', 'Q','R','S','T', 'U','V','W','X', 'Y','Z'};
    int n = name.size();
    string ori = "";
    for(int i=0; i<n; i++){
        ori += "A";
    }
    int idx = 0;
    int answer = 0;
    while(name != ori){
        if(ori[idx] != name[idx] ){
            int t = min(name[idx]-ori[idx],26-(name[idx]-ori[idx]) );
            ori[idx] = name[idx];
            answer+= t;
        }
        //forward;
        int t = n;
        int forward = 0;
        for(int i=(idx+n+1)%n; i!=idx; i++, i%=n){
            forward++;
            if(ori[i] != name[i]){
                t = min(t, forward);
                break;
            }
        }
        int backward = 0;
        for(int i=(idx+n-1)%n; i != idx; i+=n, i--, i%=n){
            backward++;
            if(ori[i] != name[i]){
                t = min(t, backward);
                break;
            }
        }
        if(t!=n){
            if(t == forward){
                answer+=forward;
                idx+= forward;
            }
            else{
                answer += backward;
                idx-= backward;
                if(idx <0) idx+=n;
            }
        }
    }
    cout << answer<<endl;
    return 0;

}