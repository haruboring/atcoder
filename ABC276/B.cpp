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
    vector<vector<int>> A(N + 1, vector<int>(0));
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    rep(i, N) {
        sort(all(A[i + 1]));
        cout << A[i + 1].size() << " ";
        rep(j, A[i + 1].size()) {
            cout << A[i + 1][j] << " ";
        }
        cout << endl;
    }
}