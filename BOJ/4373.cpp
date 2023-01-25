// ref: https://eine.tistory.com/entry/%EB%B0%B1%EC%A4%80-4373%EB%B2%88-%EB%AC%B8%EC%A0%9C-%EC%88%98%EC%A7%91%ED%95%A9-%ED%92%80%EC%9D%B4
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

bool comp1(pair<int, int> &a, pair<int,int> &b){
  return a.first+a.second < b.first+b.second;
}
bool comp2(pair<int, int> &a, pair<int,int> &b){
    if(a.first-a.second == b.first-b.second){
        return a.first > b.first;
    }
  return a.first-a.second < b.first-b.second;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    while(1){
        int n; 
        cin>>n;
        if(n==0) return 0;
        else if(n<4){
            cout <<"no solution"<<endl;
        }
        else{
            // 집합 S
            vector<int> S(n);
            // permutation 생성을 위한 bool 배열생성
            for(int i=0; i<n; i++){
                cin>> S[i];
            }
            // sort(V.begin(), V.end());
            sort(S.begin(), S.end());
            vector< pair<int, int> > ab_pair;
            vector< pair<int, int> > dc_pair;
            
            for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                    ab_pair.push_back({S[i],S[j]});
                }
            }
            for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                    dc_pair.push_back({S[i],S[j]});
                    dc_pair.push_back({S[j],S[i]});
                }
            }
            // ab_pair는 합으로 정렬
            sort(ab_pair.begin(), ab_pair.end(), comp1);
            // dc_pair는 차로 정렬
            sort(dc_pair.begin(), dc_pair.end(), comp2);

            //two pointer
            int left_idx=0;
            int left_max=ab_pair.size();
            int right_idx=0;
            int right_max=dc_pair.size();
            int ans = -1234567890;
            while(left_idx < left_max && right_idx <right_max){
                int left_sum = ab_pair[left_idx].first +ab_pair[left_idx].second;
                int right_diff = dc_pair[right_idx].first - dc_pair[right_idx].second;
                //cout << "left_idx: "<< left_idx<<" left_sum: "<<left_sum <<" right_idx: "<<right_idx<<" right_diff: "<< right_diff<<endl;
                if(left_sum > right_diff){
                    right_idx++;
                }else if(left_sum < right_diff){
                    left_idx++;
                }else{ // left_sum == right_diff
                    //cout << "left_idx: "<< left_idx<<" left_sum: "<<left_sum <<" right_idx: "<<right_idx<<" right_diff: "<< right_diff<<endl;
                    if(ab_pair[left_idx].first == dc_pair[right_idx].first || ab_pair[left_idx].first == dc_pair[right_idx].second || ab_pair[left_idx].second == dc_pair[right_idx].first ||ab_pair[left_idx].second == dc_pair[right_idx].second){
                       right_idx++;
                        continue;
                    }
                    ans = dc_pair[right_idx].first;
                    right_idx++;   
                }
            }

            // for(int i=0; i<ab_pair.size(); i++){
            //     cout << ab_pair[i].first<<" "<<ab_pair[i].second<<endl;
            // }
            // for(int i=0; i<dc_pair.size(); i++){
            //     cout << dc_pair[i].first<<" "<<dc_pair[i].second<<endl;
            // }
            if(ans ==  -1234567890){
                cout <<"no solution"<<endl;
            }else{
                cout << ans<<endl;
            }

        }

    }


}
