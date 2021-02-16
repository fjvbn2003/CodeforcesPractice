#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>> s;
    int left = 0;
    int right = n/2;
    bool dif = false;
    while(left != n/2 && right != n-1){
        if(dif && s[left] != s[right]){
            dif  = false;
            break;
        }

        if(s[left] != right){
            right++;
            dif = true;
            continue;
        }
        left++;
        right++;
    }

}