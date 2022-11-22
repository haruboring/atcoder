#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string T;
    cin >> T;
    vector<vector<int>> avg = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    vector<int> ans = {0, 0};
    int cnt = 0;
    rep(i, N) {
        if (T[i] == 'S') {
            ans[0] += avg[cnt % 4][0];
            ans[1] += avg[cnt % 4][1];
        } else {
            cnt++;
        }
    }
    cout << ans[0] << " " << ans[1] << endl;
}