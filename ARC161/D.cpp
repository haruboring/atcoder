#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, D;
    cin >> N >> D;

    // そもそも、グラフが存在しない
    if (N - 1 < 2 * D) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    rep(i, N) {
        rep(j, D) {
            cout << i + 1 << " " << (i + j + 1) % N + 1 << endl;
        }
    }
}
