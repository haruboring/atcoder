#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;

    int X = 0, tmp = 1;
    rep(i, M + 1) {
        X += tmp;
        if (tmp > 1000000000 || X > 1000000000) {
            cout << "inf" << endl;
            return 0;
        }
        tmp *= N;
    }

    cout << X << endl;
}
