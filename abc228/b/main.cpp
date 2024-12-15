#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    X--;
    rep(i, N) A[i]--;

    vector<bool> visited(N, false);

    int cnt = 0;
    while (1) {
        if (visited[X]) break;
        visited[X] = true;
        X = A[X];
        cnt++;
    }

    cout << cnt << endl;
}
