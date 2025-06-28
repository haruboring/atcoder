#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S, T;
    cin >> S >> T;

    set<char> s;
    rep(i, S.size() - 1) {
        if ('A' <= S[i + 1] && S[i + 1] <= 'Z') {
            s.insert(S[i]);
        }
    }

    rep(i, T.size()) {
        if (s.count(T[i])) s.erase(T[i]);
    }

    if (s.size() == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
