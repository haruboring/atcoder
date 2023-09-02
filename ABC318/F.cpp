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
    vector<int> X(N);
    rep(i, N) cin >> X[i];
    vector<int> L(N);
    rep(i, N) cin>>L[i];

    int l = 0, r = 1e18 + 100;
    int _ = 0;
    while (_ < 1000) {
        int m = (l + r) / 2;
        int cnt = 0;
        vector<int> tmp(N);
        rep(i, N) {
            tmp[i] = abs(m - X[i]);
        }
        sort(all(tmp));
        
        if (cnt % 2 == 0)
            l = m;
        else
            r = m;
    }
}