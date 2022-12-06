#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll K;
    cin >> K;
    ll n = 1;
    ll ans = 1;
    ll cnt;
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
            ll memo = 0;
            while (cnt > 0) {
                memo += n;
                ll cpy_memo = memo;
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
