#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int sum = 0;
    set<int> s = {2, 4, 5, 6, 8};
    rep(i, n) {
        while (1) {
            if (s.count(a[i])) {
                a[i]--;
                sum++;
            } else {
                break;
            }
        }
    }
    cout << sum << endl;
}