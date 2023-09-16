#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> pos(0), neg(0);
    rep(i, N) {
        ll x;
        cin >> x;
        if (x > 0)
            pos.push_back(x);
        else
            neg.push_back(-x);
    }

    sort(all(pos));
    sort(all(neg));

    ll ans = 1'000'000'000'000'000;
    if ((ll)neg.size() >= K) ans = neg[K - 1];
    if ((ll)pos.size() >= K) ans = min(ans, pos[K - 1]);

    rep(i, K) {
        if (pos.size() <= i || neg.size() <= K - i - 2) continue;
        // 正側を移動する時間
        ll cost = 2 * pos[i];
        // 負側を移動する時間
        cost += neg[K - 2 - i];
        ans = min(ans, cost);
    }
    rep(i, K) {
        if (neg.size() <= i || pos.size() <= K - i - 2) continue;
        // 正側を移動する時間
        ll cost = 2 * neg[i];
        // 負側を移動する時間
        cost += pos[K - 2 - i];
        ans = min(ans, cost);
    }
    cout << ans << endl;
}