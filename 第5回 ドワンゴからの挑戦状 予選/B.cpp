// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    multiset<int> st;
    vector<int> sum(N + 1);
    rep(i, N) {
        sum[i + 1] = sum[i] + a[i];
    }

    rep(i, N - 1) {
        repp(j, i, N) {
            // debug(sum[j + 1] - sum[i]);
            st.insert(sum[j + 1] - sum[i]);
        }
    }

    int tmp = 1;
    rep(i, 62) tmp *= 2;
    int ans = 0;
    for (int i = 62; i >= 0; i--) {
        int cnt = 0;
        for (auto b : st) {
            bitset<63> bit(b);
            if (bit.test(i)) cnt++;
        }
        if (cnt >= K) {
            ans += tmp;
            multiset<int> tmp_st;
            for (auto b : st) {
                bitset<63> bit(b);
                if (bit.test(i)) {
                    tmp_st.insert(b);
                }
            }
            st = tmp_st;
        }
        tmp /= 2;
    }

    cout << ans << endl;
}