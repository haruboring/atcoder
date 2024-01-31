#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;

    if (M < 2 * N || 4 * N < M) {
        cout << "-1 -1 -1" << endl;
        return 0;
    }

    int legs = 3 * N;
    if (legs == M) {
        cout << 0 << " " << N << " " << 0 << endl;
        return 0;
    }
    if (legs < M) {
        int diff = M - legs;
        cout << 0 << " " << N - diff << " " << diff << endl;
        return 0;
    }
    int diff = legs - M;
    cout << diff << " " << N - diff << " " << 0 << endl;
    return 0;
}
