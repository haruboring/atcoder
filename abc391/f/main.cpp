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
    vector<int> A(N), B(N), C(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];

    sort(all(A));
    sort(all(B));
    sort(all(C));
    reverse(all(A));
    reverse(all(B));
    reverse(all(C));

    priority_queue<tuple<int, int, int, int>> pq;
    pq.push({A[0] * B[0] + B[0] * C[0] + C[0] * A[0], 0, 0, 0});

    int cnt = 0;
    set<tuple<int, int, int>> s;
    while (1) {
        auto [sum, a, b, c] = pq.top();
        if (s.count({a, b, c})) {
            pq.pop();
            continue;
        }
        // cout << a << " " << b << " " << c << endl;
        // debug(sum);
        pq.pop();
        s.insert({a, b, c});
        cnt++;
        if (cnt == K) {
            cout << sum << endl;
            return 0;
        }

        if (a + 1 < N) {
            pq.push({A[a + 1] * B[b] + B[b] * C[c] + C[c] * A[a + 1], a + 1, b, c});
        }
        if (b + 1 < N) {
            pq.push({A[a] * B[b + 1] + B[b + 1] * C[c] + C[c] * A[a], a, b + 1, c});
        }
        if (c + 1 < N) {
            pq.push({A[a] * B[b] + B[b] * C[c + 1] + C[c + 1] * A[a], a, b, c + 1});
        }
    }
}
