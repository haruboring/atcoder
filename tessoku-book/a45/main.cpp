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
    char C;
    cin >> N >> C;
    string A;
    cin >> A;

    int s = 0;
    map<char, int> m;
    m['W'] = 0, m['R'] = 2, m['B'] = 1;
    rep(i, N) s += m[A[i]];

    if (s % 3 == m[C]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
