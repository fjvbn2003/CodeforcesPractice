#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(){
    int n = 10;
    list<int> lt;
    for(int i=0; i<n; i++){
        lt.push_back(i);
    }
    auto iter = lt.begin();
    // 0 1 2 3 4 5 6 7 8 9;
    iter++;
    iter = lt.erase(iter);
    for(auto t = lt.begin(); t != lt.end(); t++){
        //if(t == lt.end()) cout << "last"<<endl;
        cout << *t<<" ";
    }
    cout <<endl;
    iter = lt.end();
    *iter = 100;
    cout<< *iter<<endl;
iter = lt.end();
iter--;

    cout<< *iter<<endl;
    for(auto t = lt.begin(); t != lt.end(); t++){
        //if(t == lt.end()) cout << "last"<<endl;
        cout << *t<<" ";
    }
    cout <<endl;
}