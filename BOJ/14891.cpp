#include <iostream>
#include <cmath>
using namespace std;
char arr[4][8];
void turn(int wheel, int dir){
    
    if( dir==1){
        int last = arr[wheel][7];
        for(int i=7; i>0; i--){
            arr[wheel][i] = arr[wheel][i-1];
        }
        arr[wheel][0] = last;
    }else{
        int first = arr[wheel][0];
        for(int i=0; i<7; i++){
            arr[wheel][i] = arr[wheel][i+1];
        }
        arr[wheel][7] = first;
    }
    return ;
}
void draw(){
    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            cout << arr[i][j];
        }
        cout <<endl;
    }
}
int main(){
    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            cin>>arr[i][j];
        }
    }
    int k,a,b;
    cin>>k;
    for(int i=0; i<k; i++){
        cin>> a>>b;
        if(a ==1){
            if(arr[0][2] != arr[1][6]){
                if(arr[1][2] != arr[2][6]){
                    if(arr[2][2] != arr[3][6]){
                        turn(3,-b);
                    }
                    turn(2,b);
                }
                turn(1,-b);
            } 
            turn(0,b);
        }else if(a == 2){
            // left
            if(arr[0][2] != arr[1][6]){
                turn(0,-b);
            }
            //right
            if(arr[1][2] != arr[2][6]){
                if(arr[2][2] != arr[3][6]){
                    turn(3,b);
                }
                turn(2,-b);
            }
            turn(1,b);
        }else if( a == 3){
            //left
            if(arr[2][6] != arr[1][2]){
                if( arr[1][6] != arr[0][2] ){
                    turn(0,b);
                }
                turn(1,-b);
            }
            //right
            if(arr[2][2] != arr[3][6]){
                turn(3,-b);
            }
            turn(2,b);
        }else{
            if(arr[3][6] != arr[2][2]){
                if(arr[2][6] != arr[1][2]){
                    if(arr[1][6] != arr[0][2]){
                        turn(0,-b);
                    }
                    turn(1,b);
                }
                turn(2,-b);
            }
            turn(3,b);
        }
        //draw();
    }
    int ans = 0;
    for(int i=0; i<4; i++){
        if(arr[i][0] =='0'){
            continue;
        }else{
            ans+= pow(2, i);
        }
    }
    cout <<ans<<endl;
    return 0;
    
}