#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int X, Y, N;
    cin >> X >> Y >> N;
    int ans = Y * (N / 3) + X * (N % 3);
    ans = min(ans, X * N);
    cout << ans << endl;
}