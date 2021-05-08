#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int graph[51][51];
int visited[51];
int n;
void bfs(int from){
    queue<int> q;
    visited[from] = 0;
    q.push(from);
    
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(graph[t][i] == 1 && visited[i]==0){
                visited[i] = visited[t]+1;
                q.push(i);
            }
        }
    }
    return ;
}


int main(){
    vector<string> words;
    words.push_back("hot");
    words.push_back("dot");
    words.push_back("dog");
    words.push_back("lot");
    words.push_back("log");
    words.push_back("cog");
    
    string begin = "hit";
    string target = "cog";


    int answer = 0;
    int a,b;
    n = words.size();
    int length = words[0].size();
    for(int i=0; i<words.size(); i++){
        if(words[i] == begin) a = i;
        if(words[i] ==  target) b = i;
        for(int j=i+1; j<words.size(); j++){
            int same = 0;
            for(int k=0; k<length; k++){
                if(words[i][k] == words[j][k]){
                    same++;
                }
            }
            if(same == length-1){
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }

    }
    cout <<"a,b"<<a<<" "<<b<<endl;
    bfs(a);
    answer = visited[b];
   
}
