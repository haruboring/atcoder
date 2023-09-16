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
    ll cnt = 0;
    ll size = S.size();
    rep(i, size) {
        cnt += (ll)(pow(26, i)) * (ll)(S[size - 1 - i] - 'A' + 1);
    }
    cout << cnt << endl;
}