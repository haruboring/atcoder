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
    vector<char> T(N);
    vector<int> A(N);
    rep(i, N) {
        cin >> T[i] >> A[i];
    }
    int BASE = 10000;
    int ans = 0;
    rep(i, N) {
        if (T[i] == '+') {
            ans += A[i];
        } else if (T[i] == '-') {
            ans -= A[i];
        } else {
            ans *= A[i];
        }
        ans = (ans + BASE) % BASE;
        cout << ans << endl;
    }
}