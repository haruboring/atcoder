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
    rep(i, N) cin >> S[i];
    vector<string> T(N);
    rep(i, N) cin >> T[i];

    int cnt_S = 0, cnt_T = 0;
    rep(i, N) {
        rep(j, N) {
            if (S[i][j] == '#') cnt_S++;
            if (T[i][j] == '#') cnt_T++;
        }
    }
    if (cnt_S != cnt_T) {
        cout << "No" << endl;
        return 0;
    }

    vector<pair<int, int>> graph(0);
    rep(i, N) {
        rep(j, N) {
            if (T[i][j] == '#') {
                graph.push_back(make_pair(i, j));
            }
        }
    }
    sort(all(graph));
    int min_x = graph[0].first, min_y = graph[0].second;
    rep(i, graph.size()) {
        graph[i].first -= min_x;
        graph[i].second -= min_y;
    }

    rep(_, 4) {
        vector<pair<int, int>> com_graph(0);
        rep(i, N) {
            rep(j, N) {
                if (S[i][j] == '#') {
                    com_graph.push_back(make_pair(i, j));
                }
            }
        }
        sort(all(com_graph));
        min_x = com_graph[0].first, min_y = com_graph[0].second;
        rep(i, com_graph.size()) {
            com_graph[i].first -= min_x;
            com_graph[i].second -= min_y;
        }

        bool same = true;
        rep(i, graph.size()) {
            if (graph[i] != com_graph[i]) same = false;
        }
        if (same) {
            cout << "Yes" << endl;
            return 0;
        }

        vector<string> tmp(N);
        rep(i, N) {
            rep(j, N) {
                tmp[j].push_back(S[N - i - 1][j]);
            }
        }
        S = tmp;
    }

    cout << "No" << endl;
}
