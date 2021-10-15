#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
// if(N==M) 한번만 센다.
int main(){
  int test_case;
  cin>>test_case;
  while(test_case--){
    long long N,M,K;
    cin>>N>>M>>K;
    vector<int> arr(N);
    for(int i=0; i<N; i++)
      cin>>arr[i];
    
    //초깃 값;
    int ans = 0;
    long long tmp = 0;
    for(int i=0; i<M; i++){
      tmp += arr[i];
    }
    if(tmp<K) ans++;
    // N이랑 M이랑 같다면 한번만 세야함.
    if(N!=M)
      for(int i=1; i<N; i++){
        //i ~ i+M-1까지의 합.
        tmp-=arr[i-1];
        tmp+=arr[(i+M-1)%N];
        if(tmp<K){
          ans++;  
          //cout << "find i: "<<i<<" tmp:"<<tmp<<endl;
        }
      }
    cout <<ans<<"\n";

  }

  return 0;
}