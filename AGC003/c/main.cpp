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

    vector<int> zA(0), oA(0);
    rep(i, N) {
        if (i % 2 == 0) {
            zA.push_back(A[i]);
        } else {
            oA.push_back(A[i]);
        }
    }
    sort(all(zA));
    sort(all(oA));

    int ans = 0;
    sort(all(A));
    set<int> even;
    rep(i, N) {
        if (i % 2 == 0) {
            even.insert(A[i]);
        }
    }
    rep(i, zA.size()) {
        if (!even.count(zA[i])) ans++;
    }
    cout << ans << endl;
}
