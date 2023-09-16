#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int D, N;
    cin >> D >> N;
    vector<int> L(N), R(N), At(D + 2);
    rep(i, N) {
        cin >> L[i] >> R[i];
        At[L[i]]++;
        At[R[i] + 1]--;
    }
    int cnt = 0;
    rep(i, D) {
        cnt += At[i + 1];
        cout << cnt << endl;
    }
}