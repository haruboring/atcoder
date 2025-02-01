#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string D;
    cin >> D;

    if (D == "N") {
        cout << "S" << endl;
    } else if (D == "S") {
        cout << "N" << endl;
    } else if (D == "W") {
        cout << "E" << endl;
    } else if (D == "E") {
        cout << "W" << endl;
    } else if (D == "NE") {
        cout << "SW" << endl;
    } else if (D == "NW") {
        cout << "SE" << endl;
    } else if (D == "SE") {
        cout << "NW" << endl;
    } else if (D == "SW") {
        cout << "NE" << endl;
    }
}
