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
    rep(i, N) cin >> A[i] >> B[i];

    int ans = -1;
    for (int a : {-1, 1}) {
        for (int b : {-1, 1}) {
            vector<int> T(N);
            rep(i, N) T[i] = a * A[i] + b * B[i];

            sort(all(T));
            reverse(all(T));

            int sum = 0;
            rep(i, N) sum += max(0LL, T[i]);
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}
