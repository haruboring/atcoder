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
    string S;
    cin >> S;
    int T_cnt = 0;
    rep(i, N) {
        if (S[i] == 'T') {
            T_cnt++;
        }
    }
    if (T_cnt > N - T_cnt) {
        cout << "T" << endl;
    } else if (T_cnt < N - T_cnt) {
        cout << "A" << endl;
    } else {
        int a = 0, b = 0;
        rep(i, N) {
            if (S[i] == 'T') {
                a++;
            } else {
                b++;
            }
            if (a == T_cnt) {
                cout << "T" << endl;
                return 0;
            }
            if (b == T_cnt) {
                cout << "A" << endl;
                return 0;
            }
        }
    }
}