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

    int ans = 15;
    rep(i, 1 << N) {
        bitset<15> b(i);
        set<int> s;

        int cnt = 0;

        rep(j, N) {
            if (!b.test(j)) continue;
            cnt++;
            rep(k, M) {
                if (S[j][k] == 'o') {
                    s.insert(k);
                }
            }
        }

        if (s.size() == M) ans = min(ans, cnt);
    }

    cout << ans << endl;
}
