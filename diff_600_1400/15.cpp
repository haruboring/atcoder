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
    vector<vector<ll>> xyz(N, vector<ll>(3));
    rep(i, N) {
        rep(j, 3) {
            cin >> xyz[i][j];
        }
    }

    ll ans = -1e18;

    rep(i, (1 << 3)) {
        bitset<3> s(i);
        vector<ll> sum(N);
        rep(j, N) {
            rep(k, 3) {
                if (s.test(k)) {
                    sum[j] += xyz[j][k];
                } else {
                    sum[j] -= xyz[j][k];
                }
            }
        }
        sort(all(sum));
        ll tmp = 0;
        rep(j, M) tmp += sum[N - 1 - j];

        ans = max(ans, tmp);
    }

    cout << ans << endl;
}