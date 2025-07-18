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
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    if (N == 1) {
        cout << A[0][0] % M << endl;
        return 0;
    }

    rep(i, N) {
        rep(j, N) {
            int K = 2 * (N - 1) - (i + j);
            int t = A[i][j] % M;
            rep(k, K) {
                t *= 10;
                t %= M;
            }
            A[i][j] = t;
        }
    }

    // 0:→、1:↓
    vector<vector<int>> m_ou(N, vector<int>(0));
    for (int i = 0; i < (1 << (N - 1)); i++) {
        bitset<30> s(i);
        int x = 0, y = 0;
        int tmp = A[x][y];
        rep(j, N - 1) {
            if (s.test(j)) {
                x++;
            } else {
                y++;
            }
            tmp += A[x][y];
            tmp %= M;
        }

        m_ou[x].push_back(tmp);
    }

    // 0:←、1:↑
    vector<vector<int>> m_huk(N, vector<int>(0));
    for (int i = 0; i < (1 << (N - 1)); i++) {
        bitset<30> s(i);
        int x = N - 1, y = N - 1;
        int tmp = A[x][y];
        rep(j, N - 1) {
            if (s.test(j)) {
                x--;
            } else {
                y--;
            }
            if (j == N - 2) continue;
            tmp += A[x][y];
            tmp %= M;
        }

        m_huk[x].push_back(tmp);
    }

    debug(m_huk[0].size());

    int ans = -1;
    rep(i, N) sort(all(m_ou[i])), sort(all(m_huk[i]));
    rep(i, N) {
        for (int ou : m_ou[i]) {
            int idx = lower_bound(all(m_huk[i]), M - ou) - m_huk[i].begin();
            if (idx == 0) idx = m_huk[i].size();

            int tmp = ou + m_huk[i][idx - 1];
            ans = max(ans, tmp % M);
        }
    }

    cout << ans << endl;
}
