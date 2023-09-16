#include "atcoder/all"
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
    vector<int> T(M + 1), W(M), S(M);
    rep(i, M) {
        cin >> T[i] >> W[i] >> S[i];
    }
    T[M] = 1e18;

    vector<int> ans(N);
    set<int> st;
    rep(i, N) {
        st.insert(i);
    }
    vector<set<int>> hukkatu(M + 1);
    rep(i, M) {
        while (!hukkatu[i].empty()) {
            int eatable = *hukkatu[i].begin();
            hukkatu[i].erase(eatable);
            st.insert(eatable);
        }
        if (st.empty()) {
            continue;
        }
        int eatable = *st.begin();
        ans[eatable] += W[i];
        st.erase(eatable);

        int itr = lower_bound(all(T), T[i] + S[i]) - T.begin();
        if (eatable == 0) {
            cout << endl;
        }
        hukkatu[itr].insert(eatable);
    }

    rep(i, N) {
        cout << ans[i] << endl;
    }
}