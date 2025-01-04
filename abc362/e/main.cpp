#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint998244353;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    map<int, int> d2i;
    set<int> ds;
    rep(i, N - 1) repp(j, i + 1, N) ds.insert(A[j] - A[i]);
    int idx = 0;
    for (auto d : ds) {
        d2i[d] = idx;
        idx++;
    }

    // return 0;

    // DP[i][k][d]=末尾がA[i]で、長さがkで、公差がdの等差数列の個数
    vector<vector<vector<mint>>> dp(N, vector<vector<mint>>(N + 1, vector<mint>(ds.size(), 0)));
    rep(i, N) dp[i][1][0]++;
    rep(i, N - 1) repp(j, i + 1, N) dp[j][2][d2i[A[j] - A[i]]]++;

    rep(i, N) {
        rep(j, i) {
            int d = d2i[A[i] - A[j]];
            repp(k, 2, i + 1) {
                dp[i][k + 1][d] += dp[j][k][d];
            }
        }
    }

    repp(k, 1, N + 1) {
        mint ans = 0;
        rep(i, N) {
            rep(j, ds.size()) {
                ans += dp[i][k][j];
            }
        }
        cout << ans.val() << endl;
    }
}
