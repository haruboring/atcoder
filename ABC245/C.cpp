#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> AB(N, vector<int>(2));
    rep(i, N) cin >> AB[i][0];
    rep(i, N) cin >> AB[i][1];

    vector<vector<bool>> ok(N, vector<bool>(2, false));
    ok[0][0] = true;
    ok[0][1] = true;

    rep(i, N - 1) {
        rep(j, 2) {
            if (!ok[i][j]) continue;
            rep(k, 2) {
                if (abs(AB[i][j] - AB[i + 1][k]) <= K) ok[i + 1][k] = true;
            }
        }
    }

    if (ok[N - 1][0] || ok[N - 1][1])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}