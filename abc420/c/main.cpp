#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    int sum = 0;
    rep(i, N) sum += min(A[i], B[i]);

    rep(_, Q) {
        char c;
        int x, v;
        cin >> c >> x >> v;

        int o = min(A[x - 1], B[x - 1]);
        if (c == 'A') {
            A[x - 1] = v;
        } else {
            B[x - 1] = v;
        }
        int a = min(A[x - 1], B[x - 1]);
        sum = sum - o + a;
        cout << sum << endl;
    }
}
