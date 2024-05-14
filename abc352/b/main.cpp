#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int ans = 0;
    queue<int> q;
    rep(i, N) q.push(A[i]);
    int cap = K;

    while (!q.empty()) {
        int a = q.front();
        if (a <= cap) {
            cap -= a;
            q.pop();
        } else {
            ans++;
            cap = K;
        }
    }

    cout << ans << endl;
}
