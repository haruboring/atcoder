#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int L, R, d;
    cin >> L >> R >> d;

    int cnt = 0;
    for (int i = 0; i <= R; i += d) {
        if (i >= L) cnt++;
    }

    cout << cnt << endl;
}
