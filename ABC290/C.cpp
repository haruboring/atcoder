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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    sort(all(A));
    set<int> st;
    rep(i, N) {
        st.insert(A[i]);
        if ((int)st.size() == K) break;
    }
    rep(i, K + 10) {
        if (!st.count(i)) {
            cout << i << endl;
            return 0;
        }
    }
}