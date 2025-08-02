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
    int N;
    cin >> N;

    int nS = 0, t = 1;
    vector<int> add;
    rep(i, S.size()) {
        if (S[S.size() - 1 - i] == '1') nS += t;
        if (S[S.size() - 1 - i] == '?') add.push_back(t);
        t *= 2;
    }

    if (nS > N) {
        cout << -1 << endl;
        return 0;
    }

    sort(all(add));
    reverse(all(add));
    rep(i, add.size()) if (nS + add[i] <= N) nS += add[i];

    cout << nS << endl;
}
