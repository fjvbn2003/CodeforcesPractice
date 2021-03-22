#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int test_case;
    cin>> test_case;
    while(test_case--){
        int x=0, y=0;
        //북 동 남 서
        int dy[4] = {1,0,-1,0};
        int dx[4] = {0,1,0,-1};
        string s;
        cin>> s;
        int dir = 0;
        int left_most_x = 0;
        int right_most_x = 0;
        int high_most_y = 0;
        int low_most_y = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='F'){
                x += dx[dir];
                y += dy[dir];
            }else if(s[i]=='B'){
                x -= dx[dir];
                y -= dy[dir];
            }else if(s[i]=='L'){
                dir+=4;
                dir--;
                dir%=4;
            }else if(s[i]=='R'){
                dir++;
                dir%=4;
            }
            //cout <<"x"<<x<<" "<<"y"<<y<<"dir "<<dir<<endl;
            left_most_x = min(x, left_most_x);
            right_most_x = max(x, right_most_x);
            high_most_y = max(y, high_most_y);
            low_most_y = min(y, low_most_y);
        }
        cout << (right_most_x-left_most_x)*(high_most_y-low_most_y)<<endl;
    }
    return 0;

}