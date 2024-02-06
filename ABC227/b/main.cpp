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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    set<int> st;
    repp(a, 1, 1000) {
        repp(b, 1, 1000) {
            st.insert(4 * a * b + 3 * a + 3 * b);
        }
    }

    int ans = 0;
    rep(i, N) {
        if (!st.count(stoi(S[i]))) {
            ans++;
        }
    }

    cout << ans << endl;
}
