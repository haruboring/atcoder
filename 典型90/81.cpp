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
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<vector<int>> cnt(5000 + 10, vector<int>(5000 + 10));
    rep(i, N) cnt[A[i]][B[i]]++;

    vector<vector<int>> wa(5000 + 10, vector<int>(5000 + 10));

    rep(i, 5000 + 10) {
        rep(j, 5000 + 10) {
            wa[i][j] = cnt[i][j];
            if (j > 0) wa[i][j] += wa[i][j - 1];
        }
    }

    rep(i, 5000 + 10) {
        rep(j, 5000 + 10) {
            if (i > 0) wa[i][j] += wa[i - 1][j];
        }
    }

    int ans = 0;
    rep(i, 5000 + 10) {
        rep(j, 5000 + 10) {
            int x = i + K, y = j + K;
            if (x >= 5000 + 10 || y >= 5000 + 10) continue;
            int tmp = wa[x][y];
            if (i > 0) tmp -= wa[i - 1][y];
            if (j > 0) tmp -= wa[x][j - 1];
            if (i > 0 && j > 0) tmp += wa[i - 1][j - 1];
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
}