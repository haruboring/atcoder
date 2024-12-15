#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N1, N2, N3, N4;
    cin >> N1 >> N2 >> N3 >> N4;

    vector<int> v = {N1, N2, N3, N4};
    sort(all(v));
    if (v[0] == 1 && v[1] == 4 && v[2] == 7 && v[3] == 9) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
