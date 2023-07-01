#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    string S;
    cin >> S;

    vector<ll> M(0), E(0), X(0);
    ll ans = 0;
    map<ll, ll> m;
    m[0] = 0;
    m[1] = 0;
    m[2] = 0;
    map<set<ll>, ll> e;
    vector<set<ll>> tmp = {{0}, {1}, {2}, {0, 1}, {0, 2}, {1, 2}};
    rep(i, 6) e[tmp[i]] = 0;

    rep(i, N) {
        if (S[i] == 'M') {
            m[A[i]]++;
        } else if (S[i] == 'E') {
            rep(j, 3) {
                set<ll> s;
                s.insert(A[i]);
                s.insert(j);
                e[s] += m[j];
            }
        } else {
            rep(j, 6) {
                set<ll> s = tmp[j];
                rep(k, 4) {
                    if (k == A[i]) continue;
                    if (s.count(k) == 0) {
                        ans += k * e[s];
                        break;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}