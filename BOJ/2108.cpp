#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
    //ifstream cin("input.txt");
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    double s = accumulate(arr.begin(), arr.end(), 0);
    int cnt = 0;
    int before = arr[0];
    vector<pair<int, int> > occurence;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == before)
        {
            cnt++;
        }
        else
        {
            occurence.push_back(make_pair(cnt, arr[i - 1]));
            cnt = 1;
        }
        before = arr[i];
    }
    occurence.push_back(make_pair(cnt, arr[n - 1]));
    sort(occurence.begin(), occurence.end());
    int size_occurence = occurence.size();
    int max_occurence = occurence[size_occurence - 1].first;

    cout << floor(s/n + 0.5) << endl;
    cout << arr[n / 2] << endl;
    if (size_occurence <= 1)
    {
        cout << occurence[size_occurence - 1].second<<endl;;
    }
    else if (occurence[size_occurence - 1].first != occurence[size_occurence - 2].first)
    {
        cout << occurence[size_occurence - 1].second<<endl;
    }
    else
    {
        bool find = false;
        for (int i = size_occurence - 2; i >= 0; i--)
        {
            if (occurence[i].first != max_occurence)
            {
                cout << occurence[i + 2].second << endl;
                find = true;
                break;
            }
        }
        if (find == false)
        {
            cout << occurence[1].second << endl;
        }
    }
    cout << arr[n - 1] - arr[0] << endl;
    return 0;
}