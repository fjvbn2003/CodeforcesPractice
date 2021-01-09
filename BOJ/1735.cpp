#include<iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(a<b){swap(a,b);}
    if(b==0) return a;
    return gcd(b, a%b);
}


int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int mo = b*d;
    int ja = d*a +b*c;
    int gcdd = gcd(mo,ja);
    cout << ja/gcdd<< " "<<mo/gcdd<<endl;
    return 0;
}