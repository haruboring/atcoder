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

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    bitset<35> bs(abs(N));
    debug(bs);
    vector<int> ans(40);
    if (N > 0) {
        rep(i, 35) {
            if (bs[i]) {
                if (i % 2 == 0) {
                    ans[i]++;
                } else {
                    ans[i]++;
                    ans[i + 1]++;
                }
            }
        }
    } else {
        rep(i, 35) {
            if (bs[i]) {
                if (i % 2 == 0) {
                    ans[i]++;
                    ans[i + 1]++;
                } else {
                    ans[i]++;
                }
            }
        }
    }

    int last = 0;
    rep(i, 35) {
        ans[i + 1] += ans[i] / 2;
        ans[i + 2] += ans[i] / 2;
        ans[i] %= 2;
        if (ans[i] == 1) last = i;
    }

    for (int i = last; i >= 0; i--) cout << ans[i];
    cout << endl;
}
