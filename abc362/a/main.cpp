#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int R, G, B;
    cin >> R >> G >> B;
    string C;
    cin >> C;

    if (C[0] == 'G') {
        cout << min(R, B) << endl;
    } else if (C[0] == 'B') {
        cout << min(G, R) << endl;
    } else {
        cout << min(G, B) << endl;
    }
}
