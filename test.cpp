
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
using namespace std;

int main(){
    list<int> lt;

    int n=8;
    int k = 2;
    auto iter = lt.begin();
    vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};
    stack<pair< list<int>::iterator , int> > st;
    for(int i=0; i<n; i++){
        lt.push_back(i);
    }
    int t;
    for(int i=0; i<=k; i++) iter++;
    for(int i=0; i<cmd.size(); i++){
        if(cmd[i][0] == 'D'){
            t = (cmd[i][2]-'0');
            for(int tt=0; tt<t; tt++) iter ++;
            cout <<"Down "<<t<<endl;
        }else if(cmd[i][0]=='U'){
            t = (cmd[i][2]-'0');
            cout <<"Up "<<t<<endl;
            for(int tt=0; tt<t; tt++) iter--;
                
        }else if(cmd[i][0] == 'C'){
            lt.erase(iter);
            iter++;
            if(iter == lt.end()) iter--;
            //st.push({iter, *iter });
            
        }else if(cmd[i][0] == 'Z'){
            // auto tmp = st.top();
            // lt.insert(tmp.first, tmp.second);
            // st.pop();
        }
        
        for(auto k=lt.begin(); k != lt.end(); k++){
            cout <<*k<<" ";
        }
        cout <<*iter<<endl;
        cout <<endl;
    }
}

    
    
    