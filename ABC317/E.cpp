#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    rep(i, H) cin >> A[i];

    vector<vector<set<char>>> ME(H, vector<set<char>>(W));
    pair<int, int> S, G;
    set<char> st = {'>', '<', '^', 'v', 'S', 'G', '#'};
    rep(i, H) {
        rep(j, W) {
            char c = A[i][j];

            if (c == 'S') S = make_pair(i, j);
            if (c == 'G') G = make_pair(i, j);

            if (c == '>') {
                repp(k, j + 1, W) {
                    if (ME[i][k].count('>') || st.count(A[i][k])) break;
                    ME[i][k].insert('>');
                    A[i][k] = 'z';
                }
            }
            if (c == '<') {
                for (int k = j - 1; k >= 0; k--) {
                    if (ME[i][k].count('<') || st.count(A[i][k])) break;
                    ME[i][k].insert('<');
                    A[i][k] = 'z';
                }
            }
            if (c == '^') {
                for (int k = i - 1; k >= 0; k--) {
                    if (ME[k][j].count('^') || st.count(A[k][j])) break;
                    ME[k][j].insert('^');
                    A[k][j] = 'z';
                }
            }
            if (c == 'v') {
                repp(k, i + 1, H) {
                    if (ME[k][j].count('v') || st.count(A[k][j])) break;
                    ME[k][j].insert('v');
                    A[k][j] = 'z';
                }
            }
        }
    }

    // cout << endl;
    // rep(i, H) {
    //     rep(j, W) {
    //         cout << A[i][j];
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> dist(H, vector<int>(W, 1e9));
    queue<pair<int, int>> q;
    q.push(S);
    dist[S.first][S.second] = 0;

    vector<vector<int>> dx = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
        int v = q.front().first;
        int u = q.front().second;
        q.pop();
        for (auto d : dx) {
            int nv = v + d[0];
            int nu = u + d[1];
            if (nv < 0 || nv >= H || nu < 0 || nu >= W) continue;
            if (A[nv][nu] != '.' && A[nv][nu] != 'G') continue;
            if (dist[nv][nu] <= dist[v][u] + 1) continue;
            dist[nv][nu] = dist[v][u] + 1;
            q.push({nv, nu});
        }
    }

    if (dist[G.first][G.second] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << dist[G.first][G.second] << endl;
    }
}