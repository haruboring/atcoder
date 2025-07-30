#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    int A, B, C, D;
    A = S[0] - '0';
    B = S[1] - '0';
    C = S[2] - '0';
    D = S[3] - '0';

    map<int, char> m;
    m[-1] = '-', m[1] = '+';

    for (auto op1 : {-1, 1}) {
        for (auto op2 : {-1, 1}) {
            for (auto op3 : {-1, 1}) {
                if (A + op1 * B + op2 * C + op3 * D == 7) {
                    cout << A << m[op1] << B << m[op2] << C << m[op3] << D << "=7" << endl;
                    return 0;
                }
            }
        }
    }
}
