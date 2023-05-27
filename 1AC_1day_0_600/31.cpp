#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    vector<int> cookies(4);
    rep(i, 4) cin >> cookies[i];

    ll sum = 0;
    rep(i, 4) sum += cookies[i];

    repp(i, 1, (1 << 4)) {
        bitset<4> bs(i);
        ll tmp = 0;
        rep(j, 4) {
            if (bs[j]) tmp += cookies[j];
        }
        if (tmp == sum - tmp) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}