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
    vector<ll> A(N), B(N);
    rep(i, N - 1) {
        cin >> A[i + 1];
    }
    rep(i, N - 1) {
        cin >> B[i + 1];
    }
    vector<ll> ans(N + 1);
    repp(i, 1, N) {
        if(ans[i]!=0 || i == 1){
            ans[A[i]] = max(ans[i] + 100, ans[A[i]]);
        }
        if(ans[i]!=0 || i == 1){
            ans[B[i]] = max(ans[i] + 150, ans[B[i]]);
        }
    }
    cout << ans[N] << endl;
}