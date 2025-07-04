#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H1, M1, H2, M2, K;
    cin >> H1 >> M1 >> H2 >> M2 >> K;

    int a = 60 * H2 + M2 - (60 * H1 + M1);
    // if (a < 0) a += 24 * 60;

    cout << a - K << endl;
}
