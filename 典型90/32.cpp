#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];
    int M;
    cin >> M;
    vector<int> X(M), Y(M);
    rep(i, M) cin >> X[i] >> Y[i];

    rep(i, M) {
        X[i]--;
        Y[i]--;
    }

    vector<int> order(N);
    rep(i, N) order[i] = i;

    int ans = 1e9;
    do {
        int tmp = 0;
        rep(i, N) {
            tmp += A[order[i]][i];
        }

        map<int, int> mp;
        rep(i, N) {
            mp[order[i]] = i;
        }

        rep(i, M) {
            if (mp[X[i]] == mp[Y[i]] + 1 || mp[X[i]] == mp[Y[i]] - 1) {
                tmp = 1e9;
            }
        }

        ans = min(ans, tmp);
    } while (next_permutation(all(order)));

    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}