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
    string S;
    cin >> S;

    vector<int> idxes = {};
    rep(i, N) idxes.push_back(i);
    sort(all(idxes));

    set<string> st;

    int ans = 0;
    do {
        string T = "";
        rep(i, N) T += S[idxes[i]];

        if (st.count(T)) continue;
        st.insert(T);

        bool ok = true;
        rep(i, N - K + 1) {
            bool ok_ = true;
            rep(j, K) {
                if (T[i + j] != T[i + K - 1 - j]) ok_ = false;
            }
            if (ok_) ok = false;
        }
        if (ok) ans++;
    } while (next_permutation(all(idxes)));

    cout << ans << endl;
}
