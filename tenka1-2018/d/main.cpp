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

    if (N == 1) {
        cout << "Yes 2 1 1 1 1" << endl;
        return 0;
    }

    int k = -1;
    repp(i, 3, 10000) {
        if (i * (i - 1) / 2 == N) k = i;
    }
    if (k == -1) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    cout << k << endl;

    map<int, vector<int>> m;
    int l = 0;
    cout << k - 1 << " ";
    rep(i, k - 1) {
        cout << i + 1 << " ";
        m[i].push_back(i + 1);
        l = i + 1;
    }
    cout << endl;
    rep(i, k - 1) {
        cout << k - 1 << " ";

        vector<int> n = m[i];
        rep(j, n.size()) {
            cout << n[j] << " ";
            m[j].push_back(m[i][j]);
        }
        rep(j, k - 1 - n.size()) {
            cout << l + 1 << " ";
            m[n.size() + j].push_back(l + 1);
            l++;
        }
        cout << endl;
    }
}
