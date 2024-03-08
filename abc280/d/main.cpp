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
    int n = 1;
    int ans = 1;
    int cnt;
    while (1) {
        if (n * n > K) {
            break;
        }
        if (K == 1) {
            break;
        }
        n++;
        if (K % n == 0) {
            cnt = 0;
            while (K % n == 0) {
                K /= n;
                cnt++;
            }
            int memo = 0;
            while (cnt > 0) {
                memo += n;
                int cpy_memo = memo;
                while (cpy_memo % n == 0) {
                    cpy_memo /= n;
                    cnt--;
                }
            }
            ans = max(ans, memo);
        }
    }
    cout << max(ans, K) << endl;
}
