#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> C(N), P(N);
    vector<vector<int>> S(N);
    rep(i, N) {
        cin >> C[i] >> P[i];
        S[i].resize(P[i]);
        rep(j, P[i]) cin >> S[i][j];
    }

    vector<double> e(M + 1, 1e18);
    e[M] = 0;
    for (int i = M - 1; i >= 0; i--) {
        rep(j, N) {
            double a = 0;
            int cnt = 0;
            for (int k : S[j]) {
                if (k == 0) {
                    cnt++;
                    continue;
                }
                a += e[min(M, i + k)];
            }
            e[i] = min(e[i], a / (P[j] - cnt) + (double)C[j] * P[j] / (P[j] - cnt));
        }
    }

    cout << fixed << setprecision(10) << e[0] << endl;
}
