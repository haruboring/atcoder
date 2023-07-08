#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];
    int Q;
    cin >> Q;
    vector<int> S(Q), T(Q);
    rep(i, Q) cin >> S[i] >> T[i];

    vector<vector<int>> G(N, vector<int>(0));
    rep(i, N) {
        rep(j, N) {
            if (A[i][j] == 1) {
                G[i].push_back(j);
            }
        }
    }
    vector<vector<int>> expandG(2 * N, vector<int>(0));
    rep(i, N) {
        rep(j, N) {
            if (A[i][j] == 1) {
                expandG[i].push_back(j);
                expandG[i].push_back(j + N);
                expandG[i + N].push_back(j);
                expandG[i + N].push_back(j + N);
            }
        }
    }

    vector<int> same_dist(N);
    rep(i, N) {
        queue<int> q;
        vector<int> dist(2 * N, -1);
        q.push(i);
        dist[i] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int nv : expandG[v]) {
                if (dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }
        same_dist[i] = dist[i + N];
    }

    rep(i, Q) {
        int s = S[i] - 1, t = T[i] - 1;
        queue<int> q;
        vector<int> dist_s_t(N, -1);
        q.push(s % N);
        dist_s_t[s % N] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int nv : G[v]) {
                if (dist_s_t[nv] != -1) continue;
                dist_s_t[nv] = dist_s_t[v] + 1;
                q.push(nv);
            }
        }

        vector<int> dist_t_s(N, -1);
        q.push(t % N);
        dist_t_s[t % N] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int nv : G[v]) {
                if (dist_t_s[nv] != -1) continue;
                dist_t_s[nv] = dist_t_s[v] + 1;
                q.push(nv);
            }
        }
        int base = (abs(s / N - t / N)) * same_dist[s % N];
        if (base < 0) base = 0;
        int ans = base + dist_s_t[t % N];
        base = (abs(s / N - t / N) - 1) * same_dist[s % N];
        if(dist_t_s[s % N] != -1) ans = min(ans, base + dist_t_s[s % N]);
        cout << min(base + dist_s_t[t % N], abs(base - dist_t_s[s % N])) << endl;
    }
}