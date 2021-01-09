#include <iostream>
using namespace std;
long long a,b,c;
long long arr[1000001];
long long pro(long long times){
    if(times==1){return a;}
    if(times<1000001 && arr[times]){
        return arr[times];
    }
    long long ret;
    if(times%2 == 0){
        ret = (pro(times/2)%c *pro(times/2)%c)%c;
    }else{
        ret = (pro(times-1)*a)%c;
    }
    if(times<1000001) arr[times] = ret;
    return ret;
}


int main(){
    
    cin>> a>>b>>c;
    cout <<pro(b)%c<<endl;

}