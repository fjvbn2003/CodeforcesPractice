#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    vector<string> phone_book;
    phone_book.push_back("119");
    phone_book.push_back("97674223");
    phone_book.push_back("1195524421");

    
    sort(phone_book.begin(), phone_book.end());
    bool answer = true;
    for(int i=0; i<phone_book.size()-1; i++){
        if(phone_book[i].size() > phone_book[i+1].size()) continue;
        bool flag = false;
        for(int j=0; j<phone_book[i].size(); j++){
            if(phone_book[i][j] != phone_book[i+1][j]){
                flag = true;
                break;
            }
        }
        if(flag){
            answer = false;
            break;
        }
    }
    cout << answer<< endl;
    return 0;
}