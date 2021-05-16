#include <iostream>
#include <string>
using namespace std;
int answer = 1;
void brute(string& s,int idx, int first, int last, int k, int n, int second){
    if(idx == second){
        int before = last;
        for(int i=last-1; i>=0; i--){
            if(s[i]=='x'){
                if(before-i >k){
                    return;
                }
            }
        }
        answer++;
        return ;
    }
    
    for(int i=idx+1; i<n; i++){
        if(s[i]=='*' && i-idx <=k){
            s[i] = 'x';
            brute(s,i,first,last,k,n, second);
            s[i] ='*';
            brute(s,i,first,last,k,n, second);
        }

    }
    cout <<s<<endl;
    return;
}

int main(){
    int test_case;  
    cin>> test_case;
    while(test_case--){
        int n,k;
        string s;
        cin>>n>>k>>s;
        int first_x;
        int last_x;
        int last_second = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='*'){
                s[i] = 'x';
                first_x = i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(s[i]=='*'){
                s[i] = 'x';
                last_x = i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(s[i]=='*'){
                
                last_second = i;
                break;
            }
        }
        answer = 1;
        brute(s,first_x,first_x,last_x,k,n, last_second);
        cout << answer<<endl;
    }
    return 0;
}