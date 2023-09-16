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
    vector<vector<int>> P(1500 + 2, vector<int>(1500 + 2));
    rep(i, N) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        P[A][B]++;
        P[A][D]--;
        P[C][B]--;
        P[C][D]++;
    }
    rep(i, 1500 + 2) {
        int sum = 0;
        rep(j, 1500 + 2) {
            sum += P[i][j];
            P[i][j] = sum;
        }
    }
    rep(i, 1500 + 2) {
        int sum = 0;
        rep(j, 1500 + 2) {
            sum += P[j][i];
            P[j][i] = sum;
        }
    }
    int cnt = 0;
    rep(i, 1500 + 2) {
        rep(j, 1500 + 2) {
            if (P[i][j] >= 1) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}