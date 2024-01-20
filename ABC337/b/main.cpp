#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    set<char> st;
    rep(i, S.size()) st.insert(S[i]);
    for (auto c : st) {
        if (c == 'A' || c == 'B' || c == 'C') continue;
        cout << "No" << endl;
        return 0;
    }

    rep(i, S.size() - 1) {
        if (S[i] <= S[i + 1]) continue;
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
}
