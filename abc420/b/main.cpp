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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<int> cnt(N);
    rep(i, M) {
        int z = 0;
        rep(j, N) if (S[j][i] == '0') z++;

        // debug(z);

        if (z == 0 || z == N) {
            rep(j, N) cnt[j]++;
        } else if (z > N - z) {
            rep(j, N) if (S[j][i] == '1') cnt[j]++;
        } else {
            rep(j, N) if (S[j][i] == '0') cnt[j]++;
        }
    }

    int m = -1;
    rep(i, N) m = max(m, cnt[i]);
    rep(i, N) if (cnt[i] == m) cout << i + 1 << " ";
    cout << endl;
}
