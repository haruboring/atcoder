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

    for (int x = 100 + 10; x >= 0; x--) {
        int cnt = 0;
        rep(i, N) {
            if (A[i] >= x) cnt++;
            if (cnt >= x) {
                cout << x << endl;
                return 0;
            }
        }
    }
}
