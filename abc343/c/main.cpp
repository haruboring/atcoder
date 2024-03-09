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

    vector<int> a3(0);

    repp(i, 1, 1000000 + 1) {
        a3.push_back(i * i * i);
    }
    vector<int> kai(0);
    rep(i, a3.size()) {
        string s = to_string(a3[i]);
        string rs = s;
        reverse(all(rs));
        if (s == rs) {
            kai.push_back(a3[i]);
        }
    }

    auto itr = upper_bound(all(kai), N) - kai.begin();
    cout << kai[itr-1] << endl;
}
