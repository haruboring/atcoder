#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll N;
    cin >> N;

    int cnt = 0;

    repp(i, 1, sqrt(N) + 1) {
        if (N % i == 0) {
            ll a = i;
            ll b = N / i;
            if (b % 2 == 1) cnt++;
            if (a != b && a % 2 == 1) cnt++;
        }
    }

    cout << 2 * cnt << endl;
}