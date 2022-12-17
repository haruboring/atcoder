#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int N, M;
vector<int> color(100 + 1);
vector<vector<ll>> G(100 + 1, vector<ll>(0));
map<vector<vector<int>>, vector<int>> m;

int cnt_sepa = -1;
vector<int> visist(100 + 1);
bool b = true;

void visited(int ind, int clr) {
    color[ind] = clr;
    rep(i, G[ind].size()) {
        if (color[G[ind][i]] == clr) {
            b = false;
        }
        color[G[ind][i]] = (clr + 1) % 2;
        if (color[G[ind][i]] == -1) {
            m[make_pair(cnt_sepa,(clr + 1) % 2)].push_back(G[ind][i]);
            visited(G[ind][i], (clr + 1) % 2);
        }
    }
}

int main() {
    cin >> N >> M;
    vector<int> u(M), v(M);
    rep(i, M) {
        cin >> u[i] >> v[i];
    }
    rep(i, M) {
        G[u[i] - 1].push_back(v[i] - 1);
        G[v[i] - 1].push_back(u[i] - 1);
    }
    rep(i, 100 + 1) {
        color[i] = -1;
    }
    // 1-> black -1->white
    rep(i, N) {
        if (color[i] == -1) {
            cnt_sepa++;
            visited(i, 0);
        }
    }
    ll ans = 0;
    if (b == false) {
        cout << 0 << endl;
    } else {
        rep(i, cnt_sepa + 1) {
            // 同じグラフ
            rep(j, m[i][0].size()) {
                rep(k, m[i][1].size()) {
                    bool am = true;
                    rep(l, G[m[i][0][j]].size()) {
                        if (G[m[i][0][j]][l] == m[i][1][k]) {
                            am = false;
                        }
                    }
                    if (am) {
                        ans++;
                    }
                }
            }
            cout << (int(m[i][0].size()) + int(m[i][1].size())) << endl;
            // そうでない時
            ans += N - (int(m[i][0].size()) + int(m[i][1].size()));
        }
        cout << ans << endl;
    }
}