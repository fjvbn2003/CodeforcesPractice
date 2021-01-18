#include <iostream>
using namespace std;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int dir = 0;

int arr[1000][1000];
int main(){
    int n,k;
    cin>>n>>k;
    int x = 0;
    int y = -1;
    int cnt = n*n;
    int gap = n;
    int two =  1;
    while(cnt>0){
        for(int i=0; i<gap; i++){
            //cout<< "dy[dir]: "<<dy[dir]<<endl;
            y = y + dy[dir];
            x = x + dx[dir];
            //cout <<"y: "<<y<<"x: "<<x<<"cnt: "<<cnt<<endl;
            arr[y][x] = cnt;
            cnt--;
            //cout <<cnt<<endl;
        }
        //cout <<cnt<<endl;
        two++;
        dir = dir+1;
        dir%=4;
        if(two==2){
            //cout << "int two"<<endl;
            two = 0;
            gap--;
        }
    }
    int ix,iy;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j]<<" ";
            if(arr[i][j]==k){
                iy = i;
                ix = j;
            }
        }
        cout <<endl;
    }
    cout << iy+1<<" "<<ix+1<<endl;
    return 0;

}