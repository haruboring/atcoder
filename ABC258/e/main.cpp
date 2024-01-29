#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q, X;
    cin >> N >> Q >> X;
    vector<int> W(N);
    rep(i, N) cin >> W[i];
    vector<int> K(Q);
    rep(i, Q) cin >> K[i];

    int sum = accumulate(all(W), 0LL);

    vector<int> wa(2 * N);
    int tmp_sum = 0;
    rep(i, 2 * N) {
        tmp_sum += W[i % N];
        wa[i] = tmp_sum;
    }

    vector<int> cnt(N);
    rep(i, N) {
        cnt[i] = N * (X / sum);

        int tmp_sum = sum * (X / sum);
        int tmp_cnt = -1;

        if (i != 0) tmp_cnt = lower_bound(all(wa), wa[i - 1] + X - tmp_sum) - wa.begin() - i;
        if (i == 0) tmp_cnt = lower_bound(all(wa), X - tmp_sum) - wa.begin();
        cnt[i] += (tmp_cnt + 1);
    }

    map<int, int> mp, mp_order;
    int loop_cnt = 0, loop_idx = 0;
    int idx = 0;
    vector<int> order(0);
    rep(i, 1000000) {
        if (mp.count(idx)) {
            loop_cnt = i;
            loop_idx = idx;
            break;
        }
        mp[idx] = (idx + cnt[idx]) % N;
        mp_order[idx] = i;
        order.push_back(idx);
        idx = (idx + cnt[idx]) % N;
    }

    int looped_cnt = loop_cnt - mp_order[loop_idx];
    rep(i, Q) {
        if (K[i] < order.size()) {
            cout << cnt[order[K[i] - 1]] << endl;
        } else {
            int tmp = (K[i] - 1 - mp_order[loop_idx]) % looped_cnt;
            cout << cnt[order[mp_order[loop_idx] + tmp]] << endl;
        }
    }
}
