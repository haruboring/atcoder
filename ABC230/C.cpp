#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll N, A, B, P, Q, R, S;
    cin >> N >> A >> B >> P >> Q >> R >> S;
    for (ll i = P; i < Q + 1; i++) {
        for (ll j = R; j < S + 1; j++) {
            ll dis_x = i - A;
            ll dis_y = j - B;
            if (abs(dis_x) == abs(dis_y)) {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
}