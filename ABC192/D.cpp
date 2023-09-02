#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int BASE = 1e18 + 10;

int powll(int a, int b) {
    int ans = 1;
    rep(i, b) {
        if (ans > BASE / a) return -1;
        ans *= a;
    }
    return ans;
}

signed main() {
    string X;
    cin >> X;
    int M;
    cin >> M;

    int m = -1;
    rep(i, X.size()) m = max(m, (int)(X[i] - '0'));

    int left = m, right = 1'000'000'000'000'000'000LL;
    debug(right);
    while (right - left > 1) {
        int mid = (left + right) / 2;
        debug(mid);
        int sum = 0;
        rep(i, X.size()) {
            if (sum > M) break;

            int p = powll(mid, X.size() - i - 1);
            if (p == -1) {
                debug(p);
                sum = 1'000'000'000'000'000'000LL + 100;
                break;
            }
            sum += (X[i] - '0') * p;
            if (sum < 0) {
                sum = 1'000'000'000'000'000'000LL + 100;
                break;
            }
        }
        if (sum <= M) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left - m << endl;
}

// 1'000'000'000'000'000'128