#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int M, D;
    cin >> M >> D;
    int y, m, d;
    cin >> y >> m >> d;

    cout << y + ((m + d / D - 1) / M) << " " << (m + d / D - 1) % M + 1 << " " << d % D + 1 << endl;
}
