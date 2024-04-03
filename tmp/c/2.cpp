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

    int cnt = 0;
    for (int i = 1; i <= N; i += 2) {
        int tmp = 0;
        int ii = i;
        bool t = false;

        for (int j = 2; j <= ii; j++) {
            if (ii % j == 0) {
                t = true;
            }
            if (t) tmp++;
        }
        if (ii != 1) tmp++;

        if (tmp == 8) cnt++;
    }

    cout << cnt << endl;
}