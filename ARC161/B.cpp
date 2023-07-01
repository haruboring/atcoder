#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll T;
    cin >> T;
    vector<ll> tmp(0);
    rep(i, 63 - 2) {
        repp(j, i + 1, 63 - 1) {
            repp(k, j + 1, 63) {
                tmp.push_back((1LL << i) + (1LL << j) + (1LL << k));
            }
        }
    }
    sort(all(tmp));
    rep(_, T) {
        ll N;
        cin >> N;
        int idx = upper_bound(all(tmp), N) - tmp.begin();
        if (idx == 0) {
            cout << -1 << endl;
        } else {
            cout << tmp[idx - 1] << endl;
        }
    }
}