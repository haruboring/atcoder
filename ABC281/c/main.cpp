#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    int sum = 0;
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    T %= sum;
    int ans = 0;
    rep(i, N) {
        if (ans + A[i] >= T) {
            cout << i + 1 << " " << T - ans << endl;
            return 0;
        }
        ans += A[i];
    }
}