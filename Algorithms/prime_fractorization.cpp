#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cout << "소인수 분해할 숫자를 입력하세요: ";
    cin>> t;
    int n = t;
    vector<int> factor;
	for (int i = 2; i * i <= t; ++i) {
		while (n % i == 0) {
			n /= i;
            factor.push_back(i);
		}
	}
    if(n!=1){
        factor.push_back(n);
    }
    if(factor.size() ==1){
        cout << t<<" 은 소수입니다."<<endl;
    }else{
        cout << t<<" 을 소인수분해하면, "<<endl;
        for( int i : factor){
            cout <<i<<" ";
        }
        cout << " 입니다."<<endl;
    }
}