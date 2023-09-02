#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, P;
    cin >> N >> M >> P;

    int cnt = 0;
    repp(i, M, N + 1) {
        if ((i - M) % P == 0) cnt++;
    }

    cout << cnt << endl;
}