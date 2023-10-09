#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int T;
    cin >> T;
    rep(_, T) {
        int N;
        cin >> N;
        string X, Y;
        cin >> X >> Y;

        bool ok = true;
        rep(i, N) {
            if (X[i] == 'C' && Y[i] != 'C') {
                X[i] = 'X';
            }
            if (Y[i] == 'C' && X[i] != 'C') {
                ok = false;
            }
        }
        if (!ok) {
            cout << "No" << endl;
            continue;
        }

        map<int, int> mp_xa, mp_ya;
        int cnt_c = 0;
        rep(i, N) {
            if (Y[i] == 'C') cnt_c++;
            if (X[i] == 'A') mp_xa[cnt_c]++;
            if (Y[i] == 'A') mp_ya[cnt_c]++;
        }

        cnt_c = 0;
        vector<int> sum_A_x(N + 1, 0), sum_A_y(N + 1, 0);
        rep(i, N) {
            if (Y[i] == 'C') cnt_c++;
            sum_A_x[i + 1] = sum_A_x[i];
            sum_A_y[i + 1] = sum_A_y[i];

            if (Y[i] == 'A') sum_A_y[i + 1]++;
            if (X[i] == 'A') sum_A_x[i + 1]++;

            if (X[i] == 'X' && mp_xa[cnt_c] < mp_ya[cnt_c]) {
                X[i] = 'A';
                sum_A_x[i + 1]++;
                mp_xa[cnt_c]++;
            }
        }
        if (!ok) {
            cout << "No" << endl;
            continue;
        }
        rep(i, cnt_c + 1) {
            if (mp_xa[i] != mp_ya[i]) {
                ok = false;
                break;
            }
        }
        rep(i, N) {
            if (sum_A_x[i + 1] < sum_A_y[i + 1]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "No" << endl;
            continue;
        }

        cout << "Yes" << endl;
    }
}