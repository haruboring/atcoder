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
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    vector<vector<int>> G(N);
    rep(i, N) {
        rep(j, N) {
            if (A[i][j] == 1) G[i].push_back(j);
        }
    }

    rep(i, N) {
        sort(all(G[i]));
        for (auto a : G[i]) cout << a + 1 << " ";
        cout << endl;
    }
}
