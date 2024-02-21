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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    set<int> st;
    int cnt = 0;
    rep(i, N) {
        if (A[i] >= 3200)
            cnt++;
        else
            st.insert(A[i] / 400);
    }

    int ans1 = max((int)st.size(), 1LL);
    int ans2 = (int)st.size() + cnt;

    cout << ans1 << " " << ans2 << endl;
}
