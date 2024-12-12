#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> T(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> T[i][j];

    vector<int> order;
    repp(i, 1, N) order.push_back(i);

    int cnt = 0;
    do {
        int time = 0;
        int from = 0;
        for (int to : order) {
            time += T[from][to];
            from = to;
        }
        time += T[from][0];
        if (time == K) cnt++;
    } while (next_permutation(all(order)));

    cout << cnt << endl;
}
