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
    vector<int> ans(2 * N + 1);
    rep(i, N) {
        if (i != 2 * N) {
            ans[2 * i + 1] = ans[A[i] - 1] + 1;
            ans[2 * i + 2] = ans[A[i] - 1] + 1;
        }
    }
    rep(i, 2*N+1){
        cout << ans[i] << endl;
    }
}