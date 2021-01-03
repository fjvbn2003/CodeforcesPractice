#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n;
    int cnt = 0;
    cin>>n;
    for(int i=1; i<=n; i++){
        int t = i;
        if(t<10){cnt++; continue;}
        if(t <100){cnt++; continue;}
        int before = t%10;
        t/=10;
        int diff = before- t%10;
        before = t%10;
        t/=10;
        bool flag  = false;
        while(t){
            if(diff != before-t%10){
                flag = true;
                break;
            }
            before = t%10;
            t/=10;
        }
        if(flag) continue;
        else cnt++;
    }
    cout <<cnt<<endl;

}