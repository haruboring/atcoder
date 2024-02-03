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
    vector<string> S(N);
    rep(i, N) {
        cin >> S[i];
    }

    vector<vector<vector<vector<int>>>> dist(N, vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(N, 1e9))));
    queue<tuple<int, int, int, int>> q;
    rep(i, N) {
        rep(j, N) {
            rep(k, N) {
                rep(l, N) {
                    if (i == k && j == l) continue;
                    if (S[i][j] == 'P' && S[k][l] == 'P') {
                        dist[i][j][k][l] = 0;
                        q.push({i, j, k, l});
                    }
                }
            }
        }
    }
    vector<int> di = {0, 1, 0, -1}, dj = {1, 0, -1, 0};
    q.pop();
    debug(q.size());
    while (!q.empty()) {
        auto [i, j, k, l] = q.front();
        if (i == k && j == l) {
            cout << dist[i][j][k][l] << endl;
            return 0;
        }
        q.pop();
        rep(n, 4) {
            int ni = i + di[n], nj = j + dj[n];
            bool is_move_1 = true;
            if (ni < 0 || ni >= N || nj < 0 || nj >= N) {
                is_move_1 = false;
            }
            if (is_move_1 && S[ni][nj] == '#') {
                is_move_1 = false;
            }
            int nk = k + di[n], nl = l + dj[n];
            bool is_move_2 = true;
            if (nk < 0 || nk >= N || nl < 0 || nl >= N) {
                is_move_2 = false;
            }
            if (is_move_2 && S[nk][nl] == '#') {
                is_move_2 = false;
            }

            if (!is_move_1) {
                ni = i;
                nj = j;
            }
            if (!is_move_2) {
                nk = k;
                nl = l;
            }

            if (!is_move_1 && !is_move_2) continue;
            if (dist[ni][nj][nk][nl] > dist[i][j][k][l] + 1) {
                dist[ni][nj][nk][nl] = dist[i][j][k][l] + 1;
                q.push({ni, nj, nk, nl});
            }
        }
    }

    cout << -1 << endl;
}