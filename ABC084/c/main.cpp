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
    vector<int> C(N - 1), S(N - 1), F(N - 1);
    rep(i, N - 1) cin >> C[i] >> S[i] >> F[i];

    for (int j = 0; j < N; j++) {
        if (j == N - 1) {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        for (int i = j; i < N - 1; i++) {
            if (ans < S[i]) {
                ans = S[i];
            } else {
                ans = (ans + F[i] - 1) / F[i] * F[i];
            }
            ans += C[i];
        }
        cout << ans << endl;
    }
}
