#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, H;
    cin >> N >> H;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    int cnt = 0;
    int a_max = -1;
    rep(i, N) a_max = max(a_max, A[i]);
    sort(all(B));
    reverse(all(B));
    rep(i, N) {
        if (B[i] > a_max) {
            H -= B[i];
            cnt++;
            if (H <= 0) {
                cout << cnt << endl;
                return 0;
            }
        }
    }
    cout << cnt + (H + a_max - 1) / a_max << endl;
}
