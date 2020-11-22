#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-variable"

#include <bits/stdc++.h>
using namespace std;
void solve();
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    #ifdef hi
    freopen("./input.txt","r",stdin);
    freopen("./output.txt","w",stdout);
    #endif 


        solve();

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
void solve(){
    long long r1,c1,r2,c2;
    cin>> r1>>c1>>r2>>c2;
    long long diff1 = r1-c1;
    long long diff2 = r2-c2;
    if(r1==r2 && c1 == c2){
        cout << 0<<endl;
    }
    else if(r1+c1 == r2+c2 || r1-c1 == r2-c2 || ((long long)abs(r1-r2)+ (long long)abs(c1-c2))<=3){
        cout << 1<<endl;        
    }else{
       if((r1+c1)%2 == (r2+c2)%2 ){
           cout << 2<<endl;
       }else{
           cout <<3<<endl;
       }
    }
    

}
/*
Author: fjvbn2003
Round: #
problem: C.
*/