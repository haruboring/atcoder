#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int L, N1, N2;
    cin >> L >> N1 >> N2;
    vector<vector<int>> vl1(2, vector<int>(N1)), vl2(2, vector<int>(N2));
    rep(i, N1) cin >> vl1[0][i] >> vl1[1][i];
    rep(i, N2) cin >> vl2[0][i] >> vl2[1][i];

    rep(i, N1 - 1) vl1[1][i + 1] += vl1[1][i];
    rep(i, N2 - 1) vl2[1][i + 1] += vl2[1][i];

    int ans = 0;
    int idx1 = 0, idx2 = 0;

    int tl = 0;
    while (tl != L) {
        int v1 = vl1[0][idx1], v2 = vl2[0][idx2];
        int l1 = vl1[1][idx1], l2 = vl2[1][idx2];

        if (l1 <= l2) {
            if (v1 == v2) {
                ans += l1 - tl;
            }
            tl = l1;
            if (idx1 != N1 - 1) idx1++;
        } else {
            if (v1 == v2) {
                ans += l2 - tl;
            }
            tl = l2;
            if (idx2 != N2 - 1) idx2++;
        }
    }

    cout << ans << endl;
}