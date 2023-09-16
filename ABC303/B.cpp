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
    vector<vector<int>> A(M, vector<int>(N));
    rep(i, M) {
        rep(j, N) {
            cin >> A.at(i).at(j);
        }
    }

    set<pair<int, int>> st;
    rep(i, M) {
        rep(j, N - 1) {
            st.insert(make_pair(A[i][j], A[i][j + 1]));
        }
    }

    int cnt = 0;
    repp(i, 1, N + 1) {
        repp(j, 1, N + 1) {
            if (i == j) continue;
            if (st.count(make_pair(i, j)) != 0) {
                continue;
            }
            if (st.count(make_pair(j, i)) != 0) {
                continue;
            }
            cnt++;
        }
    }
    cout << cnt / 2 << endl;
}