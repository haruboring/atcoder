#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    multiset<double> st;
    rep(i, N) st.insert(A[i]);

    rep(i, M) {
        double ma = *rbegin(st);
        st.erase(st.find(ma));

        st.insert(ma / 2);
    }

    int ans = 0;
    for (auto x : st) ans += x;
    cout << ans << endl;
}