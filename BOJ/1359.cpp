#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m,k;
    int match;
    vector<int> p1;
    vector<int> p2;
    cin>> n>>m>>k;
    for(int i=0; i<n-m; i++){
        p1.push_back(0);
        p2.push_back(0);
    }
    for(int i=0; i<m; i++){
        p1.push_back(1);
        p2.push_back(1);
    }
    sort(p1.begin(), p1.end());
    double up = 0;
    do{
        sort(p2.begin(), p2.end());
        do{
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(p1[i]== 1 && p2[i]==1){
                    cnt++;
                }
            }
            if(cnt>=k){
                up+= 1;
            }
        }while(next_permutation(p2.begin(), p2.end()));
    }while(next_permutation(p1.begin(), p1.end()));
    double down =1;
    for(int i=n; i>=n-m+1; i--){
        down*=i;
    }
    for(int i=m; i>=1; i--){
        down /=i;
    }
    down = down*down;
    cout<<fixed;
    cout.precision(16);
    cout <<up/down<<endl;
    return 0;

}