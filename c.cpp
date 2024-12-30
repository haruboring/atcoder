// #include "atcoder/all"
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
    vector<int> H(N);
    rep(i, N) cin >> H[i];

    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    int ans = 0;
    unordered_set<int> s;
    rep(i, N) s.insert(10000 * H[i] + i);

    repp(d, 1, N) {
        rep(st, N) {
            int cnt = 0;
            int j = st;
            int h = H[st];
            while (j < N) {
                if (s.count(10000 * h + j)) {
                    cnt++;
                    j += d;
                } else {
                    break;
                }
            }
            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;
}