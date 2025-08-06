#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, L, R;
    cin >> N >> L >> R;

    bitset<64> b(N);
    vector<int> ke(64);
    int t = 1;
    rep(i, 64) {
        ke[i] = t;
        t *= 2;
    }
    int cnt = 0;
    rep(i, 64) {
        if (b.test(i) == 0) continue;
        debug(i);
        cnt += max(0LL, min(R, ke[i + 1] - 1) - max(L, ke[i]) + 1);
    }
    cout << cnt << endl;
}
