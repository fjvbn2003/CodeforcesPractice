#include <iostream>
#include <string>

using namespace std;

int main(){

    int n;
    cin>>n;
    bool even = (n%2 == 0);
    int offset = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==1 || i== n || j==1 || j ==n ){
                cout <<'*';
            }else if(j-1==offset || (n-offset)==j){
                cout <<'*';
            }
            else{
                cout <<' ';
            }
        }
        if(even){
        if(i < n/2) offset++;

        }else{
            if(i <= n/2) offset++;
        }
        if(i>n/2) offset--;
        cout <<endl;
    }


}