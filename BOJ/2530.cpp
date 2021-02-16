#include <iostream>

using namespace std;

int main(){
    int h,m,s;
    int delta;
    cin>> h>>m>>s;
    cin>> delta;
    while(delta){   
        s++;
        if(s==60){
            m++;
            s=0;
        }
        if(m==60){
            h++;
            m=0;
        }
        if(h==24){
            h=0;
        }
        delta--;
    }
    
    cout <<h <<" "<<m<<" "<<s<<endl;
}