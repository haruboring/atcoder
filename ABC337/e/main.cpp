#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    cout << (1LL << 10) << endl;
    cout << (1LL >> 10) << endl;
    int N;
    cin >> N;

    int M = 0;
    int tmp = 1;
    debug(N);
    debug(tmp);
    while (tmp < N) {
        tmp *= 2;
        M++;
    }
    cout << M << endl;

    rep(i, M) {
        vector<int> drinks(0);
        rep(j, N) {
            if (j & (1LL << i)) drinks.push_back(j);
        }

        cout << drinks.size() << " ";
        for (auto drink : drinks) cout << drink + 1 << " ";
        cout << endl;
    }

    tmp = 1;
    int ans = 0;
    string S;
    cin >> S;
    rep(i, M) {
        if (S[i] == '1') {
            ans += tmp;
        }
        tmp *= 2;
    }

    cout << ans + 1 << endl;
}
