#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

ll MOD = 1'000'000'007;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> G(N + 1, vector<ll>(0));
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    repp(i, 1, N + 1) {
        if (int(G[i].size()) >= int(K)) {
            cout << 0 << endl;
            return 0;
        }
    }

    vector<ll> connect(N + 1, -1);
    queue<ll> q;
    connect[1] = 0;
    q.push(1);
    while (q.size()) {
        int top = q.front();
        q.pop();
        int i = 1;
        for (auto next_top : G[top]) {
            if (connect[next_top] == -1) {
                connect[next_top] = 1 + i;
                if (top == 1) {
                    connect[next_top]--;
                }
                q.push(next_top);
                i++;
            }
        }
    }
    ll ans = 1;
    repp(i, 1, N + 1) {
        ans *= K - connect[i];
        ans %= MOD;
    }
    cout << ans << endl;
}