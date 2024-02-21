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

    int l = 1e9, r = -1;
    rep(i, S.size()) {
        if (S[i] == 'A') {
            l = min(l, i);
        }
        if (S[i] == 'Z') {
            r = max(r, i);
        }
    }

    cout << r - l + 1 << endl;
}
