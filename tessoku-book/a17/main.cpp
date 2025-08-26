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
    vector<int> A(N - 1), B(N - 2);
    rep(i, N - 1) cin >> A[i];
    rep(i, N - 2) cin >> B[i];

    vector<int> dist(N, 1e18);
    dist[0] = 0;
    rep(i, N - 1) {
        dist[i + 1] = min(dist[i + 1], dist[i] + A[i]);
        if (i < N - 2) dist[i + 2] = min(dist[i + 2], dist[i] + B[i]);
    }

    vector<int> path;
    path.push_back(N - 1);
    int i = 0;
    while (1) {
        if (A[N - 2 - i] == dist[N - 1 - i] - dist[N - 2 - i]) {
            path.push_back(N - 2 - i);
            i++;
        } else {
            path.push_back(N - 3 - i);
            i += 2;
        }
        debug(i);
        if (i == N - 1) break;
    }
    sort(all(path));

    cout << path.size() << endl;
    rep(i, path.size()) cout << path[i] + 1 << " ";
    cout << endl;
}
