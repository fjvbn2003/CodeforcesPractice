#include <iostream>
#include <string>
#include <set>
using namespace std;
string s;
int n;
set<int> sett;
int arr[10] = {0,};
void brute(string t){
    if(t != ""){
        int tmp = stoi(t);
        sett.insert(tmp);
    }
    for(int i=0; i<10; i++){
        if(arr[i]>0){
            arr[i]--;
            brute(t + to_string(i));
            arr[i]++;
        }
    }
    return ;
}

int main(){
    
    cin>> s;
    n = s.size();
    for(int i=0; i<s.size(); i++){
        arr[s[i]-'0']++;
    }
    brute("");
    int answer = 0;
    for(int i : sett){
        bool flag = false;
        if(i==2){
            answer++;
            continue;
        } 
        if(i== 1 || i%2 ==0) continue;
        else{
            for(int j=3; j*j<=i; j+=2){
                if(i%j ==0){
                    flag = true;
                    break;
                }  
            }
        }
        if(!flag){
            answer++;
        }
    }
    cout <<answer<<endl;
    return 0;
}