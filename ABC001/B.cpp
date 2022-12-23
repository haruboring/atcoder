#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int m;
    cin >> m;
    int vv = 0;
    if (m < 100) {
        vv = 0;
    } else if (m <= 5000) {
        vv = m / 100;
    } else if (6000 <= m && m <= 30000) {
        vv = m / 1000 + 50;
    } else if (35000 <= m && m <= 70000) {
        vv = (m / 1000 - 30) / 5 + 80;
    } else if (70000 < m) {
        vv = 89;
    }
    cout << setw(2) << setfill('0') << vv << endl;
}