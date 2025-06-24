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
    string S, T;
    cin >> S >> T;

    vector<int> Sz(0), Tz(0);
    rep(i, N) {
        if (S[i] == '0') Sz.push_back(i);
        if (T[i] == '0') Tz.push_back(i);
    }
    if (Sz.size() != Tz.size()) {
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0;
    rep(i, Sz.size()) if (Sz[i] != Tz[i]) cnt++;

    cout << cnt << endl;
}
