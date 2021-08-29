#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = 1e18;
    
    vector< vector<int> > arr(n, vector<int>(n, 987654321) );
    
    for(int i=0; i<n; i++)
        arr[i][i] = 0;
    for(auto f : fares){
        arr[f[0]-1][f[1]-1] = f[2];
        arr[f[1]-1][f[0]-1] = f[2];
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
            }
        }
    }
    for(int i=0; i<n; i++){
        answer = min(answer, (long long)arr[s-1][i]+arr[i][a-1]+arr[i][b-1]);
    }
    
    return answer;
}