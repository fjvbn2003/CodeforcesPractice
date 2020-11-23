#include <iostream>
#include <string>
using namespace std;
int main(){
    string s ="abcdef";
    string s1 = s.substr(2,3);
    string s2 = s.substr(1);
    cout <<"원래 문자열: "<< s<<endl;
    cout << "s.substr(2,3): "<< s1<<endl;
    cout << "s.substr(1): "<< s2<<endl;
}