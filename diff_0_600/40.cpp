#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    int cnt = 0;
    rep(i, n - 2) {
        vector<int> tmp(0);
        tmp.push_back(p[i]);
        tmp.push_back(p[i + 1]);
        tmp.push_back(p[i + 2]);
        sort(all(tmp));
        if (tmp[1] == p[i + 1]) {
            cnt++;
        }
    }

    cout << cnt << endl;
}