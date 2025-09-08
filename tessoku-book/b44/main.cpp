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
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];
    int Q;
    cin >> Q;

    map<int, int> m;
    rep(i, N) m[i] = i;
    rep(_, Q) {
        int f, x, y;
        cin >> f >> x >> y, x--, y--;
        if (f == 1) {
            swap(m[x], m[y]);
        } else {
            cout << A[m[x]][y] << endl;
        }
    }
}
