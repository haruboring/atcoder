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
    vector<int> A(N + 1);
    rep(i, N) cin >> A[i];

    vector<int> upp(N);
    int u = 1;
    A[N] = -1e9;
    rep(i, N) {
        if (A[i] <= A[i + 1]) {
            u++;
        } else {
            rep(j, u) upp[i - j] = j + 1;
            u = 1;
        }
    }

    vector<int> don(N);
    int d = 1;
    A[N] = 1e9;
    rep(i, N) {
        if (A[i] <= A[i + 1]) {
            d++;
        } else {
            rep(j, d) don[i - j] = j + 1;
            d = 1;
        }
    }

    int cnt = 0, i = 0;
    while (i < N) {
        if (upp[i] >= don[i]) {
            i += upp[i];
        } else {
            i += don[i];
        }
        cnt++;
    }

    cout << cnt << endl;
}
