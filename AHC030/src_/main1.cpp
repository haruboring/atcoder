#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// 提出 #50117797
signed main() {
    int N, M;
    cin >> N >> M;
    double e;
    cin >> e;
    vector<int> d(M);
    vector<vector<pair<int, int>>> ij(M);
    rep(s, M) {
        cin >> d[s];
        rep(_, d[s]) {
            int i, j;
            cin >> i >> j;
            ij[s].push_back({i, j});
        }
    }

    int oil_sum = accumulate(all(d), 0);
    vector<pair<int, int>> has_oil(0);
    int oil_count = 0;

    rep(i, N) {
        rep(j, N) {
            if (oil_count >= oil_sum) continue;
            cout << "q 1 " << i << " " << j << endl;
            int response;
            cin >> response;
            if (response != 0) {
                has_oil.push_back({i, j});
                oil_count++;
            }
        }
    }

    cout << "a " << has_oil.size() << " ";
    for (auto [i, j] : has_oil) {
        cout << i << " " << j << " ";
    }
    cout << endl;
}

// 163000000
// 12679000000