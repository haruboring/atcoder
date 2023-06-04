#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> buka(N);
    rep(i, N - 1) {
        int sv;
        cin >> sv;
        buka[sv - 1].push_back(i + 1);
    }

    vector<int> ans(N, 0);

    for (int i = N - 1; i >= 0; i--) {
        if (buka[i].size() == 0) {
            ans[i] = 1;
            continue;
        }
        int ma = 0, mi = 1e9;
        for (auto v : buka[i]) {
            ma = max(ma, ans[v]);
            mi = min(mi, ans[v]);
        }
        ans[i] = ma + mi + 1;
    }

    cout << ans[0] << endl;
}