#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    string a,b;
    cin>> a>>b;

    int max_a = 1;
    int max_b = 1;
    int t;
    for(int i=0; i<a.size(); i++){
        t =  (a[i] <'9')? a[i]-'0' : a[i]-'a'+10;
        max_a = max(max_a,t);
    }
    for(int i=0; i<b.size(); i++){
        int t =  (b[i] <'9')? b[i]-'0' : b[i]-'a'+10;
        max_b = max(max_b,t);
    }
    //cout <<max_a<<" "<<max_b<<endl;
    int cnt = 0;
    long long ans_a, ans_b, ans_x;
    for(int i=max_a; i<=36; i++){
        //cout <<"i:"<<i<<" ";
        long long a_sum = 0;
        for(int k=a.size()-1; k>=0; k--){
            t = (a[k] <'9')? a[k]-'0' : a[k]-'a'+10;
            a_sum+= t*pow(i,a.size()-1-k);
        }
        for(int j=max_b; j<=36; j++){
            //cout <<"j:"<<j<<endl;
            long long b_sum = 0;
            for(int l=b.size()-1; l>=0; l--){   
                t = (b[l] <'9')? b[l]-'0' : b[l]-'a'+10;
                b_sum+= t*pow(j,b.size()-1-l);
                if(a_sum<b_sum) break;
            }
            //cout <<"asum: "<<a_sum<<" b_sum"<<b_sum<<endl;
            if(a_sum == b_sum && i!=j){
                cnt++;
                ans_a = i;
                ans_b = j;
                ans_x = a_sum;
                //cout <<"i: j"<<i<<" "<<j<< a_sum<<endl;
            } 
        }
    }
    if(cnt ==0 || (a=="z" || b=="z") ){
        cout <<"Impossible"<<endl;
    }else if(cnt == 1){
        cout <<ans_x<<" "<<ans_a<<" "<<ans_b<<endl;
    }else{
        cout <<"Multiple"<<endl;
    }
    return 0;

}