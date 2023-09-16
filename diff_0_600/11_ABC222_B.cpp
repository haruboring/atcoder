#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, P;
    cin >> N >> P;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    int failing_cnt = 0;
    rep(i, N) {
        if (a[i] < P) {
            failing_cnt++;
        }
    }
    cout << failing_cnt << endl;
}