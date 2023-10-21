#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    int ans = 0;
    set<pair<int, int>> st;
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;

            int dx = x[i] - x[j];
            int dy = y[i] - y[j];

            int dc = gcd(dx, dy);

            dx /= dc;
            dy /= dc;

            st.insert(make_pair(dx, dy));
        }
    }

    cout << st.size() << endl;
}