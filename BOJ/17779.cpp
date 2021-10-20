//
// Created by Yongju KIM on 2021/10/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int arr[21][21];
void dfs(int r, int c, int color, vector<vector<int> >& tmp){
    if(r<0 || r>=N || c<0 || c>=N) return;
    if(tmp[r][c] != 0) return;
    tmp[r][c] = color;
    dfs(r+1,c, color, tmp);
    dfs(r,c+1, color, tmp);
    dfs(r-1,c, color, tmp);
    dfs(r,c-1, color, tmp);
    return ;

}
int solve(){
    int ans = 1234567890;
    for(int x=0; x<=N-3; x++){
        for(int y =1; y<=N-2; y++){
            for(int d1=1; x+d1<=N-2 && y-d1>=0; d1++){
                for(int d2=1; x+d2<=N-2 && y+d2<=N-1; d2++){
                    if(x+d1+d2 <=N-1){
                        vector<vector<int> >tmp(N, vector<int>(N,0));
                        // 경계선 그리기.
                        for(int i=0; i<=d1; i++){
                            tmp[x+i][y-i] = 5;
                            tmp[x+d2+i][y+d2-i] = 5;
                        }
                        for(int i=0; i<=d2; i++){
                            tmp[x+i][y+i] = 5;
                            tmp[x+d1+i][y-d1+i] = 5;
                        }
                        for(int i=x-1; i>=0; i--) tmp[i][y] = 1;
                        for(int i=y-d1-1; i>=0; i--) tmp[x+d1][i] = 3;
                        for(int i=y+d2+1; i<=N-1; i++) tmp[x+d2][i] = 2;
                        for(int i=x+d1+d2+1; i<=N-1; i++) tmp[i][y-d1+d2] = 4;


                        //색깔 칠하기.
                        dfs(0,0,1, tmp);
                        dfs(0,N-1,2, tmp);
                        dfs(N-1,0,3, tmp);
                        dfs(N-1,N-1,4, tmp);

//                        cout << "x: "<<x<<" y:"<<y<<" d1: "<<d1<<" d2:"<<d2<<endl;
//                        for(int i=0; i<N; i++){
//                            for(int j=0; j<N; j++) {
//                                cout <<tmp[i][j]<<" ";
//                            }
//                            cout <<endl;
//                        }
//                        cout <<endl;

                        vector<int> population(6,0);
                        for(int i=0; i<N; i++){
                            for(int j=0; j<N; j++){
                                population[tmp[i][j]] += arr[i][j];
                            }
                        }
                        int min_p = 123456789;
                        int max_p = -1;
                        population[5]+= population[0];
                        for(int i=1; i<population.size(); i++){
                            min_p = min(min_p, population[i]);
                            max_p = max(max_p, population[i]);
                        }

                        ans = min(ans, max_p- min_p);
                    }
                }
            }
        }
    }


    return ans;
}


int main(){
    cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
           cin>>arr[i][j];
        }
    }
    cout <<solve()<<endl;

    return 0;

}