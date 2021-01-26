#include <iostream>
using namespace std;
 
int N, M;
int arr[300];
 
bool isPossible(int mid) {
    int sum = 0, groupCnt = 1;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        if (sum > mid){
            sum = arr[i];
            groupCnt++;
        }
    }
    return groupCnt <= M;
}
 
void printAns(int mid){
    cout << mid << '\n';
 
    int i, sum = 0, marbleCnt = 0;
    for (i=0; i < N; i++) {
        sum += arr[i];
        if (sum > mid) {
            sum = arr[i];
            M--;
            cout << marbleCnt << " ";
            marbleCnt = 0;
        }
        marbleCnt++;
        // M개의 그룹을 만들기 위해 최소한의 구슬은 남겨둡니다.
        // (나머지 그룹에 적어도 구슬 1개를 배치해야 하기 때문.)
        if (N - i == M) break;
    }
 
    // 위에서 구한 구슬 개수를 현재 그룹까지만 출력하고
    // 나머지 남은 그룹에는 구슬 1개씩 배치
    while (M--){
        cout << marbleCnt << " ";   
        marbleCnt = 1;
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    int left = 0, right = 0, mid;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
        // 원소 중 최대값으로 left 설정
        left = left < arr[i] ? arr[i] : left;
        right += arr[i];
    }
        
    while (left <= right) {
        mid = (left + right) / 2;
        if(isPossible(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
 
    // 정답 출력
    printAns(left);
}
