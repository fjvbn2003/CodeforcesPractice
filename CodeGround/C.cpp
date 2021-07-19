/*
#include <iostream>
#include <vector>

using namespace std;
vector<int> adj[501];
int dis[501];
int fini[501];
int N,M,K,a,b;
int cnt = 0;
void init(int n){
  for(int i=0;i<=n; i++){
    dis[i] = -1;
    fini[i] = 0;
  }
}

bool dfs_has_cycle(int h){
  cnt++;
  dis[h] = cnt;
  bool ret = false;
  for(int i=0; i<adj[h].size(); i++){
    int t = adj[h][i];
    if(dis[t]==-1){
      ret |= dfs_has_cycle(t);
    }else if(fini[t]==0){
      return true;
    }else{
      continue;
    }
  }
  fini[h]=1;
  return ret;
}
int main(){
  int test_case;
  cin>> test_case;
  while(test_case--){

    cin>>N>>M>>K;
    cnt = 0;
    vector<pair<int,int> > Ks;
    for(int i=0; i<=N; i++){
      adj[i].clear();
      dis[i]=-1;
      fini[i]=0;
    }

    for(int i=0; i<M; i++){
      cin>>a>>b;
      adj[a].push_back(b);
    }
    for(int i=0;i<K; i++){
      cin>>a>>b;
      Ks.push_back(make_pair(a,b));
    }

    vector<int> ans;
    for(int tt=0; tt<K; tt++){
      a = Ks[tt].first;
      b = Ks[tt].second;
      init(N);
      adj[a].push_back(b);
      bool cycle = false;
      for(int i=1; i<=N; i++){
        if(fini[i]==0)
          cycle |= dfs_has_cycle(i);
        if(cycle) break;
      }
      if(!cycle){
        ans.push_back(0);
      }else{
        adj[a].pop_back();
        adj[b].push_back(a);
        ans.push_back(1);
      }
    }
    for(int i=0; i<K; i++){
      cout<<ans[i];
    }
    cout <<endl;
  }

}
*/
/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[501];
int dis[501];
int fini[501];
int N,M,K,a,b;
int cnt = 0;
void init(int n){
  for(int i=0;i<=n; i++){
    dis[i] = -1;
    fini[i] = 0;
  }
}
bool dfs_has_cycle(int h){
  cnt++;
  dis[h] = cnt;
  bool ret = false;
  for(int i=0; i<adj[h].size(); i++){
    int t = adj[h][i];
    if(dis[t]==-1){
      ret |= dfs_has_cycle(t);
    }else if(fini[t]==0){
      return true;
    }else{
      continue;
    }
  }
  fini[h]=1;
  return ret;
}
int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin>>N>>M>>K;
        cnt = 0;
        vector<pair<int,int> > Ks;
        for(int i=0; i<=N; i++){
            adj[i].clear();
            dis[i]=-1;
            fini[i]=0;
        }

        for(int i=0; i<M; i++){
          cin>>a>>b;
          adj[a].push_back(b);
        }
        for(int i=0;i<K; i++){
          cin>>a>>b;
          Ks.push_back(make_pair(a,b));
        }
    
        vector<int> ans;
        for(int tt=0; tt<K; tt++){
          a = Ks[tt].first;
          b = Ks[tt].second;
          init(N);
          adj[a].push_back(b);
          bool cycle = false;
          for(int i=1; i<=N; i++){
            if(fini[i]==0)
              cycle |= dfs_has_cycle(i);
            if(cycle) break;
          }
          if(!cycle){
            ans.push_back(0);
          }else{
            adj[a].pop_back();
            adj[b].push_back(a);
            ans.push_back(1);
          }
        }

		cout << "Case #" << test_case+1 << endl;
		for(int i=0; i<K; i++){
            cout<<ans[i];
        }
        cout <<endl;
	}

	return 0;//Your program should return 0 on normal termination.
}