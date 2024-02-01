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
    vector<int> L(N);
    rep(i, N) cin >> L[i];

    sort(all(L));
    int max_L = L[N - 1];
    int sum_L = accumulate(all(L), 0LL) - max_L;

    if (max_L < sum_L) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
