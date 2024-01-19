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
    rep(i, N) {
        cin >> A[i];
    }
    rep(ans, 2020) {
        bool a = true;
        rep(i, N) {
            if (ans == A[i]) {
                a = false;
                break;
            }
        }
        if (a) {
            cout << ans << endl;
            break;
        }
    }
}