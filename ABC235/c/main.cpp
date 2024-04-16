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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    map<pair<int, int>, int> mp;
    map<int, int> cnt;
    rep(i, N) {
        cnt[A[i]]++;
        mp[{A[i], cnt[A[i]]}] = i;
    }

    rep(_, Q) {
        int x, k;
        cin >> x >> k;
        if (mp.count({x, k}) == 0) {
            cout << -1 << endl;
        } else {
            cout << mp[{x, k}] + 1 << endl;
        }
    }
}
