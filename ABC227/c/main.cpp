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

    int ans = 0;
    repp(i, 1, 10000) {
        repp(j, i, 1000000) {
            if (N / (i * j) - j + 1 <= 0) break;
            ans += N / (i * j) - j + 1;
        }
    }

    cout << ans << endl;
}

/*
5745290566750
9374392590012
*/