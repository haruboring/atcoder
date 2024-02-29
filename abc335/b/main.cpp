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
    vector<tuple<int, int, int>> a;
    rep(i, N + 1) {
        rep(j, N + 1) {
            rep(k, N + 1) {
                if (i + j + k <= N) {
                    a.push_back(make_tuple(i, j, k));
                }
            }
        }
    }
    sort(all(a));
    rep(i, a.size()) {
        int x, y, z;
        tie(x, y, z) = a[i];
        if (x + y + z <= N) {
            cout << x << " " << y << " " << z << endl;
        }
    }
}
