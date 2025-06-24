#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int W, H;
    cin >> W >> H;

    if (W % 4 == 0 && 3 * (W / 4) == H) {
        cout << "4:3" << endl;
        return 0;
    }
    cout << "16:9" << endl;
}
