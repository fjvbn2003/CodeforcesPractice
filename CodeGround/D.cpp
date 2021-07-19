/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long Answer;

int main(int argc, char** argv)
{
	long long T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
    long long n,m,L;
    cin>>n>>m;
    vector<vector<long long> > arr;
    vector<pair<long long, int > >pen;
    for(int i=0; i<n; i++){
      cin>>L;
      vector<long long> t(L);
      for(int j=0; j<L; j++){
        cin>> t[j];
      }
      sort(t.begin(), t.end());
      pen.push_back(make_pair(t[2]+t[3],i));
      arr.push_back(t);
    }
    sort(pen.begin(), pen.end());
    int max_idx1 = pen[n-1].second;
    int max_idx2 = pen[n-2].second;
    for(int i=0; i<n; i++){
      if(i == max_idx1 || i== max_idx2 ){
        Answer +=(arr[i][0]+arr[i][0]+arr[i][1]);
      }else{
        Answer+= (arr[i][0]+arr[i][0]+arr[i][1]+arr[i][2]+arr[i][3]);
      }
    }
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}