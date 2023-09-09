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
    vector<int> L(N);
    rep(i, N) cin >> L[i];

    int l = 0, r = 1e18 + 100;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int cnt = 1;
        int tmp = 0;

        bool kai = false;
        rep(i, N) {
            tmp += L[i];
            if (tmp > m) {
                cnt = 1e18 + 100;
                break;
            }

            if (i != N - 1) {
                if (tmp + L[i + 1] + 1 > m) {
                    tmp = 0;
                    cnt++;
                    kai = true;
                }
                else{
                    tmp++;
                }
            }
        }
        if (cnt > M)
            l = m;
        else
            r = m;
    }

    cout << r << endl;
}