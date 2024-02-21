#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> UV(N, vector<int>(0));
    int U, V;
    rep(i, M) {
        cin >> U >> V;
        UV[U - 1].push_back(V - 1);
        UV[V - 1].push_back(U - 1);
    }
    int ans = 0;
    rep(i, N) {
        // 頂点→i
        rep(j, UV[i].size()) {
            // 頂点→UV[i][j]
            if (UV[i][j] == i) {
                continue;
            }
            rep(k, UV[UV[i][j]].size()) {
                // 頂点UV[UV[i][j]][k]
                if (UV[UV[i][j]][k] == UV[i][j]) {
                    continue;
                }
                rep(l, UV[UV[UV[i][j]][k]].size()) {
                    if (UV[UV[UV[i][j]][k]][l] == i) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans / 6 << endl;
}