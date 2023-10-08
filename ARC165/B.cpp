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
    vector<int> P(N);
    rep(i, N) cin >> P[i];

    vector<int> cP = P;

    map<int, int> cnt;
    int last = -1;
    cnt[0] = 1;
    rep(i, N - 1) {
        if (P[i] < P[i + 1]) {
            cnt[i + 1] = cnt[i] + 1;
            if (i + 1 < N - K) last = i + 1;
        } else {
            cnt[i + 1] = 1;
        }
    }

    rep(i, N) {
        if (cnt[i] >= K) {
            rep(j, N) cout << P[j] << " ";
            cout << endl;
            return 0;
        }
    }

    int x = N - K;
    while (cnt[x] != 1) {
        x--;
    }
    debug(x);
    sort(P.begin() + x, P.begin() + x + K);
    sort(cP.end() - K, cP.end());

    if (P < cP) {
        rep(i, N) cout << cP[i] << " ";
        cout << endl;
        return 0;
    } else {
        rep(i, N) cout << P[i] << " ";
        cout << endl;
        return 0;
    }
}
