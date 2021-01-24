#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c,x,y, rx, ry, cand;
    cin>> a>>b>>c>>x>>y;
    int cnt_c = 0;//cnt_c 하나당리 후라이드 양념 한마리
    int ans = 987654321;
    while(cnt_c<=x || cnt_c<=y){
        rx = max(0, x-cnt_c);
        ry = max(0, y-cnt_c);
        cand = rx*a + ry*b + cnt_c*c*2;
        if(ans > cand){
            //cout << cnt_c<<" "<<rx<<" "<<ry<<endl;
            ans = cand;
        }
        cnt_c++;
    }
    cout <<ans<<endl;
    return 0;
    
}