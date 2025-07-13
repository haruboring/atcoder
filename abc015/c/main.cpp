#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int N, K;
vector<vector<int>> T(10, vector<int>(10));
bool ok = true;

void dfs(int i, int x) {
    if (i == N) {
        if (x == 0) {
            ok = false;
        }
        return;
    }
    rep(j, K) {
        int nx = T[i][j];
        dfs(i + 1, (x ^ nx));
    }
}

signed main() {
    cin >> N >> K;
    rep(i, N) rep(j, K) cin >> T[i][j];

    dfs(0, 0);

    if (ok) {
        cout << "Nothing" << endl;
    } else {
        cout << "Found" << endl;
    }
}
