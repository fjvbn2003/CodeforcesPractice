//
// Created by Yongju KIM on 2021/11/14.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int test_case;
    cin>> test_case;
    while(test_case--){
        int a,b,c;
        cin>>a>>b>>c;
        int t = a+c;
        int tt = b;
        int ans = 1234567890;
        if(t>=2*tt){
            int remain = t-2*tt;
            remain/=3;
            t-=remain;
            tt+= remain;
            ans = min(ans, abs(t-2*tt));
            t-=1;
            tt+=1;
            ans = min(ans, abs(t-2*tt));
            t-=1;
            tt+=1;
            ans = min(ans, abs(t-2*tt));
            t-=1;
            tt+=1;
            ans = min(ans, abs(t-2*tt));

        }else if(t<2*tt){
            int remain = 2*tt-t;
            remain/=3;
            t+=remain;
            tt-= remain;
            ans = min(ans, abs(t-2*tt));
            t+=1;
            tt-=1;
            ans = min(ans, abs(t-2*tt));
            t+=1;
            tt-=1;
            ans = min(ans, abs(t-2*tt));
            t+=1;
            tt-=1;
            ans = min(ans, abs(t-2*tt));
        }


        cout <<ans<<endl;
    }

    return 0;
}