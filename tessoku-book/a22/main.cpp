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
    vector<int> A(N), B(N);
    rep(i, N - 1) cin >> A[i + 1];
    rep(i, N - 1) cin >> B[i + 1];

    vector<int> s(N + 1, -1);
    s[1] = 0;
    for (int i = 1; i < N; i++) {
        if (s[i] == -1) continue;
        s[A[i]] = max(s[A[i]], s[i] + 100);
        s[B[i]] = max(s[B[i]], s[i] + 150);
    }
    cout << s[N] << endl;
}
