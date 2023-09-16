#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
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