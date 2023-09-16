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
    vector<int> p(N);
    rep(i, N) cin >> p[i];

    vector<int> cp = p;
    sort(all(cp));

    int cnt = 0;
    rep(i, N) {
        if (p[i] != cp[i]) cnt++;
    }

    if (cnt == 2 || cnt == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}