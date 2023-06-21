#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> p(A), q(B), r(C);
    rep(i, A) cin >> p[i];
    rep(i, B) cin >> q[i];
    rep(i, C) cin >> r[i];

    sort(all(p), greater<ll>());
    sort(all(q), greater<ll>());

    priority_queue<ll, vector<ll>, greater<ll>> pp;
    rep(i, X) pp.push(p[i]);
    priority_queue<ll, vector<ll>, greater<ll>> qq;
    rep(i, Y) qq.push(q[i]);
    priority_queue<ll> rr;
    rep(i, C) rr.push(r[i]);

    rep(_, C) {
        ll p_min = pp.top();
        ll q_min = qq.top();
        ll r_max = rr.top();
        if (p_min >= q_min && r_max > q_min) {
            qq.pop();
            qq.push(r_max);
            rr.pop();
        } else if (p_min < q_min && r_max > p_min) {
            pp.pop();
            pp.push(r_max);
            rr.pop();
        }
    }

    ll ans = 0;
    rep(i, X) {
        ans += pp.top();
        pp.pop();
    }
    rep(i, Y) {
        ans += qq.top();
        qq.pop();
    }

    cout << ans << endl;
}
