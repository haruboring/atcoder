#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M);
    rep(i, M) cin >> A.at(i) >> B.at(i);

    rep(i, M) {
        A.at(i)--;
        B.at(i)--;
    }

    vector<vector<ll>> G(N);
    rep(i, M) {
        G.at(A.at(i)).push_back(B.at(i));
        G.at(B.at(i)).push_back(A.at(i));
    }

    int ans = 0;

    rep(i, N) {
        int tmp = 0;
        for (int nv : G.at(i)) {
            if (nv < i) tmp++;
        }
        if (tmp == 1) ans++;
    }

    cout << ans << endl;
}
