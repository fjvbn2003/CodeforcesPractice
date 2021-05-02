#include <iostream>
#include <vector>
#include <array>
#include <set>

using namespace std;

int main(){
    int n;
    cin>> n;
    vector<array<int,5> > A(n);
    for(auto& a: A) for(int &i :a) cin>> i;
    //for(auto& a: A) for(int &i :a) cout <<i<<" ";
    int left=0, right = 1e9+1;
    auto check = [&](int x)-> bool{
        set<int> s;
        for(auto& a: A){
            int bit = 0;
            for(int& i :a){
                bit <<=1;
                bit |= i>=x;
            }
            s.insert(bit);
        }
        for(int x: s) for(int y: s) for(int z: s){
            if((x|y|z)==31) return 1;
        }
        return 0;
    };
    while(left+1<right){
        int cen = (left + right) / 2;
        if(check(cen)){
            left = cen;
        }else{
            right = cen;
        }   
    }
        
    cout << left << endl;
    return 0;
}