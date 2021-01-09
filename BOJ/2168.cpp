#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b){
    if(b>a){swap(a,b);}
    if(b==0) return a;
    return gcd(b, a%b);
}
int main(){
    int x,y;
    cin>> x>>y;
    int gcdd = gcd(x,y);
    cout << x+y-gcdd<<endl;
    return 0;
}