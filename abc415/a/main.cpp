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
    cin >> N;
    set<int> s;
    rep(i, N) {
        int a;
        cin >> a;
        s.insert(a);
    }

    int x;
    cin >> x;

    if (s.count(x)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
