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
    vector<int> V(N);
    rep(i, N) cin >> V[i];

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j + i <= N; j++) {
            if (i + j > K) continue;
            int sum = 0;
            vector<int> tmp;
            for (int k = 0; k < i; k++) {
                tmp.push_back(V[k]);
            }
            for (int k = 0; k < j; k++) {
                tmp.push_back(V[N - 1 - k]);
            }
            sort(all(tmp));
            rep(k, tmp.size()) {
                sum += tmp[k];
            }
            rep(k, min(i + j, K - (i + j))) {
                if (tmp[k] < 0) sum -= tmp[k];
            }

            ans = max(ans, sum);
        }
    }

    cout << ans << endl;
}
