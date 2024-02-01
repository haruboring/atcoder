#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, L;
    cin >> N >> L;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int sum = accumulate(all(A), 0LL);

    priority_queue<int, vector<int>, greater<int>> pq;

    rep(i, N) pq.push(A[i]);
    if (L - sum > 0) pq.push(L - sum);

    int ans = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    cout << ans << endl;
}
