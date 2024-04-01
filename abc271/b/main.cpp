#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> aa(0, vector<int>(0));
    rep(i, N) {
        int L;
        cin >> L;
        vector<int> a(L);
        rep(j, L) {
            cin >> a[j];
        }
        aa.push_back(a);
    }
    rep(i, Q) {
        int s, t;
        cin >> s >> t;
        cout << aa[s - 1][t - 1] << endl;
    }
}