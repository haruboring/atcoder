#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<int> ABC(3);
    rep(i, 3) cin >> ABC[i];

    sort(all(ABC));
    if (ABC[0] == 5 && ABC[1] == 5 && ABC[2] == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}