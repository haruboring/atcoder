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
    string T;
    cin >> T;

    if (T == "1") {
        cout << 20000000000 << endl;
        return 0;
    }
    if (T == "0") {
        cout << 10000000000 << endl;
        return 0;
    }

    int s = 1e15;
    rep(i, 3) {
        int error_cnt = 0;
        rep(j, N) {
            if ((j + i) % 3 < 2) {
                if (T[j] != '1') error_cnt++;
            } else {
                if (T[j] != '0') error_cnt++;
            }
        }
        if (error_cnt == 0) {
            s = i;
            break;
        }
    }
    if (s == 1e15) {
        cout << 0 << endl;
        return 0;
    }

    cout << 10000000000 - (s + N - 1) / 3 << endl;
}
