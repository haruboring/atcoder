#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int Q;
    cin >> Q;

    int MOD = 998244353;
    deque<int> deq;
    deq.push_back(1);

    vector<vector<int>> sa(10, vector<int>(6e5 + 100, 0));
    for (int i = 1; i < 10; i++) {
        sa[i][2] = i * 10;
        for (int j = 3; j < 6e5 + 100; j++) {
            sa[i][j] = (sa[i][j - 1] * 10) % MOD;
        }
    }

    int tmp = 1;

    rep(_, Q) {
        int query;
        cin >> query;

        if (query == 1) {
            int c;
            cin >> c;
            deq.push_back(c);

            tmp = 10 * tmp + c;
            tmp %= MOD;
        } else if (query == 2) {
            int c = deq.front();
            tmp += MOD - sa[c][deq.size()];
            tmp %= MOD;
            deq.pop_front();
        } else {
            cout << tmp << endl;
        }
    }
}