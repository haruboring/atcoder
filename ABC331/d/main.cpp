#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<string> P(N);
    rep(i, N) cin >> P[i];
    vector<int> A(Q), B(Q), C(Q), D(Q);
    rep(i, Q) cin >> A[i] >> B[i] >> C[i] >> D[i];

    vector<vector<int>> sub_cnt(N, vector<int>(N));
    rep(i, N) rep(j, N) if (P[i][j] == 'B') sub_cnt[i][j]++;
    rep(i, N - 1) rep(j, N) sub_cnt[i + 1][j] += sub_cnt[i][j];
    rep(i, N) rep(j, N - 1) sub_cnt[i][j + 1] += sub_cnt[i][j];

    rep(i, Q) {
        int a = A[i], b = B[i], c = C[i], d = D[i];
        int ans = 0;

        ans += ((c / N) * (d / N)) * sub_cnt[N - 1][N - 1];
        ans += sub_cnt[c % N][N - 1] * (d / N);
        ans += sub_cnt[N - 1][d % N] * (c / N);
        ans += sub_cnt[c % N][d % N];

        if (b > 0) {
            ans -= ((c / N) * ((b - 1) / N)) * sub_cnt[N - 1][N - 1];
            ans -= sub_cnt[c % N][N - 1] * ((b - 1) / N);
            ans -= sub_cnt[N - 1][(b - 1) % N] * (c / N);
            ans -= sub_cnt[c % N][(b - 1) % N];
        }
        if (a > 0) {
            ans -= ((a - 1) / N) * (d / N) * sub_cnt[N - 1][N - 1];
            ans -= sub_cnt[(a - 1) % N][N - 1] * (d / N);
            ans -= sub_cnt[N - 1][d % N] * ((a - 1) / N);
            ans -= sub_cnt[(a - 1) % N][d % N];
        }
        if (a > 0 && b > 0) {
            ans += ((a - 1) / N) * ((b - 1) / N) * sub_cnt[N - 1][N - 1];
            ans += sub_cnt[(a - 1) % N][N - 1] * ((b - 1) / N);
            ans += sub_cnt[N - 1][(b - 1) % N] * ((a - 1) / N);
            ans += sub_cnt[(a - 1) % N][(b - 1) % N];
        }

        cout << ans << endl;
    }
}
