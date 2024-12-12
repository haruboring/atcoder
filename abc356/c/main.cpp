#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> C(M);
    vector<vector<int>> A(M, vector<int>(0));
    vector<char> R(M);
    rep(i, M) {
        cin >> C[i];
        rep(j, C[i]) {
            int a;
            cin >> a;
            A[i].push_back(a);
        }
        cin >> R[i];
    }

    int cnt = 0;

    rep(i, 1 << N) {
        bitset<17> b(i);
        // cout << b << endl;
        bool ok = true;
        rep(i, M) {
            int cnt = 0;
            rep(j, C[i]) {
                if (b.test(A[i][j] - 1)) {
                    cnt++;
                }
            }

            if (cnt >= K && R[i] == 'x') {
                ok = false;
            }
            if (cnt < K && R[i] == 'o') {
                ok = false;
            }
        }

        if (ok) cnt++;
    }

    cout << cnt << endl;
}
