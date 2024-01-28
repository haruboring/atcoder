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

    set<vector<int>> st;
    rep(_, N) {
        int L;
        cin >> L;

        vector<int> A(L);
        rep(i, L) cin >> A[i];

        st.insert(A);
    }

    cout << st.size() << endl;
}