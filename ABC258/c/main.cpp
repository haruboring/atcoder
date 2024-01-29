#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<pair<int, int>> query(0);
    int t, x;
    rep(i, Q) {
        cin >> t >> x;
        query.push_back(make_pair(t, x));
    }
    int swipe = 0;
    rep(i, Q) {
        if (query[i].first == 1) {
            swipe += query[i].second;
            swipe %= N;
        } else {
            cout << S[(query[i].second - swipe - 1 + 3 * N) % N] << endl;
        }
    }
}