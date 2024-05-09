#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> T(N), X(N);
    rep(i, N) cin >> T[i] >> X[i];

    vector<int> free, lock, locker;
    rep(i, N) {
        if (T[i] == 0) {
            free.push_back(X[i]);
        } else if (T[i] == 1) {
            lock.push_back(X[i]);
        } else {
            locker.push_back(X[i]);
        }
    }
    sort(all(free));
    reverse(all(free));
    vector<int> free_sum(M + 1);
    rep(i, min(M, (int)free.size())) {
        free_sum[i + 1] = free_sum[i] + free[i];
    }
    repp(i, min(M, (int)free.size()), M) {
        free_sum[i + 1] = free_sum[i];
    }

    sort(all(lock));
    reverse(all(lock));
    sort(all(locker));
    reverse(all(locker));
    int locker_idx = 0;
    int locker_cnt = 0;
    int lock_idx = 0;
    vector<int> lock_sum(M + 1);

    debug(lock.size());
    rep(i, M) {
        debug(i);
        if (locker_cnt == 0) {
            if (locker_idx >= locker.size()) {
                lock_sum[i + 1] = lock_sum[i];
                continue;
            }
            locker_cnt += locker[locker_idx];
            locker_idx++;
            lock_sum[i + 1] = lock_sum[i];
        } else {
            locker_cnt--;
            if (lock_idx < lock.size()) {
                lock_sum[i + 1] = lock_sum[i] + lock[lock_idx];
                lock_idx++;
            } else {
                lock_sum[i + 1] = lock_sum[i];
            }
        }
    }

    int ans = -1;
    rep(i, M + 1) {
        ans = max(ans, free_sum[i] + lock_sum[M - i]);
    }

    cout << ans << endl;
}
