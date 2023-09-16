#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K, P;
    cin >> N >> K >> P;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int a_cnt = N / 2;
    int b_cnt = N - a_cnt;

    vector<int> a(a_cnt), b(b_cnt);
    rep(i, a_cnt) a[i] = A[i];
    rep(i, b_cnt) b[i] = A[i + a_cnt];

    vector<vector<int>> a_sum(a_cnt + 1), b_sum(b_cnt + 1);

    for (int i = 0; i < (1 << a_cnt); i++) {
        bitset<20> s(i);
        int sum = 0;
        int cnt = 0;
        rep(j, a_cnt) {
            if (s[j]) {
                sum += a[j];
                cnt++;
            }
        }
        a_sum[cnt].push_back(sum);
    }

    for (int i = 0; i < (1 << b_cnt); i++) {
        bitset<20> s(i);
        int sum = 0;
        int cnt = 0;
        rep(j, b_cnt) {
            if (s[j]) {
                sum += b[j];
                cnt++;
            }
        }
        b_sum[cnt].push_back(sum);
    }

    rep(i, a_cnt + 1) sort(all(a_sum[i]));
    rep(i, b_cnt + 1) sort(all(b_sum[i]));

    int ans = 0;

    rep(i, a_cnt + 1) {
        int j = K - i;
        if (j < 0 || j > b_cnt) continue;
        for (int x : a_sum[i]) {
            int y = P - x;
            if (y < 0) continue;
            int cnt = upper_bound(all(b_sum[j]), y) - b_sum[j].begin();
            ans += cnt;
        }
    }

    cout << ans << endl;
}
