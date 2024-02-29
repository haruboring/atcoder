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
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    set<int> s(all(a));
    map<int, int> m;
    int cnt = 0;
    for (auto x : s) {
        m[x] = cnt;
        cnt++;
    }

    rep(i, N) {
        cout << m[a[i]] << endl;
    }
}
