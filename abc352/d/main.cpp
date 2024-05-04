#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    rep(i, N) cin >> P[i];

    rep(i, N) P[i]--;

    if (K == 1) {
        cout << 0 << endl;
        return 0;
    }

    map<int, int> mp;
    rep(i, N) mp[P[i]] = i;

    set<int> st;
    rep(i, N) {
        if (P[i] < K) st.insert(i);
    }
    int l = *st.begin(), r = *st.rbegin();
    int ans = r - l;
    debug(ans);
    rep(i, N - K) {
        st.erase(mp[i]);
        st.insert(mp[i + K]);
        l = *st.begin(), r = *st.rbegin();
        ans = min(ans, r - l);
    }

    cout << ans << endl;
}
