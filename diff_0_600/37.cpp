#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int r, g, b;
    cin >> r >> g >> b;
    int num = 100 * r + 10 * g + b;

    cout << (num % 4 == 0 ? "YES" : "NO") << endl;
}