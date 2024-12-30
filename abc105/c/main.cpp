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

    vector<int> plus;
    map<int, bitset<20>> plus_mp;
    rep(i, 1 << 20) {
        bitset<20> b(i);
        int num = 0;
        int tmp = 1;
        rep(j, 20) {
            num += b[j] * tmp;
            tmp *= 4;
        }
        plus.push_back(num);
        plus_mp[num] = b;
    }

    set<int> minus;
    map<int, bitset<20>> minus_mp;
    rep(i, 1 << 20) {
        bitset<20> b(i);
        int num = 0;
        int tmp = 1;
        rep(j, 20) {
            num += 2 * b[j] * tmp;
            tmp *= 4;
        }
        minus.insert(num);
        minus_mp[num] = b;
    }

    rep(i, plus.size()) {
        if (minus.count(plus[i] - N) == 0) continue;
        debug(plus[i]);
        debug(plus[i] - N);
        bitset<20> p = plus_mp[plus[i]];
        bitset<20> m = minus_mp[plus[i] - N];
        vector<int> ans(45);
        int max_idx = 0;
        rep(i, 20) {
            if (p[i]) {
                ans[2 * i] = 1;
                max_idx = 2 * i;
            }
            if (m[i]) {
                ans[2 * i + 1] = 1;
                max_idx = 2 * i + 1;
            }
        }

        for (int i = max_idx; i >= 0; i--) cout << ans[i];
        cout << endl;
        return 0;
    }
}