#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S, T;
    cin >> S >> T;
    int sSize = S.size(), tSize = T.size();
    vector<vector<int>> st(sSize + 2, vector<int>(tSize + 2));
    repp(i, 1, sSize + 2) {
        repp(j, 1, tSize + 2) {
            st[i][j] = max(max(st[i][j], st[i][j - 1]), st[i - 1][j]);
            if (i + 1 < sSize + 2 && j + 1 < tSize + 2 && S[i - 1] == T[j - 1]) {
                st[i + 1][j + 1] = st[i][j] + 1;
            }
        }
    }
    cout << st[sSize + 1][tSize + 1] << endl;
}