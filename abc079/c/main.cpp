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

    int A = S[0] - '0';
    int B = S[1] - '0';
    int C = S[2] - '0';
    int D = S[3] - '0';

    if (A + B + C + D == 7) {
        cout << A << "+" << B << "+" << C << "+" << D << "=7" << endl;
    } else if (A + B + C - D == 7) {
        cout << A << "+" << B << "+" << C << "-" << D << "=7" << endl;
    } else if (A + B - C + D == 7) {
        cout << A << "+" << B << "-" << C << "+" << D << "=7" << endl;
    } else if (A + B - C - D == 7) {
        cout << A << "+" << B << "-" << C << "-" << D << "=7" << endl;
    } else if (A - B + C + D == 7) {
        cout << A << "-" << B << "+" << C << "+" << D << "=7" << endl;
    } else if (A - B + C - D == 7) {
        cout << A << "-" << B << "+" << C << "-" << D << "=7" << endl;
    } else if (A - B - C + D == 7) {
        cout << A << "-" << B << "-" << C << "+" << D << "=7" << endl;
    } else if (A - B - C - D == 7) {
        cout << A << "-" << B << "-" << C << "-" << D << "=7" << endl;
    }
}
