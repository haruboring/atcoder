#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, L;
    cin >> N >> M >> L;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    vector<int> b(M);
    rep(i, M) cin >> b[i];
    vector<int> aa = a, bb = b;
    vector<int> c(L), d(L);
    rep(i, L) cin >> c[i] >> d[i];

    sort(all(a));
    sort(all(b));

    int left = 0, right = 1e18;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        int cnt = 0;
        rep(i, N) {
            cnt += M - (lower_bound(all(b), mid - a[i]) - b.begin());
        }
        if (cnt > L) {
            left = mid;
        } else {
            right = mid;
        }
    }

    set<pair<int, int>> st;
    rep(i, L) st.insert({aa[c[i] - 1], bb[d[i] - 1]});

    reverse(all(a));
    reverse(all(b));
    multiset<int> ans;
    debug(right);
    rep(i, N) {
        rep(j, M) {
            if (a[i] + b[j] < left) break;
            if (st.count({a[i], b[j]})) continue;
            ans.insert(a[i] + b[j]);
        }
    }

    cout << *ans.rbegin() << endl;
}
