#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<pair<ll, ll>> query(0);
    ll t, x;
    rep(i, Q) {
        cin >> t >> x;
        query.push_back(make_pair(t, x));
    }
    ll swipe = 0;
    rep(i, Q) {
        if (query[i].first == 1) {
            swipe += query[i].second;
            swipe %= N;
        } else {
            cout << S[(query[i].second - swipe - 1 + 3 * N) % N] << endl;
        }
    }
}