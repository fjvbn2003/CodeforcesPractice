#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int m , c;
    int dp[101][101];
    int arr[101][101];
    for(int i=0; i<101; i++){
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    cin>> c>>m;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=c; j++){
            cin>>arr[i][j];
        }
    }
    // for(int i=0; i<=m; i++){
    //     for(int j=0; j<=c; j++){
    //         cout <<dp[i][j]<<" ";
    //     }
    //     cout <<endl;
    // }
    for(int i=1; i<=m; i++){
        for(int j=0; j<=c; j++){
            int tmp_max = -1;
            for(int k=0; k<=j; k++){
                // cpu를 k개 만큼 i 상인에게 판매하는 경우 Optimal한 판매수익을 얻으려면, 
                // i-1번째에서 j-k개의 최적의 해에 k개를 판매하는 경우를 더하면 된다.
                tmp_max = max(dp[i-1][j-k]+arr[i][k],tmp_max );
            }
            dp[i][j] = tmp_max;
        }
    }
    // for(int i=0; i<=m; i++){
    //     for(int j=0; j<=c; j++){
    //         cout <<dp[i][j]<<" ";
    //     }
    //     cout <<endl;
    // }
    cout << dp[m][c]<<endl;
    return 0;
}


// reference
// https://github.com/lukasstevens/gcpc-2016/blob/master/src/CPU.cpp

// #include<iostream>
// #include<algorithm>
// #include<vector>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
    
//     int cpu_cnt;
//     int merch_cnt;
//     cin >> cpu_cnt >> merch_cnt;
   
//     vector<int> prev_max_money(cpu_cnt + 1);
//     for (int merch_idx = 0; merch_idx < merch_cnt; ++merch_idx) {
//         vector<int> curr_max_money(prev_max_money);
//         for (int offer = 1; offer <= cpu_cnt; ++offer) {
//             int money;
//             cin >> money;
//             for (int prev_cpu_cnt = 0; prev_cpu_cnt <= cpu_cnt; ++prev_cpu_cnt) {
//                 if (prev_cpu_cnt - offer >= 0) {
//                     curr_max_money[prev_cpu_cnt - offer] =
//                         max(
//                                 curr_max_money[prev_cpu_cnt - offer],
//                                 prev_max_money[prev_cpu_cnt] + money 
//                            );
//                 }
//             }
//         }
//         prev_max_money = std::move(curr_max_money);
//     }

//     cout << *max_element(prev_max_money.begin(), prev_max_money.end());
// }


// Arup Guha
// 2/11/2017
// Solution to 2016 German Programming Contest Problem J: Selling CPUs
// ref: http://www.cs.ucf.edu/~dmarino/progcontests/mysols/collegeother/gcpc/2016/j.java
// import java.util.*;

// public class j {
	
// 	public static void main(String[] args) {
		
// 		// Read in all the input data.
// 		Scanner stdin = new Scanner(System.in);
// 		int n = stdin.nextInt();
// 		int numM = stdin.nextInt();
// 		int[][] price = new int[numM][n+1];
// 		for (int i=0; i<numM; i++)
// 			for (int j=1; j<=n; j++)
// 				price[i][j] = stdin.nextInt();
				
// 		// DP array - res[i] = best answer for i CPUs.
// 		int[] res = new int[n+1];
		
// 		// Go through each merchant.
// 		for (int i=0; i<numM; i++) {
			
// 			// Store new answers here.
// 			int[] tmp = new int[n+1];
			
// 			// Get best answer for j CPUs incorporating this merchant.
// 			for (int j=0; j<=n; j++) {
				
// 				// k represents the number of CPUs we buy from this merchant. We simply want the
// 				// best possible result for the remaining j-k CPUs which are stored in res.
// 				for (int k=0; j-k>=0; k++)
// 					tmp[j] = Math.max(tmp[j], price[i][k]+res[j-k]);
				
// 			}
			
// 			// Update for next loop iteration.
// 			res = tmp;
// 		}
		
// 		// We want the best answer of all of these.
// 		int ans = 0;
// 		for (int i=0; i<res.length; i++) ans = Math.max(ans, res[i]);
// 		System.out.println(ans);
// 	}
// }