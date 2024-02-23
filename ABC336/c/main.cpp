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

    N--;

    vector<int> a;
    int t = 5;
    while (N > 0) {
        a.push_back(N % t);
        N -= N % t;
        N /= t;
    }

    int ans = 0;
    reverse(all(a));
    for (int i = 0; i < a.size(); i++) {
        debug(a[i]);
        ans = 10 * ans + 2 * a[i];
    }

    cout << ans << endl;
}
