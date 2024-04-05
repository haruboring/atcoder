#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int a, N;
    cin >> a >> N;

    vector<int> dp(10 * N + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});

    while (!q.empty()) {
        auto [cnt, x] = q.top();
        q.pop();
        if (dp[x] != 1e9) continue;
        string sx = to_string(x);

        dp[x] = cnt;

        if (x * a <= 10 * N) q.push({cnt + 1, x * a});
        if (x >= 10 && x % 10 != 0) {
            string nsx = sx[sx.size() - 1] + sx.substr(0, sx.size() - 1);
            if (stoll(nsx) <= 10 * N) q.push({cnt + 1, stoll(nsx)});
        }
    }

    cout << (dp[N] == 1e9 ? -1 : dp[N]) << endl;
}
