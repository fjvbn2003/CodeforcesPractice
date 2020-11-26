#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;
int visited[103];
pair<int,int> arr[103];
bool solve(int x){
	if(x==n+1)return true;
	bool s=false;
	visited[x]=1;
	for(int i=1;i<n+2;++i){
		if(i==x)continue;
		if(!visited[i]&&abs(arr[i].first-arr[x].first)+abs(arr[i].second-arr[x].second)<=1000)s|=solve(i);
	}
	return s;
}
int main(){
	bool s;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n+2;++i)visited[i]=0;
		for(int i=0;i<n+2;++i)scanf("%d %d",&arr[i].first,&arr[i].second);
		s=solve(0);
		printf(s?"happy\n":"sad\n");
	}
}