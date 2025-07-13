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

    int han = -1, hasi = -1;
    rep(i, N - 1) {
        int dist = 0;
        cout << "? " << 1 << " " << 2 + i << endl;
        cin >> dist;

        if (dist > han) {
            han = dist;
            hasi = 2 + i;
        }
    }

    int zen = -1;
    rep(i, N) {
        if (hasi == i + 1) continue;
        int dist = 0;
        cout << "? " << hasi << " " << 1 + i << endl;
        cin >> dist;

        zen = max(zen, dist);
    }
    cout << "! " << zen << endl;
}
