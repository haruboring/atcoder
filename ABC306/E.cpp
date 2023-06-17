#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, K, Q;
    cin >> N >> K >> Q;
    vector<ll> X(Q), Y(Q);
    rep(i, Q) cin >> X[i] >> Y[i];

    if (N == K) {
        ll ans = 0;
        vector<ll> a(N + 1, 0);
        rep(i, Q) {
            ans += Y[i] - a[X[i]];
            a[X[i]] = Y[i];
            cout << ans << endl;
        }
        return 0;
    }

    vector<ll> a(N + 1, 0);
    multiset<ll> s, es;
    rep(i, K) {
        s.insert(0);
    }
    rep(i, N - K) {
        es.insert(0);
    }
    ll now = 0;
    rep(i, Q) {
        ll sb = *s.begin();
        if (a[X[i]] >= sb) {
            if (Y[i] >= sb) {
                now += Y[i] - a[X[i]];
                s.insert(Y[i]);
                s.erase(s.find(a[X[i]]));
            } else {
                ll esrb = *es.rbegin();
                if (esrb > Y[i]) {
                    ll in = esrb;
                    ll out = a[X[i]];
                    now += in - out;
                    s.insert(in);
                    s.erase(s.find(out));
                    es.insert(Y[i]);
                    es.erase(es.find(in));
                } else {
                    ll in = Y[i];
                    ll out = a[X[i]];
                    now += in - out;
                    s.insert(in);
                    s.erase(s.find(out));
                }
            }
        } else {
            if (Y[i] >= sb) {
                ll in = Y[i];
                ll out = sb;
                now += in - out;
                s.insert(in);
                s.erase(s.find(out));
                es.insert(out);
                es.erase(es.find(a[X[i]]));
            } else {
                es.insert(Y[i]);
                es.erase(es.find(a[X[i]]));
            }
        }

        a[X[i]] = Y[i];

        cout << now << endl;
    }
}