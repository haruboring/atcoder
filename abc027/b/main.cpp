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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int sum = 0;
    rep(i, N) sum += A[i];

    if (sum % N) {
        cout << -1 << endl;
        return 0;
    }

    int s = sum / N, cnt = 0, tmp = 0;
    rep(i, N) {
        tmp += A[i];
        tmp -= s;

        if (tmp == 0) continue;
        cnt++;
    }
    cout << cnt << endl;
}
