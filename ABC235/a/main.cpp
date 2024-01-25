#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    int a = S[0] - '0', b = S[1] - '0', c = S[2] - '0';
    int ans = 100 * a + 10 * b + c + 100 * b + 10 * c + a + 100 * c + 10 * a + b;
    cout << ans << endl;
}
