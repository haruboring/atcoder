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
    vector<int> H(N);
    rep(i, N) cin >> H[i];

    vector<int> c(N, 1e18);
    c[0] = 0;
    rep(i, N - 1) {
        c[i + 1] = min(c[i + 1], c[i] + abs(H[i + 1] - H[i]));
        if (i < N - 2) c[i + 2] = min(c[i + 2], c[i] + abs(H[i + 2] - H[i]));
    }

    vector<int> path;
    int i = 0;
    while (1) {
        if (abs(H[N - 1 - i] - H[N - 2 - i]) == c[N - 1 - i] - c[N - 2 - i]) {
            path.push_back(N - 2 - i);
            i++;
        } else {
            path.push_back(N - 3 - i);
            i += 2;
        }
        if (i == N - 1) break;
    }
    path.push_back(N - 1);
    sort(all(path));

    cout << path.size() << endl;
    rep(i, path.size()) cout << path[i] + 1 << " ";
    cout << endl;
}
