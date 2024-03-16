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

    string b = S.substr(0, 2), a = S.substr(2, 2);
    debug(a);
    int ib = stoi(b), ia = stoi(a);
    debug(ia);

    if ((ib > 12 && ia > 12) || (ib == 0 && ia == 0)) {
        cout << "NA" << endl;
        return 0;
    }
    if ((ib <= 12 && ia <= 12) && min(ia, ib) != 0) {
        cout << "AMBIGUOUS" << endl;
        return 0;
    }
    if (1 <= ib && ib <= 12) {
        cout << "MMYY" << endl;
        return 0;
    }
    if (1 <= ia && ia <= 12) {
        cout << "YYMM" << endl;
        return 0;
    }
    cout << "NA" << endl;
}
