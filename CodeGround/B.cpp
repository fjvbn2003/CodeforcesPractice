/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

        int n, t;
        string s;
        cin>> n>>t;
        cin>> s;
        vector<int> A(n+1,0);
        vector<int> B(n+1,0);
  
        for(int i=0; i<n; i++)
            B[i+1] = s[i]-'0';

    // Greedy 한 방향으로 무조건 뒤에다가만 뿌리고 못 뿌리면 어쩔 수 없이 앞에다가 뿌리기
        for(int i=1; i<=n; i++){
            if(B[i]>=1){
                if(i-t<1){
                  A[i+t] = 1;
                }else if(i+t>n){
                  A[i-t] = 1;
                }else{
                  if(A[i-t]==1){
                    continue;
                  }
                  else if((i+t+t <=n && B[i+t+t]==1) || (i+t+t>n)){
                    A[i+t] =1;
                  }else{
                    A[i-t] = 1;
                  }
                }

            }else{
                continue;
            }
        }

		cout << "Case #" << test_case+1 << endl;
        for(int i=1; i<=n; i++)
            cout <<A[i];
        cout <<endl;
	}

	return 0;//Your program should return 0 on normal termination.
}