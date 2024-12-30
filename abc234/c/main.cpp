#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int K;
    cin >> K;

    bitset<64> bs(K);
    vector<int> ans(64);
    rep(i, 64) {
        if (bs[i]) {
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }
    }
    reverse(all(ans));
    bool s = false;
    rep(i, 64) {
        if (ans[i] == 1) s = true;
        if (s) cout << 2 * ans[i];
    }
    cout << endl;
}
