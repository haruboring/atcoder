#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H1, W1;
    cin >> H1 >> W1;
    vector<vector<int>> A(H1, vector<int>(W1));
    rep(i, H1) rep(j, W1) cin >> A[i][j];
    int H2, W2;
    cin >> H2 >> W2;
    vector<vector<int>> B(H2, vector<int>(W2));
    rep(i, H2) rep(j, W2) cin >> B[i][j];

    rep(i, (1 << H1 + W1)) {
        bitset<30> s(i);
        set<int> sh, sw;
        rep(i, H1) if (s.test(i)) sh.insert(i);
        repp(i, H1, H1 + W1) if (s.test(i)) sw.insert(i - H1);
        if (sh.size() != H1 - H2 || sw.size() != W1 - W2) continue;
        bool ok = true;
        int hi = 0;
        rep(i, H1) {
            if (sh.count(i)) continue;
            int wi = 0;
            rep(j, W1) {
                if (sw.count(j)) continue;
                if (A[i][j] != B[hi][wi]) ok = false;
                wi++;
            }
            hi++;
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
