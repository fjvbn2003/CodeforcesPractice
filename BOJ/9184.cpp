#include <iostream>

using namespace std;
long long dp[51][51][51];
long long recur(long long a, long long b, long long c){
    
    if(a<=0 || b <=0 || c<=0) return 1;
    if(a>20 || b>20 || c>20) return recur(20,20,20);
    long long& ret = dp[a][b][c];
    if(ret != 0) return ret;
    if(a<b && b<c) return ret = (recur(a,b,c-1)+recur(a,b-1,c-1)- recur(a,b-1,c));
    return ret = (recur(a-1,b,c)+recur(a-1,b-1,c)+recur(a-1,b,c-1)-recur(a-1,b-1,c-1));
}


int main(){
    long long a,b,c;
    for(int i=0; i<51; i++)
            for(int j=0; j<51; j++)
                for(int k=0; k<51; k++)
                    dp[i][j][k] = 0;

    while(true){
        
        cin>>a>>b>>c;
        if(a==-1 && b==-1 && c==-1) return 0;
        cout <<"w("<<a<<", "<<b<<", "<<c<<") = "<<recur(a,b,c)<<endl;
    }
}