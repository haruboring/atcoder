#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string N;
    cin >> N;
    int ans = 0;
    rep(i, N.size()) {
        ans += int(N[N.size() - 1 - i] - '0') * pow(2, i);
    }
    cout << ans << endl;
}