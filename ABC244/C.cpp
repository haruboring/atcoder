#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    set<int> S;
    int N;
    while (1) {
        cin >> N;
        if (N == 0) {
            break;
        }
        S.insert(N);
        repp(i, 1, 2 * N + 2) {
            if (S.count(i) == 0) {
                S.insert(i);
                cout << flush;
                cout << i << endl;
                cout << flush;
                break;
            }
        }
    }
}