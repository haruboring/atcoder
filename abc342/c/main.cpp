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
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<char> c(Q), d(Q);
    rep(i, Q) cin >> c[i] >> d[i];

    map<char, char> mp;
    rep(i, 26) {
        mp['a' + i] = 'a' + (i) % 26;
    }
    rep(i, Q) {
        rep(j, 26) {
            if (mp['a' + j] == c[i]) {
                mp['a' + j] = d[i];
            }
        }
    }

    rep(i, S.size()) {
        cout << mp[S[i]];
    }
    cout << endl;
}
